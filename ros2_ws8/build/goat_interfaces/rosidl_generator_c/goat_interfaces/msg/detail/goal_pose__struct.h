// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from goat_interfaces:msg/GoalPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__STRUCT_H_
#define GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GoalPose in the package goat_interfaces.
typedef struct goat_interfaces__msg__GoalPose
{
  double x;
  double y;
  double theta;
} goat_interfaces__msg__GoalPose;

// Struct for a sequence of goat_interfaces__msg__GoalPose.
typedef struct goat_interfaces__msg__GoalPose__Sequence
{
  goat_interfaces__msg__GoalPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} goat_interfaces__msg__GoalPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__STRUCT_H_
