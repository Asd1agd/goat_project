// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__STRUCT_H_
#define GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GoToPose in the package goat_interfaces.
typedef struct goat_interfaces__srv__GoToPose_Request
{
  double x;
  double y;
  double theta;
} goat_interfaces__srv__GoToPose_Request;

// Struct for a sequence of goat_interfaces__srv__GoToPose_Request.
typedef struct goat_interfaces__srv__GoToPose_Request__Sequence
{
  goat_interfaces__srv__GoToPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} goat_interfaces__srv__GoToPose_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GoToPose in the package goat_interfaces.
typedef struct goat_interfaces__srv__GoToPose_Response
{
  bool success;
  rosidl_runtime_c__String message;
} goat_interfaces__srv__GoToPose_Response;

// Struct for a sequence of goat_interfaces__srv__GoToPose_Response.
typedef struct goat_interfaces__srv__GoToPose_Response__Sequence
{
  goat_interfaces__srv__GoToPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} goat_interfaces__srv__GoToPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__STRUCT_H_
