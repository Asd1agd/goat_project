import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
from goat_interfaces.srv import GoToPose  # Replace with your package
import tf_transformations

class GoToPoseServer(Node):
    def __init__(self):
        super().__init__('go_to_pose_server')
        self.navigator = BasicNavigator()
        self.navigator.waitUntilNav2Active()
        self.set_initial_pose()

        self.get_logger().info("🚀 GoToPose service ready.")

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
        self.get_logger().info("📌 Initial pose set.")

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



def main(args=None):
    rclpy.init(args=args)
    node = GoToPoseServer()
    rclpy.spin(node)
    rclpy.shutdown()
    # try:
    #     rclpy.spin(node)
    # except KeyboardInterrupt:
    #     pass
    # finally:
    #     node.destroy_node()
    #     rclpy.shutdown()

if __name__ == '__main__':
    main()
