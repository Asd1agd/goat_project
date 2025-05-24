
import time
import threading
import math
import rclpy
from rclpy.node import Node
from goat_interfaces.srv import GoToPose
from geometry_msgs.msg import PoseStamped,PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import tf_transformations
import tkinter as tk
from tkinter import messagebox
from datetime import datetime


# # Initial table_dict
# table_dict = {
#     "table1": [[["t1", [12, 30, 11], 1]], [["t1", [12, 30, 11], 1]]],
#     "table2": [[["t2", [12, 30, 11], 2]], [["t2", [12, 30, 11], 2]]],
#     "table3": [[["t3", [12, 30, 11], 3]], [["t3", [12, 30, 11], 3]]]
# }

table_dict = {
    "table1": [[], []],
    "table2": [[], []],
    "table3": [[], []]
}

# Track canceled orders
order_canceled = []

# GLOBAL order ID, initialized based on max ID in initial orders
global_order_id = 0

# Store GUI container references
table_gui_refs = {}  # {"table1": Frame, ...}


def cancel_order(order, button):
    order_id = order[2]
    
    if order_id not in order_canceled:
        order_canceled.append(order_id)
        button.config(state="disabled")
        messagebox.showinfo("Order Canceled", f"Order ID {order_id} has been canceled.")
    else:
        messagebox.showwarning("Already Canceled", f"Order ID {order_id} was already canceled.")

    print(f"order_canceled: {order_canceled}")

     # Refresh GUI
    refresh_gui()


def add_order(table_name, container_frame):
    global global_order_id
    now = datetime.now()
    global_order_id += 1

    table_code = "t" + table_name[-1]
    order = [table_code, [now.hour, now.minute, now.second], global_order_id]

    # Add to both front-end and back-end lists
    table_dict[table_name][0].append(order)
    table_dict[table_name][1].append(order)

    # GUI display for new order
    show_order_block(container_frame, order)
    print(table_dict)

     # Refresh GUI
    refresh_gui()


def show_order_block(container, order):
    order_frame = tk.Frame(container, relief=tk.RIDGE, borderwidth=2, padx=5, pady=5)
    order_frame.pack(pady=10, fill="x")

    order_text = f"Table: {order[0]}\nTime: {order[1][0]:02d}:{order[1][1]:02d}:{order[1][2]:02d}\nOrder ID: {order[2]}"
    label = tk.Label(order_frame, text=order_text, justify="left")
    label.pack()

    cancel_button = tk.Button(order_frame, text="Cancel Order")
    cancel_button.pack(pady=5)
    cancel_button.config(command=lambda o=order, b=cancel_button: cancel_order(o, b))


def refresh_gui():
    """Rebuilds the GUI content based on current table_dict."""
    for table_name, (visible_orders, _) in table_dict.items():
        container = table_gui_refs.get(table_name)
        if container:
            # Clear existing widgets
            for widget in container.winfo_children():
                widget.destroy()
            # Rebuild current orders
            for order in visible_orders:
                show_order_block(container, order)


def create_gui():
    root = tk.Tk()
    root.title("Order Manager")
    root.geometry("1200x600")

    for col_index, (table_name, (visible_orders, _)) in enumerate(table_dict.items()):
        table_frame = tk.LabelFrame(root, text=table_name.upper(), padx=10, pady=10)
        table_frame.grid(row=0, column=col_index, padx=20, pady=20, sticky="n")

        orders_container = tk.Frame(table_frame)
        orders_container.pack()

        table_gui_refs[table_name] = orders_container  # Save reference

        # Show initial visible orders
        for order in visible_orders:
            show_order_block(orders_container, order)

        # Add Order Button
        add_button = tk.Button(
            table_frame,
            text="Add Order",
            command=lambda tn=table_name, f=orders_container: add_order(tn, f)
        )
        add_button.pack(pady=10)

    root.mainloop()
    # print("Canceled orders:", order_canceled)
    # print("Final table_dict:", table_dict)

