#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav2_simple_commander.robot_navigator import BasicNavigator
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
import tf_transformations

def create_pose_stamped(navigator, position_x, position_y, rotation_z):
    q_x, q_y, q_z, q_w = tf_transformations.quaternion_from_euler(0.0, 0.0, rotation_z)
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose.pose.position.x = position_x
    goal_pose.pose.position.y = position_y
    goal_pose.pose.position.z = 0.0
    goal_pose.pose.orientation.x = q_x
    goal_pose.pose.orientation.y = q_y
    goal_pose.pose.orientation.z = q_z
    goal_pose.pose.orientation.w = q_w
    return goal_pose

def publish_initialpose(node, x, y, yaw):
    pub = node.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
    q_x, q_y, q_z, q_w = tf_transformations.quaternion_from_euler(0, 0, yaw)

    msg = PoseWithCovarianceStamped()
    msg.header.stamp = node.get_clock().now().to_msg()
    msg.header.frame_id = 'map'
    msg.pose.pose.position.x = x
    msg.pose.pose.position.y = y
    msg.pose.pose.position.z = 0.0
    msg.pose.pose.orientation.x = q_x
    msg.pose.pose.orientation.y = q_y
    msg.pose.pose.orientation.z = q_z
    msg.pose.pose.orientation.w = q_w

    # Covariance matrix: small covariance means confident in initial pose
    msg.pose.covariance = [
    0.25, 0.0,  0.0,  0.0,  0.0,  0.0,
    0.0,  0.25, 0.0,  0.0,  0.0,  0.0,
    0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
    0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
    0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
    0.0,  0.0,  0.0,  0.0,  0.0,  0.06853891909122467
]


    # Publish multiple times to ensure AMCL receives it
    for _ in range(10):
        pub.publish(msg)
        rclpy.spin_once(node, timeout_sec=0.1)

def main():
    rclpy.init()
    nav = BasicNavigator()

    # # Publish initial pose to /initialpose for AMCL localization
    # publish_initialpose(nav, -10.0, -10.0, 0.0)

    # # Also set initial pose in Nav2 stack
    # initial_pose = create_pose_stamped(nav, -3.221095085144043, -4.4982757568359375, 1.9229348)
    # nav.setInitialPose(initial_pose)

    nav.waitUntilNav2Active()

    # List of all goal poses
    goals = [
        create_pose_stamped(nav, -5.5, -1.0, 0.0),   # t1
        create_pose_stamped(nav, -3.4, 0.0, 0.0),    # t2
        create_pose_stamped(nav, -0.5, 1.0, 0.0),    # t3
        create_pose_stamped(nav, -3.8, -8.0, 0.0),    # kit
        create_pose_stamped(nav, -3.221095085144043, -4.4982757568359375, 1.9229348),  # home,
        create_pose_stamped(nav, -5.5, -1.0, 0.0),   # t1
        create_pose_stamped(nav, -3.4, 0.0, 0.0),    # t2
        create_pose_stamped(nav, -0.5, 1.0, 0.0),    # t3
        create_pose_stamped(nav, -3.8, -8.0, 0.0),    # kit
        create_pose_stamped(nav, -3.221095085144043, -4.4982757568359375, 1.9229348)  # home
    ]

    for i, goal in enumerate(goals, start=1):
        print(f"\n🚀 Navigating to Goal {i} ...")
        nav.goToPose(goal)
        count = 0

        while not nav.isTaskComplete():
            feedback = nav.getFeedback()
            if feedback:
                distance_remaining_ = feedback.distance_remaining
                print(f"📍 Feedback for Goal {i}: Distance remaining = {distance_remaining_:.2f} m")
                if distance_remaining_ > 0.03 and distance_remaining_ < 0.1:
                    distance_remaining_ = 10
                    count += 1
                if count > 20:
                    break
            rclpy.spin_once(nav, timeout_sec=0.01)

        result = nav.getResult()
        print(f"✅ Goal {i} completed with result: {result}")

    print("🎯 All goals completed.")
    rclpy.shutdown()


if __name__ == '__main__':
    main()


# t1 = -7.8,-1.2,0.0
# t2 = -3.4,0.0,0.0
# t3 = -0.5,1.0,0.0

# kit = 3.6,-7.6,0.0
# home = -3.221095085144043, -4.4982757568359375, 1.9229348