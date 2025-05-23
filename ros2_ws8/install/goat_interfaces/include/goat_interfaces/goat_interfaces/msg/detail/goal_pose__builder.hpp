// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from goat_interfaces:msg/GoalPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__BUILDER_HPP_
#define GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "goat_interfaces/msg/detail/goal_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace goat_interfaces
{

namespace msg
{

namespace builder
{

class Init_GoalPose_theta
{
public:
  explicit Init_GoalPose_theta(::goat_interfaces::msg::GoalPose & msg)
  : msg_(msg)
  {}
  ::goat_interfaces::msg::GoalPose theta(::goat_interfaces::msg::GoalPose::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::goat_interfaces::msg::GoalPose msg_;
};

class Init_GoalPose_y
{
public:
  explicit Init_GoalPose_y(::goat_interfaces::msg::GoalPose & msg)
  : msg_(msg)
  {}
  Init_GoalPose_theta y(::goat_interfaces::msg::GoalPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GoalPose_theta(msg_);
  }

private:
  ::goat_interfaces::msg::GoalPose msg_;
};

class Init_GoalPose_x
{
public:
  Init_GoalPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoalPose_y x(::goat_interfaces::msg::GoalPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GoalPose_y(msg_);
  }

private:
  ::goat_interfaces::msg::GoalPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::goat_interfaces::msg::GoalPose>()
{
  return goat_interfaces::msg::builder::Init_GoalPose_x();
}

}  // namespace goat_interfaces

#endif  // GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__BUILDER_HPP_
