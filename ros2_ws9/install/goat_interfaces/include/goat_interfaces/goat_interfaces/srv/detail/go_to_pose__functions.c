// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice
#include "goat_interfaces/srv/detail/go_to_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
goat_interfaces__srv__GoToPose_Request__init(goat_interfaces__srv__GoToPose_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // theta
  return true;
}

void
goat_interfaces__srv__GoToPose_Request__fini(goat_interfaces__srv__GoToPose_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
}

bool
goat_interfaces__srv__GoToPose_Request__are_equal(const goat_interfaces__srv__GoToPose_Request * lhs, const goat_interfaces__srv__GoToPose_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  return true;
}

bool
goat_interfaces__srv__GoToPose_Request__copy(
  const goat_interfaces__srv__GoToPose_Request * input,
  goat_interfaces__srv__GoToPose_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  return true;
}

goat_interfaces__srv__GoToPose_Request *
goat_interfaces__srv__GoToPose_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__srv__GoToPose_Request * msg = (goat_interfaces__srv__GoToPose_Request *)allocator.allocate(sizeof(goat_interfaces__srv__GoToPose_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(goat_interfaces__srv__GoToPose_Request));
  bool success = goat_interfaces__srv__GoToPose_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
goat_interfaces__srv__GoToPose_Request__destroy(goat_interfaces__srv__GoToPose_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    goat_interfaces__srv__GoToPose_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
goat_interfaces__srv__GoToPose_Request__Sequence__init(goat_interfaces__srv__GoToPose_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__srv__GoToPose_Request * data = NULL;

  if (size) {
    data = (goat_interfaces__srv__GoToPose_Request *)allocator.zero_allocate(size, sizeof(goat_interfaces__srv__GoToPose_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = goat_interfaces__srv__GoToPose_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        goat_interfaces__srv__GoToPose_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
goat_interfaces__srv__GoToPose_Request__Sequence__fini(goat_interfaces__srv__GoToPose_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      goat_interfaces__srv__GoToPose_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

goat_interfaces__srv__GoToPose_Request__Sequence *
goat_interfaces__srv__GoToPose_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__srv__GoToPose_Request__Sequence * array = (goat_interfaces__srv__GoToPose_Request__Sequence *)allocator.allocate(sizeof(goat_interfaces__srv__GoToPose_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = goat_interfaces__srv__GoToPose_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
goat_interfaces__srv__GoToPose_Request__Sequence__destroy(goat_interfaces__srv__GoToPose_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    goat_interfaces__srv__GoToPose_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
goat_interfaces__srv__GoToPose_Request__Sequence__are_equal(const goat_interfaces__srv__GoToPose_Request__Sequence * lhs, const goat_interfaces__srv__GoToPose_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!goat_interfaces__srv__GoToPose_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
goat_interfaces__srv__GoToPose_Request__Sequence__copy(
  const goat_interfaces__srv__GoToPose_Request__Sequence * input,
  goat_interfaces__srv__GoToPose_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(goat_interfaces__srv__GoToPose_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    goat_interfaces__srv__GoToPose_Request * data =
      (goat_interfaces__srv__GoToPose_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!goat_interfaces__srv__GoToPose_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          goat_interfaces__srv__GoToPose_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!goat_interfaces__srv__GoToPose_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
goat_interfaces__srv__GoToPose_Response__init(goat_interfaces__srv__GoToPose_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    goat_interfaces__srv__GoToPose_Response__fini(msg);
    return false;
  }
  return true;
}

void
goat_interfaces__srv__GoToPose_Response__fini(goat_interfaces__srv__GoToPose_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
goat_interfaces__srv__GoToPose_Response__are_equal(const goat_interfaces__srv__GoToPose_Response * lhs, const goat_interfaces__srv__GoToPose_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
goat_interfaces__srv__GoToPose_Response__copy(
  const goat_interfaces__srv__GoToPose_Response * input,
  goat_interfaces__srv__GoToPose_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

goat_interfaces__srv__GoToPose_Response *
goat_interfaces__srv__GoToPose_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__srv__GoToPose_Response * msg = (goat_interfaces__srv__GoToPose_Response *)allocator.allocate(sizeof(goat_interfaces__srv__GoToPose_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(goat_interfaces__srv__GoToPose_Response));
  bool success = goat_interfaces__srv__GoToPose_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
goat_interfaces__srv__GoToPose_Response__destroy(goat_interfaces__srv__GoToPose_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    goat_interfaces__srv__GoToPose_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
goat_interfaces__srv__GoToPose_Response__Sequence__init(goat_interfaces__srv__GoToPose_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__srv__GoToPose_Response * data = NULL;

  if (size) {
    data = (goat_interfaces__srv__GoToPose_Response *)allocator.zero_allocate(size, sizeof(goat_interfaces__srv__GoToPose_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = goat_interfaces__srv__GoToPose_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        goat_interfaces__srv__GoToPose_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
goat_interfaces__srv__GoToPose_Response__Sequence__fini(goat_interfaces__srv__GoToPose_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      goat_interfaces__srv__GoToPose_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

goat_interfaces__srv__GoToPose_Response__Sequence *
goat_interfaces__srv__GoToPose_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__srv__GoToPose_Response__Sequence * array = (goat_interfaces__srv__GoToPose_Response__Sequence *)allocator.allocate(sizeof(goat_interfaces__srv__GoToPose_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = goat_interfaces__srv__GoToPose_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
goat_interfaces__srv__GoToPose_Response__Sequence__destroy(goat_interfaces__srv__GoToPose_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    goat_interfaces__srv__GoToPose_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
goat_interfaces__srv__GoToPose_Response__Sequence__are_equal(const goat_interfaces__srv__GoToPose_Response__Sequence * lhs, const goat_interfaces__srv__GoToPose_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!goat_interfaces__srv__GoToPose_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
goat_interfaces__srv__GoToPose_Response__Sequence__copy(
  const goat_interfaces__srv__GoToPose_Response__Sequence * input,
  goat_interfaces__srv__GoToPose_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(goat_interfaces__srv__GoToPose_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    goat_interfaces__srv__GoToPose_Response * data =
      (goat_interfaces__srv__GoToPose_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!goat_interfaces__srv__GoToPose_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          goat_interfaces__srv__GoToPose_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!goat_interfaces__srv__GoToPose_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
