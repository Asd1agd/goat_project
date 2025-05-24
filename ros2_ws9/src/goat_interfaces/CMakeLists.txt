cmake_minimum_required(VERSION 3.8)
project(goat_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

## If you use this service in Python or C++, you may also need these:
# find_package(builtin_interfaces REQUIRED)  # Only if used in .srv
# find_package(std_msgs REQUIRED)           # If used

# Interface generation
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/GoToPose.srv"
)

# Export dependencies
ament_export_dependencies(rosidl_default_runtime)

ament_package()

