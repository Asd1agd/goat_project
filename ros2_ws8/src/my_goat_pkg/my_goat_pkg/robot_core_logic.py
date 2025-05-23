import time
import threading
import math
import rclpy
from rclpy.node import Node
from goat_interfaces.msg import GoalPose
from std_msgs.msg import String
from geometry_msgs.msg import PoseWithCovarianceStamped


table_list = ["table1","table2","table3"]
order_canceled = [4,1]
table_cords = [[-5.5, -1.0, 0.0],[-3.4, 0.0, 0.0],[-0.5, 1.0, 0.0]]
kitchen_cords = [-3.8, -8.0, 0.0]
home_cords = [-3.22, -4.5, 0.0]
curent_pose = [0,0,0]

table_dict = {"table1":[[["t1",[12,30,11],1]],[["t1",[12,30,11],1]]],"table2":[[["t2",[12,30,11],2]],[["t2",[12,30,11],2]]],"table3":[[["t3",[12,30,11],3]],[["t3",[12,30,11],3]]]}

cooking_time = 10 # sec
order_wait = 30 # sec
stedy_state = 2*60

kitchen = []
wetter_robot = []
tables = 3
order_id = 0
wetter_capacity = 5 # orders at a time

timer_stedy_val = 0
kitchen_timer_val = 0
lock = threading.Lock()

class GoToPoseClient(Node):
    def __init__(self):
        super().__init__('go_to_pose_client')
        # self.curent_pose = [0,0,0]
        self.goal_stat = "none"

        self.state_sub = self.create_subscription(
            String,
            "goal_state",
            self.state_callback,
            10
        )
        self.goal_cords = self.create_publisher(GoalPose, "goal", 10)

        self.subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            '/amcl_pose',
            self.pose_callback,
            10
        )
        self.pose = None

    def pose_callback(self, msg):
        global curent_pose
        self.pose = msg.pose.pose
        x = self.pose.position.x
        y = self.pose.position.y
        yaw = 0 # self.get_yaw_from_quaternion(self.pose.orientation)
        # self.curent_pose = [x,y,yaw]
        curent_pose = [x,y,yaw]
        self.get_logger().info(f'Current pose: x={x:.2f}, y={y:.2f}, yaw={yaw:.2f} rad')


    def state_callback(self, msg):
        goal_status = msg.data
        if goal_status == "✅ Goal reached or task completed":
            self.goal_stat = "success"
        if goal_status == "❌ Task result unavailable":
            self.goal_stat = "fail"
        self.get_logger().info(goal_status)

    
    def publish_goal_cords(self,x,y,theta):
        msg = GoalPose()
        msg.x = x
        msg.y = y
        msg.theta = theta
        self.goal_cords.publish(msg)
    

def ctime():
    current_time = time.time()
    local_time = time.localtime(current_time)

    hr = local_time.tm_hour
    min = local_time.tm_min
    sec = local_time.tm_sec

    C_time = hr*60*60 + min*60 + sec
    # print(f"cTime : {C_time}")

    return C_time



def timer_stedy():
    global timer_stedy_val
    p_time = ctime()
    while True:
        time.sleep(0.2)
        bot_px = curent_pose[0]
        bot_py = curent_pose[1]
        time.sleep(1)
        bot_cx = curent_pose[0]
        bot_cy = curent_pose[1]
        if abs(math.dist((bot_px,bot_py),(bot_cx,bot_cy))) > 0.2:  # asumed meter
            p_time = ctime()

        with lock:
            timer_stedy_val = ctime() - p_time

def kitchen_timer():
    kitchen_cords2 = [-3.8, -8.0]
    pTime = ctime()
    global kitchen_timer_val
    while True:
        time.sleep(0.5)
        bot_px = curent_pose[0]
        bot_py = curent_pose[1]
        bot_cords = [bot_px,bot_py]
        print(f"k dist = {math.dist(bot_cords,kitchen_cords2)}")
        if math.dist(bot_cords,kitchen_cords2) > 5:
            pTime = ctime()
        kitchen_timer_val = ctime() - pTime
        print(f"kitchen_timer_val = {kitchen_timer_val}")

