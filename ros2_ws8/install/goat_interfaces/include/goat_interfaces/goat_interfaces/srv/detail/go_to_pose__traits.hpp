// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__TRAITS_HPP_
#define GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "goat_interfaces/srv/detail/go_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace goat_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoToPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoToPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoToPose_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace goat_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use goat_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const goat_interfaces::srv::GoToPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  goat_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use goat_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const goat_interfaces::srv::GoToPose_Request & msg)
{
  return goat_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<goat_interfaces::srv::GoToPose_Request>()
{
  return "goat_interfaces::srv::GoToPose_Request";
}

template<>
inline const char * name<goat_interfaces::srv::GoToPose_Request>()
{
  return "goat_interfaces/srv/GoToPose_Request";
}

template<>
struct has_fixed_size<goat_interfaces::srv::GoToPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<goat_interfaces::srv::GoToPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<goat_interfaces::srv::GoToPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace goat_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoToPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoToPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoToPose_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace goat_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use goat_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const goat_interfaces::srv::GoToPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  goat_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use goat_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const goat_interfaces::srv::GoToPose_Response & msg)
{
  return goat_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<goat_interfaces::srv::GoToPose_Response>()
{
  return "goat_interfaces::srv::GoToPose_Response";
}

template<>
inline const char * name<goat_interfaces::srv::GoToPose_Response>()
{
  return "goat_interfaces/srv/GoToPose_Response";
}

template<>
struct has_fixed_size<goat_interfaces::srv::GoToPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<goat_interfaces::srv::GoToPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<goat_interfaces::srv::GoToPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<goat_interfaces::srv::GoToPose>()
{
  return "goat_interfaces::srv::GoToPose";
}

template<>
inline const char * name<goat_interfaces::srv::GoToPose>()
{
  return "goat_interfaces/srv/GoToPose";
}

template<>
struct has_fixed_size<goat_interfaces::srv::GoToPose>
  : std::integral_constant<
    bool,
    has_fixed_size<goat_interfaces::srv::GoToPose_Request>::value &&
    has_fixed_size<goat_interfaces::srv::GoToPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<goat_interfaces::srv::GoToPose>
  : std::integral_constant<
    bool,
    has_bounded_size<goat_interfaces::srv::GoToPose_Request>::value &&
    has_bounded_size<goat_interfaces::srv::GoToPose_Response>::value
  >
{
};

template<>
struct is_service<goat_interfaces::srv::GoToPose>
  : std::true_type
{
};

template<>
struct is_service_request<goat_interfaces::srv::GoToPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<goat_interfaces::srv::GoToPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__TRAITS_HPP_
