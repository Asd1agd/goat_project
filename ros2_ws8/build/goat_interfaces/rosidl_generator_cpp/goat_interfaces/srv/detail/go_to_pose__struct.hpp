// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__STRUCT_HPP_
#define GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__goat_interfaces__srv__GoToPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__goat_interfaces__srv__GoToPose_Request __declspec(deprecated)
#endif

namespace goat_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoToPose_Request_
{
  using Type = GoToPose_Request_<ContainerAllocator>;

  explicit GoToPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
    }
  }

  explicit GoToPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    goat_interfaces::srv::GoToPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const goat_interfaces::srv::GoToPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      goat_interfaces::srv::GoToPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      goat_interfaces::srv::GoToPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__goat_interfaces__srv__GoToPose_Request
    std::shared_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__goat_interfaces__srv__GoToPose_Request
    std::shared_ptr<goat_interfaces::srv::GoToPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoToPose_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoToPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoToPose_Request_

// alias to use template instance with default allocator
using GoToPose_Request =
  goat_interfaces::srv::GoToPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace goat_interfaces


#ifndef _WIN32
# define DEPRECATED__goat_interfaces__srv__GoToPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__goat_interfaces__srv__GoToPose_Response __declspec(deprecated)
#endif

namespace goat_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoToPose_Response_
{
  using Type = GoToPose_Response_<ContainerAllocator>;

  explicit GoToPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit GoToPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    goat_interfaces::srv::GoToPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const goat_interfaces::srv::GoToPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      goat_interfaces::srv::GoToPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      goat_interfaces::srv::GoToPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__goat_interfaces__srv__GoToPose_Response
    std::shared_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__goat_interfaces__srv__GoToPose_Response
    std::shared_ptr<goat_interfaces::srv::GoToPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoToPose_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoToPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoToPose_Response_

// alias to use template instance with default allocator
using GoToPose_Response =
  goat_interfaces::srv::GoToPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace goat_interfaces

namespace goat_interfaces
{

namespace srv
{

struct GoToPose
{
  using Request = goat_interfaces::srv::GoToPose_Request;
  using Response = goat_interfaces::srv::GoToPose_Response;
};

}  // namespace srv

}  // namespace goat_interfaces

#endif  // GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__STRUCT_HPP_
