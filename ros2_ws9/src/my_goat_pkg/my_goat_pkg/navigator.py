import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
from goat_interfaces.srv import GoToPose  # Replace with your actual package
import tf_transformations


class GoToPoseServer(Node):
    def __init__(self):
        super().__init__('go_to_pose_server')

        # Initialize the navigator and wait for Nav2 stack to activate
        self.navigator = BasicNavigator()
        self.navigator.waitUntilNav2Active()

        # Set robot's initial pose
        self.set_initial_pose()

        self.get_logger().info("🚀 GoToPose service ready.")

    def set_initial_pose(self):
        pub = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)

        # Set the desired initial pose (x, y, yaw in radians)
        x, y, yaw = -3.2211, -4.4983, 1.9229
        q = tf_transformations.quaternion_from_euler(0, 0, yaw)

        msg = PoseWithCovarianceStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'

        # Set position
        msg.pose.pose.position.x = x
        msg.pose.pose.position.y = y

        # Set orientation
        msg.pose.pose.orientation.x = q[0]
        msg.pose.pose.orientation.y = q[1]
        msg.pose.pose.orientation.z = q[2]
        msg.pose.pose.orientation.w = q[3]

        # Set covariance
        msg.pose.covariance = [
            0.25, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.25, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0685
        ]

        # Publish the initial pose multiple times
        for _ in range(10):
            pub.publish(msg)
            rclpy.spin_once(self, timeout_sec=0.1)

        self.get_logger().info("📌 Initial pose set.")


def main(args=None):
    rclpy.init(args=args)
    node = GoToPoseServer()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("💤 Shutting down GoToPoseServer...")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
