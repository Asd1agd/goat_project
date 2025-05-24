#!/usr/bin/python3
import os
import launch, launch_ros
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_prefix
from launch_ros.actions import Node

def generate_launch_description():

  pkg_testbed_gazebo = get_package_share_directory('testbed_gazebo_goat') 
  pkg_goat_gazebo = get_package_share_directory('goat_gazebo')
  pkg_testbed_description = get_package_share_directory('testbed_description_goat')
  pkg_turtlebot3_nav = get_package_share_directory('turtlebot3_navigation2')

  # Paths to resources
  map_yaml_file = os.path.join(pkg_goat_gazebo, 'maps', 'goat_hotel.yaml')
  params_path = os.path.join(pkg_turtlebot3_nav, 'param', 'waffle.yaml')

  nav2_path = os.path.join(pkg_turtlebot3_nav, 'launch', 'navigation2.launch.py')

  gazebo = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(
      os.path.join(pkg_testbed_gazebo, 'launch', 'spawn_playground.launch.py'),
    )
  ) 
  
  state_pub = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(
      os.path.join(pkg_testbed_description, 'launch', 'robot_description.launch.py'),
    )
  )

  spawn = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(
      os.path.join(pkg_testbed_gazebo, 'launch', 'spawn_testbed.launch.py'),
    )
  )
  
  rviz_config_dir = os.path.join(
    launch_ros.substitutions.FindPackageShare(package='testbed_description_goat').find('testbed_description_goat'),
    'rviz/full_bringup.rviz')
  
  
  
  rviz_node = Node(
    package='rviz2',
    executable='rviz2',
    name='rviz_node',
    parameters=[{'use_sim_time': True}],
    arguments=['-d', LaunchConfiguration('rvizconfig')]
  )

  navigator_server_node = Node(
    package='my_goat_pkg',
    executable='navigator_server',
    name='navigator_server',
    output='screen',
    parameters=[{'use_sim_time': True}]
  )

  goat_robo_node = Node(
    package='my_goat_pkg',
    executable='goat_robo',
    name='goat_robo',
    output='screen',
    parameters=[{'use_sim_time': True}]
  )

  nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(nav2_path),
        launch_arguments={
            'map': map_yaml_file,
            'use_sim_time': 'true',
            'autostart': 'true',
            'params_file': params_path
        }.items()
    )
  


  return LaunchDescription([
    launch.actions.DeclareLaunchArgument(name='rvizconfig', default_value=rviz_config_dir,
                                            description='Absolute path to rviz config file'),
    state_pub,
    gazebo,
    spawn,
    # rviz_node,
    nav2_launch,
    navigator_server_node,
    goat_robo_node
  ])
