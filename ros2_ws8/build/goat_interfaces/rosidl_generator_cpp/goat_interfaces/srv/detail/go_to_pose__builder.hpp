// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__BUILDER_HPP_
#define GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "goat_interfaces/srv/detail/go_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace goat_interfaces
{

namespace srv
{

namespace builder
{

class Init_GoToPose_Request_theta
{
public:
  explicit Init_GoToPose_Request_theta(::goat_interfaces::srv::GoToPose_Request & msg)
  : msg_(msg)
  {}
  ::goat_interfaces::srv::GoToPose_Request theta(::goat_interfaces::srv::GoToPose_Request::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::goat_interfaces::srv::GoToPose_Request msg_;
};

class Init_GoToPose_Request_y
{
public:
  explicit Init_GoToPose_Request_y(::goat_interfaces::srv::GoToPose_Request & msg)
  : msg_(msg)
  {}
  Init_GoToPose_Request_theta y(::goat_interfaces::srv::GoToPose_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GoToPose_Request_theta(msg_);
  }

private:
  ::goat_interfaces::srv::GoToPose_Request msg_;
};

class Init_GoToPose_Request_x
{
public:
  Init_GoToPose_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPose_Request_y x(::goat_interfaces::srv::GoToPose_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GoToPose_Request_y(msg_);
  }

private:
  ::goat_interfaces::srv::GoToPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::goat_interfaces::srv::GoToPose_Request>()
{
  return goat_interfaces::srv::builder::Init_GoToPose_Request_x();
}

}  // namespace goat_interfaces


namespace goat_interfaces
{

namespace srv
{

namespace builder
{

class Init_GoToPose_Response_message
{
public:
  explicit Init_GoToPose_Response_message(::goat_interfaces::srv::GoToPose_Response & msg)
  : msg_(msg)
  {}
  ::goat_interfaces::srv::GoToPose_Response message(::goat_interfaces::srv::GoToPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::goat_interfaces::srv::GoToPose_Response msg_;
};

class Init_GoToPose_Response_success
{
public:
  Init_GoToPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPose_Response_message success(::goat_interfaces::srv::GoToPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GoToPose_Response_message(msg_);
  }

private:
  ::goat_interfaces::srv::GoToPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::goat_interfaces::srv::GoToPose_Response>()
{
  return goat_interfaces::srv::builder::Init_GoToPose_Response_success();
}

}  // namespace goat_interfaces

#endif  // GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__BUILDER_HPP_
