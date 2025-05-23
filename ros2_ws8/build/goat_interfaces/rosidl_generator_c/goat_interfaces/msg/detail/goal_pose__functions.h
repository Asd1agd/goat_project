// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from goat_interfaces:msg/GoalPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__FUNCTIONS_H_
#define GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "goat_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "goat_interfaces/msg/detail/goal_pose__struct.h"

/// Initialize msg/GoalPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * goat_interfaces__msg__GoalPose
 * )) before or use
 * goat_interfaces__msg__GoalPose__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__msg__GoalPose__init(goat_interfaces__msg__GoalPose * msg);

/// Finalize msg/GoalPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__msg__GoalPose__fini(goat_interfaces__msg__GoalPose * msg);

/// Create msg/GoalPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * goat_interfaces__msg__GoalPose__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
goat_interfaces__msg__GoalPose *
goat_interfaces__msg__GoalPose__create();

/// Destroy msg/GoalPose message.
/**
 * It calls
 * goat_interfaces__msg__GoalPose__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__msg__GoalPose__destroy(goat_interfaces__msg__GoalPose * msg);

/// Check for msg/GoalPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__msg__GoalPose__are_equal(const goat_interfaces__msg__GoalPose * lhs, const goat_interfaces__msg__GoalPose * rhs);

/// Copy a msg/GoalPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__msg__GoalPose__copy(
  const goat_interfaces__msg__GoalPose * input,
  goat_interfaces__msg__GoalPose * output);

/// Initialize array of msg/GoalPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * goat_interfaces__msg__GoalPose__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__msg__GoalPose__Sequence__init(goat_interfaces__msg__GoalPose__Sequence * array, size_t size);

/// Finalize array of msg/GoalPose messages.
/**
 * It calls
 * goat_interfaces__msg__GoalPose__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__msg__GoalPose__Sequence__fini(goat_interfaces__msg__GoalPose__Sequence * array);

/// Create array of msg/GoalPose messages.
/**
 * It allocates the memory for the array and calls
 * goat_interfaces__msg__GoalPose__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
goat_interfaces__msg__GoalPose__Sequence *
goat_interfaces__msg__GoalPose__Sequence__create(size_t size);

/// Destroy array of msg/GoalPose messages.
/**
 * It calls
 * goat_interfaces__msg__GoalPose__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__msg__GoalPose__Sequence__destroy(goat_interfaces__msg__GoalPose__Sequence * array);

/// Check for msg/GoalPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__msg__GoalPose__Sequence__are_equal(const goat_interfaces__msg__GoalPose__Sequence * lhs, const goat_interfaces__msg__GoalPose__Sequence * rhs);

/// Copy an array of msg/GoalPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__msg__GoalPose__Sequence__copy(
  const goat_interfaces__msg__GoalPose__Sequence * input,
  goat_interfaces__msg__GoalPose__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GOAT_INTERFACES__MSG__DETAIL__GOAL_POSE__FUNCTIONS_H_
