// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice

#ifndef GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__FUNCTIONS_H_
#define GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "goat_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "goat_interfaces/srv/detail/go_to_pose__struct.h"

/// Initialize srv/GoToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * goat_interfaces__srv__GoToPose_Request
 * )) before or use
 * goat_interfaces__srv__GoToPose_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Request__init(goat_interfaces__srv__GoToPose_Request * msg);

/// Finalize srv/GoToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Request__fini(goat_interfaces__srv__GoToPose_Request * msg);

/// Create srv/GoToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * goat_interfaces__srv__GoToPose_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
goat_interfaces__srv__GoToPose_Request *
goat_interfaces__srv__GoToPose_Request__create();

/// Destroy srv/GoToPose message.
/**
 * It calls
 * goat_interfaces__srv__GoToPose_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Request__destroy(goat_interfaces__srv__GoToPose_Request * msg);

/// Check for srv/GoToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Request__are_equal(const goat_interfaces__srv__GoToPose_Request * lhs, const goat_interfaces__srv__GoToPose_Request * rhs);

/// Copy a srv/GoToPose message.
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
goat_interfaces__srv__GoToPose_Request__copy(
  const goat_interfaces__srv__GoToPose_Request * input,
  goat_interfaces__srv__GoToPose_Request * output);

/// Initialize array of srv/GoToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * goat_interfaces__srv__GoToPose_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Request__Sequence__init(goat_interfaces__srv__GoToPose_Request__Sequence * array, size_t size);

/// Finalize array of srv/GoToPose messages.
/**
 * It calls
 * goat_interfaces__srv__GoToPose_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Request__Sequence__fini(goat_interfaces__srv__GoToPose_Request__Sequence * array);

/// Create array of srv/GoToPose messages.
/**
 * It allocates the memory for the array and calls
 * goat_interfaces__srv__GoToPose_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
goat_interfaces__srv__GoToPose_Request__Sequence *
goat_interfaces__srv__GoToPose_Request__Sequence__create(size_t size);

/// Destroy array of srv/GoToPose messages.
/**
 * It calls
 * goat_interfaces__srv__GoToPose_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Request__Sequence__destroy(goat_interfaces__srv__GoToPose_Request__Sequence * array);

/// Check for srv/GoToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Request__Sequence__are_equal(const goat_interfaces__srv__GoToPose_Request__Sequence * lhs, const goat_interfaces__srv__GoToPose_Request__Sequence * rhs);

/// Copy an array of srv/GoToPose messages.
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
goat_interfaces__srv__GoToPose_Request__Sequence__copy(
  const goat_interfaces__srv__GoToPose_Request__Sequence * input,
  goat_interfaces__srv__GoToPose_Request__Sequence * output);

/// Initialize srv/GoToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * goat_interfaces__srv__GoToPose_Response
 * )) before or use
 * goat_interfaces__srv__GoToPose_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Response__init(goat_interfaces__srv__GoToPose_Response * msg);

/// Finalize srv/GoToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Response__fini(goat_interfaces__srv__GoToPose_Response * msg);

/// Create srv/GoToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * goat_interfaces__srv__GoToPose_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
goat_interfaces__srv__GoToPose_Response *
goat_interfaces__srv__GoToPose_Response__create();

/// Destroy srv/GoToPose message.
/**
 * It calls
 * goat_interfaces__srv__GoToPose_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Response__destroy(goat_interfaces__srv__GoToPose_Response * msg);

/// Check for srv/GoToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Response__are_equal(const goat_interfaces__srv__GoToPose_Response * lhs, const goat_interfaces__srv__GoToPose_Response * rhs);

/// Copy a srv/GoToPose message.
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
goat_interfaces__srv__GoToPose_Response__copy(
  const goat_interfaces__srv__GoToPose_Response * input,
  goat_interfaces__srv__GoToPose_Response * output);

/// Initialize array of srv/GoToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * goat_interfaces__srv__GoToPose_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Response__Sequence__init(goat_interfaces__srv__GoToPose_Response__Sequence * array, size_t size);

/// Finalize array of srv/GoToPose messages.
/**
 * It calls
 * goat_interfaces__srv__GoToPose_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Response__Sequence__fini(goat_interfaces__srv__GoToPose_Response__Sequence * array);

/// Create array of srv/GoToPose messages.
/**
 * It allocates the memory for the array and calls
 * goat_interfaces__srv__GoToPose_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
goat_interfaces__srv__GoToPose_Response__Sequence *
goat_interfaces__srv__GoToPose_Response__Sequence__create(size_t size);

/// Destroy array of srv/GoToPose messages.
/**
 * It calls
 * goat_interfaces__srv__GoToPose_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
void
goat_interfaces__srv__GoToPose_Response__Sequence__destroy(goat_interfaces__srv__GoToPose_Response__Sequence * array);

/// Check for srv/GoToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_goat_interfaces
bool
goat_interfaces__srv__GoToPose_Response__Sequence__are_equal(const goat_interfaces__srv__GoToPose_Response__Sequence * lhs, const goat_interfaces__srv__GoToPose_Response__Sequence * rhs);

/// Copy an array of srv/GoToPose messages.
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
goat_interfaces__srv__GoToPose_Response__Sequence__copy(
  const goat_interfaces__srv__GoToPose_Response__Sequence * input,
  goat_interfaces__srv__GoToPose_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GOAT_INTERFACES__SRV__DETAIL__GO_TO_POSE__FUNCTIONS_H_
