import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
from goat_interfaces.msg import GoalPose
from std_msgs.msg import String
import tf_transformations

class GoToPoseServer(Node):
    def __init__(self):
        super().__init__('go_to_pose_server')
        self.navigator = BasicNavigator()
        self.navigator.waitUntilNav2Active()
        self.set_initial_pose()
        self.curent_goal = []

        self.task_timer = None
        self.pending_response = None
        self.stuck_count = 0

        self.subscription = self.create_subscription(
            GoalPose,
            'goal',
            self.pose_callback,
            10
        )

        self.goal_status = self.create_publisher(String, "goal_state", 10)

        self.flag_go_to_pose = False  # your flag

        # Timer to periodically check the flag and call the method
        self.timer = self.create_timer(0.5, self.check_and_go_to_pose)

    def publish_goal_status(self,state):
            msg = String()
            msg.data = state
            self.goal_status.publish(msg)

    def check_and_go_to_pose(self):
        if self.flag_go_to_pose:
            self.get_logger().info("🚦 Flag is True: Calling go_to_pose_callback()")
            self.flag_go_to_pose = False  # reset flag to avoid repeat triggering
            self.go_to_pose_callback()

    def pose_callback(self, msg):
        x = msg.x
        y = msg.y
        yaw = msg.theta
        # self.curent_pose = [x,y,yaw]
        self.curent_goal = [x,y,yaw]
        self.flag_go_to_pose = True
        self.get_logger().info(f'Current goal: x={x:.2f}, y={y:.2f}, yaw={yaw:.2f} rad')

    def set_initial_pose(self):
        pub = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        x, y, yaw = -3.221095085144043, -4.4982757568359375, 1.9229348
        q = tf_transformations.quaternion_from_euler(0, 0, yaw)

        msg = PoseWithCovarianceStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'
        msg.pose.pose.position.x = x
        msg.pose.pose.position.y = y
        msg.pose.pose.orientation.x = q[0]
        msg.pose.pose.orientation.y = q[1]
        msg.pose.pose.orientation.z = q[2]
        msg.pose.pose.orientation.w = q[3]
        msg.pose.covariance = [
            0.25, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.25, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0685
        ]

        for _ in range(10):
            pub.publish(msg)
            rclpy.spin_once(self, timeout_sec=0.1)
        self.get_logger().info("📌 📌 Initial pose set.")

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

    def go_to_pose_callback(self):
        self.get_logger().info(f"📨 Received Goal: x={self.curent_goal[0]}, y={self.curent_goal[1]}, theta={self.curent_goal[2]}")
        goal_pose = self.create_pose_stamped(self.curent_goal[0], self.curent_goal[1], self.curent_goal[2])
        self.navigator.goToPose(goal_pose)

        count = 0
        while not self.navigator.isTaskComplete():
            feedback = self.navigator.getFeedback()
            if feedback:
                distance = feedback.distance_remaining
                self.get_logger().info(f"📍 Distance remaining: {distance:.2f} m")
                if 0.03 < distance < 0.1:
                    count += 1
                    self.get_logger().info(f"⚠️ Close to goal for {count} cycles")
                    if count > 20:
                        self.get_logger().warn("🕳️ Stuck near goal, breaking early")
                        self.navigator.cancelTask()  # 🛑 Ensure current task is properly cancelled
                        rclpy.spin_once(self, timeout_sec=0.1)  # 🕐 Give time for cleanup
                        break
            rclpy.spin_once(self, timeout_sec=0.1)

        result = self.navigator.getResult()
        if result:
            self.get_logger().info("✅ Goal reached or task completed")
            self.publish_goal_status("✅ Goal reached or task completed")
        else:
            self.get_logger().error("❌ Task result unavailable")
            self.publish_goal_status("❌ Task result unavailable")


def main(args=None):
    rclpy.init(args=args)
    node = GoToPoseServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