table_list = ["table1","table2","table3"]
table_list2 = ["t1","t2","t3"]
# order_canceled = []
table_cords = [[-5.5, -1.0, 0.0],[-3.4, 0.0, 0.0],[-0.5, 1.0, 0.0]]
kitchen_cords = [-3.8, -8.0, 0.0]
home_cords = [-3.22, -4.5, 0.0]
curent_pose = [0,0,0]


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
        self.navigator = BasicNavigator()
        self.navigator.waitUntilNav2Active()
        # self.set_initial_pose()

        self.get_logger().info("🚀 GoToPose service ready.")
        
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
        # self.get_logger().info(f'Current pose: x={x:.2f}, y={y:.2f}, yaw={yaw:.2f} rad')

    def create_pose_stamped(self, x, y, yaw):
        q = tf_transformations.quaternion_from_euler(0.0, 0.0, yaw)
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.orientation.x = q[0]
        pose.pose.orientation.y = q[1]
        pose.pose.orientation.z = q[2]
        pose.pose.orientation.w = q[3]
        return pose
    
    def go_to_pose_callback(self, x,y,theta):
        self.get_logger().info(f"📨 Received Goal: x={x}, y={y}, theta={theta}")
        goal_pose = self.create_pose_stamped(x, y,theta)
        self.navigator.goToPose(goal_pose)

        count = 0
        while not self.navigator.isTaskComplete():
            feedback = self.navigator.getFeedback()
            if feedback:
                distance = feedback.distance_remaining
                # self.get_logger().info(f"📍 Distance remaining: {distance:.2f} m")
                if 0.03 < distance < 0.1:
                    count += 1
                    # self.get_logger().info(f"⚠️ Close to goal for {count} cycles")
                    if count > 20:
                        self.get_logger().warn("🕳️ Stuck near goal, breaking early")
                        self.navigator.cancelTask()  # 🛑 Ensure current task is properly cancelled
                        rclpy.spin_once(self, timeout_sec=0.1)  # 🕐 Give time for cleanup
                        break
            rclpy.spin_once(self, timeout_sec=0.1)

        result = self.navigator.getResult()
        if result:
            self.navigator.cancelTask()  # ✅ Ensure no hanging tasks
            rclpy.spin_once(self, timeout_sec=0.1)
            self.get_logger().info("✅ Goal reached or assumed reached.")
        else:
            self.navigator.cancelTask()  # ✅ Ensure no hanging tasks
            rclpy.spin_once(self, timeout_sec=0.1)
            self.get_logger().warn("❌ Failed to reach goal.")

    

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
        # print(f"k dist = {math.dist(bot_cords,kitchen_cords2)}")
        if math.dist(bot_cords,kitchen_cords2) > 2:
            pTime = ctime()
        kitchen_timer_val = ctime() - pTime
        # print(f"kitchen_timer_val = {kitchen_timer_val}")

def cancel_order_dict():
    global order_canceled,table_list,table_dict,kitchen,wetter_robot
    while True:
        with lock:
            if len(order_canceled) > 0:  # in seperate threde
                # print("order_canceled list")
                # print(order_canceled)
                id_no = order_canceled.pop(0)
                for table in table_list:
                    # print(table)
                    # print("              ")
                    # print("complete data")
                    # print(table_dict)
                    # print("              ")
                    # print("table_dict[table][0]")
                    # print(table_dict[table][0])
                    for order in table_dict[table][1]:
                        # print(order)
                        # print(f"idno{id_no}   :   order:{order}")
                        if id_no == order[-1]:
                            # print("table_dict 1")
                            # print(table_dict[table][1])
                            table_dict[table][1].remove(order)
                            # print("order to remove t1")
                            # print(order)
                            # print("table_dict 1 updated")
                            # print(table_dict[table][1])
                    for order in table_dict[table][0]:
                        if id_no == order[-1]:
                            # print("table_dict 0")
                            # print(table_dict[table][0])
                            table_dict[table][0].remove(order)
                            # print("order to remove t0")
                            # print(order)
                            # print("table_dict 0 updated")
                            # print(table_dict[table][0])
                for order in kitchen:
                    if id_no == order[-1]:
                        kitchen.remove(order)
                for order in wetter_robot:
                    if id_no == order[-1]:
                        wetter_robot.remove(order)
                refresh_gui()
        time.sleep(1)


