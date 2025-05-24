# Hotel Waiter Robot Navigation Project

> A ROS 2-based autonomous robot simulation designed for restaurant environments. The robot acts as a **smart waiter**, navigating to tables, interacting with a kitchen queue system, and processing dynamic goals with a GUI.

---

## 📁 Project Overview

This project is developed using:
- **ROS 2 Humble**
- **Gazebo** simulation environment
- **Nav2 Stack** for autonomous navigation
- **Python-based custom logic** and GUI interface

It simulates a **waiter robot** in a hotel environment with a fully integrated navigation and order-handling system.

---

## 🧾 Folder Structure (`ros2_ws9/src/`)

```bash
ros2_ws9/src/
├── goat_gazebo/                  # Map, launch, YAML configs
├── goat_interfaces/              # Custom interfaces (msgs/srvs)
├── my_goat_pkg/
│   ├── my_goat_pkg/
│   │   ├── gui.py                # GUI app for hotel tables
│   │   ├── navigator.py          # Sends Nav2 goals
│   │   ├── robot_core_logic.py   # Robot state machine logic
│   │   └── simple_commander_api_template.py  # Goal command utility
│   ├── setup.py, setup.cfg, package.xml, resource/
├── testbed_description_goat/     # URDF, RViz config
├── testbed_gazebo_goat/          # World and spawn logic
├── turtlebot3_gazebo_goat/
├── turtlebot3_fake_node/
├── turtlebot3_simulations/
```

🚀 Getting Started
🔧 Build the Workspace

cd ~/ros2_ws9
colcon build
source install/setup.bash

🧭 Launch the Full Simulation

ros2 launch goat_gazebo goat_hotel.launch.py

This will:

    Start Gazebo world

    Spawn robot using testbed_gazebo_goat

    Load Nav2 stack with turtlebot3_navigation2

    Start robot description + state publisher

    Launch logic nodes: navigator_server and goat_robo

    Load the map goat_hotel.yaml and navigation parameters

🖥️ GUI: Table Order Management

The project includes a Python GUI to manage dynamic restaurant orders.
▶️ Launch GUI

cd ~/ros2_ws9/src/my_goat_pkg/my_goat_pkg
python3 gui.py

Features:

    Add/remove table requests (e.g., Table 1, 2…)

    Visual feedback on order status

    Waiter and kitchen queues

    Interacts with robot via ROS 2 services and topics

    🔄 Make sure the launch file is running before starting the GUI.

🧠 Node Descriptions
Node File	Description
gui.py	Tkinter GUI for order input and robot queue
navigator.py	Handles Nav2 goal publishing from table queue
robot_core_logic.py	State machine for handling waiter → kitchen behavior
simple_commander_api_template.py	Helper for sending navigation goals
🗺️ Navigation Details

    Map YAML: goat_gazebo/maps/goat_hotel.yaml

    Nav2 Params: turtlebot3_navigation2/param/waffle.yaml

    RViz Config: testbed_description_goat/rviz/full_bringup.rviz

If you want to manually load RViz:

ros2 launch goat_gazebo goat_hotel.launch.py rvizconfig:=<path_to_config.rviz>

👨‍💻 Maintainer

Atharav Dabhade
ROS 2 Developer | DD Robocon AIR-2 | Robotics Enthusiast
GitHub: Asd1agd
