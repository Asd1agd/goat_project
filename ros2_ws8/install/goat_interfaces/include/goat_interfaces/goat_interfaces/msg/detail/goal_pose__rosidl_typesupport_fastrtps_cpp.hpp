// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from goat_interfaces:msg/GoalPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "goat_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "goat_interfaces/msg/detail/goal_pose__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace goat_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_goat_interfaces
cdr_serialize(
  const goat_interfaces::msg::GoalPose & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_goat_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  goat_interfaces::msg::GoalPose & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_goat_interfaces
get_serialized_size(
  const goat_interfaces::msg::GoalPose & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_goat_interfaces
max_serialized_size_GoalPose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace goat_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_goat_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, goat_interfaces, msg, GoalPose)();

#ifdef __cplusplus
}
#endif

#endif  // GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