def cancel_order():
    global order_canceled,table_list,table_dict,kitchen,wetter_robot
    while True:
        with lock:
            if len(order_canceled) > 0:  # in seperate threde
                id_no = order_canceled[0]
                for table in table_list:
                    for order in table_dict[table][1]:
                        if id_no == order[-1]:
                            table_dict[table][1].remove(order)
                    for order in table_dict[table][0]:
                        if id_no == order[-1]:
                            table_dict[table][0].remove(order)
                for order in kitchen:
                    if id_no == order[-1]:
                        kitchen.remove(order)
                for order in wetter_robot:
                    if id_no == order[-1]:
                        wetter_robot.remove(order)
        time.sleep(1)


def move_to(client,cords):
    # send cords to navigater node i.e kitchen_cords = [3.8, -8.0, 0.0]
    # wait for the navigation complete responce frome navigator node
    client.get_logger().info(f"sending pose message='{cords}'")
    client.publish_goal_cords(cords[0], cords[1], cords[2])
    state = client.goal_stat
    while state != "success":
        state = client.goal_stat
        time.sleep(0.5)
    if state == "success":
        client.get_logger().info(f"Result: success")
    client.goal_stat = "none"


def timer_stedy_value():
    with lock:
        timer_stedy_val2 = timer_stedy_val 
    return timer_stedy_val2

def kitchen_timer_value():
    with lock:
        kitchen_timer_val2 = kitchen_timer_val 
    return kitchen_timer_val2
        

def get_orders():
    while True:
        time.sleep(0.1)
        for table in table_list:
            if len(table_dict[table][1]) > 0:
                kitchen.append(table_dict[table][1][-1])
                del table_dict[table][1][-1]

        for table in table_list:
            if len(table_dict[table][1]) > 0:
                if abs(table_dict[table][1][-1][-1] - kitchen[-1][-1]) == 1:    
                    kitchen.append(table_dict[table][1][-1])
                    del table_dict[table][1][-1]

     

def main(args=None):
    rclpy.init(args=args)
    client = GoToPoseClient()
    t1 = threading.Thread(target=timer_stedy)
    t1.start()
    t2 = threading.Thread(target=kitchen_timer)
    t2.start()
    t3 = threading.Thread(target=cancel_order)
    t3.start()
    t4 = threading.Thread(target=get_orders)
    t4.start()
    client.get_logger().info(f"wetter_robot:{wetter_robot}")
    client.get_logger().info(f"kitchen:{kitchen}")
    client.get_logger().info(f"table_dict:{table_dict}")


    # while len(wetter_robot) == 0:
    #     time.sleep(0.1)
    #     if len(kitchen) > 0:
    #         move_to(client,kitchen_cords)
    #         # Pause before sending the next goal
    #         time.sleep(2)
    #         client.get_logger().info(f"reached in kitchen")
    #         capacity_overflow = 0
    #         while capacity_overflow == 0 and kitchen_timer_value() < order_wait:
    #             client.get_logger().info(f"in while capacity_overflow and kitchen_timer_value")
    #             for order in kitchen:
    #                 order_time = order[1][0]*60*60 + order[1][1]*60 + order[1][1]
    #                 if (order_time - ctime()) > cooking_time and len(wetter_robot) <= wetter_capacity:
    #                     wetter_robot.append(order)
    #                     kitchen.remove(order)
    #                 if len(wetter_robot) > wetter_capacity:
    #                     capacity_overflow = 1
    #     if kitchen_timer_value() > order_wait and len(wetter_robot)==0:
    #         move_to(client,home_cords)
    #         # Pause before sending the next goal
    #         time.sleep(2)
    #     while len(wetter_robot) > 0:
    #         table_no = table_list.index(wetter_robot[0][0])
    #         move_to(client,table_cords[table_no])
    #         # Pause before sending the next goal
    #         time.sleep(2)
    #         for order in wetter_robot:
    #             for table_order in table_dict[list(table_dict.keys())[table_no]][0]:
    #                 if table_order[-1] == order[-1]:    # order id is same
    #                     wetter_robot.remove(order)
    #                     table_dict[list(table_dict.keys())[table_no]][0].remove(table_order)

    #     if timer_stedy_value() > stedy_state and len(wetter_robot)==0:
    #         move_to(client,home_cords)
    #         # Pause before sending the next goal
    #         time.sleep(2)
    #     client.get_logger().info(f"wetter_robot:{wetter_robot}")
    #     client.get_logger().info(f"kitchen:{kitchen}")
    #     client.get_logger().info(f"table_dict:{table_dict}")


    client.get_logger().info(f"out of while")
    rclpy.spin(client)
    t1.join()
    t2.join()
    t3.join()
    t4.join()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