def move_to(client,cords):
    # send cords to navigater node i.e kitchen_cords = [3.8, -8.0, 0.0]
    # wait for the navigation complete responce frome navigator node
    # client.get_logger().info(f"sending pose message='{cords}'")
    client.go_to_pose_callback(cords[0], cords[1], cords[2])
    # client.get_logger().info(f"Result: success={result.success}, message='{result.message}'")


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
                # print("1                   ")
                # print(kitchen)
                # print("1                   ")
                del table_dict[table][1][-1]

        for table in table_list:
            if len(table_dict[table][1]) > 0:
                if abs(table_dict[table][1][-1][-1] - kitchen[-1][-1]) == 1:    
                    kitchen.append(table_dict[table][1][-1])
                    # print("2                   ")
                    # print(kitchen)
                    # print("2                   ")
                    del table_dict[table][1][-1]

     

def main(args=None):
    time.sleep(10)
    rclpy.init(args=args)
    client = GoToPoseClient()
    t1 = threading.Thread(target=timer_stedy)
    t1.start()
    t2 = threading.Thread(target=kitchen_timer)
    t2.start()
    t3 = threading.Thread(target=cancel_order_dict)
    t3.start()
    t4 = threading.Thread(target=get_orders)
    t4.start()
    t5 = threading.Thread(target=create_gui)
    t5.start()
    # client.get_logger().info(f"wetter_robot:{wetter_robot}")
    # client.get_logger().info(f"kitchen:{kitchen}")
    # client.get_logger().info(f"table_dict:{table_dict}")


    while len(wetter_robot) == 0:
        time.sleep(0.1)
        if len(kitchen) > 0:
            move_to(client,kitchen_cords)
            # Pause before sending the next goal
            time.sleep(2)
            # client.get_logger().info(f"reached in kitchen")
            capacity_overflow = 0
            while capacity_overflow == 0 and kitchen_timer_value() < order_wait:
                # client.get_logger().info(f"in while capacity_overflow and kitchen_timer_value")
                for order in kitchen:
                    order_time = order[1][0]*60*60 + order[1][1]*60 + order[1][1]
                    if (ctime() - order_time) > cooking_time and len(wetter_robot) <= wetter_capacity:
                        wetter_robot.append(order)
                        kitchen.remove(order)
                    if len(wetter_robot) > wetter_capacity:
                        capacity_overflow = 1
        if kitchen_timer_value() > order_wait and len(wetter_robot)==0:
            move_to(client,home_cords)
            # Pause before sending the next goal
            time.sleep(2)
        while len(wetter_robot) > 0:
            # print(wetter_robot)
            # client.get_logger().info("here")
            table_no = table_list2.index(wetter_robot[0][0])
            # print(table_no)
            # client.get_logger().info("here")
            # client.get_logger().info(str(wetter_robot))
            # client.get_logger().info(str(table_no))
            move_to(client,table_cords[table_no])
            # Pause before sending the next goal
            time.sleep(2)
            for order in wetter_robot:
                for table_order in table_dict[list(table_dict.keys())[table_no]][0]:
                    if table_order[-1] == order[-1]:    # order id is same
                        wetter_robot.remove(order)
                        table_dict[list(table_dict.keys())[table_no]][0].remove(table_order)
                        refresh_gui()

        if timer_stedy_value() > stedy_state and len(wetter_robot)==0:
            move_to(client,home_cords)
            # Pause before sending the next goal
            time.sleep(2)
        client.get_logger().info(f"==========================start============================")
        client.get_logger().info(f"wetter_robot:{wetter_robot}")
        client.get_logger().info(f"kitchen:{kitchen}")
        client.get_logger().info(f"table_dict:{table_dict}")
        client.get_logger().info(f"============================end==========================")


    # client.get_logger().info(f"out of while")
    rclpy.spin(client)
    t1.join()
    t2.join()
    t3.join()
    t4.join()
    rclpy.shutdown()

if __name__ == '__main__':
    time.sleep(10)
    main()


