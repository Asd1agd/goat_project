// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from goat_interfaces:msg/GoalPose.idl
// generated code does not contain a copyright notice
#include "goat_interfaces/msg/detail/goal_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
goat_interfaces__msg__GoalPose__init(goat_interfaces__msg__GoalPose * msg)
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
goat_interfaces__msg__GoalPose__fini(goat_interfaces__msg__GoalPose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
}

bool
goat_interfaces__msg__GoalPose__are_equal(const goat_interfaces__msg__GoalPose * lhs, const goat_interfaces__msg__GoalPose * rhs)
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
goat_interfaces__msg__GoalPose__copy(
  const goat_interfaces__msg__GoalPose * input,
  goat_interfaces__msg__GoalPose * output)
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

goat_interfaces__msg__GoalPose *
goat_interfaces__msg__GoalPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__msg__GoalPose * msg = (goat_interfaces__msg__GoalPose *)allocator.allocate(sizeof(goat_interfaces__msg__GoalPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(goat_interfaces__msg__GoalPose));
  bool success = goat_interfaces__msg__GoalPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
goat_interfaces__msg__GoalPose__destroy(goat_interfaces__msg__GoalPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    goat_interfaces__msg__GoalPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
goat_interfaces__msg__GoalPose__Sequence__init(goat_interfaces__msg__GoalPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__msg__GoalPose * data = NULL;

  if (size) {
    data = (goat_interfaces__msg__GoalPose *)allocator.zero_allocate(size, sizeof(goat_interfaces__msg__GoalPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = goat_interfaces__msg__GoalPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        goat_interfaces__msg__GoalPose__fini(&data[i - 1]);
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
goat_interfaces__msg__GoalPose__Sequence__fini(goat_interfaces__msg__GoalPose__Sequence * array)
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
      goat_interfaces__msg__GoalPose__fini(&array->data[i]);
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

goat_interfaces__msg__GoalPose__Sequence *
goat_interfaces__msg__GoalPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  goat_interfaces__msg__GoalPose__Sequence * array = (goat_interfaces__msg__GoalPose__Sequence *)allocator.allocate(sizeof(goat_interfaces__msg__GoalPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = goat_interfaces__msg__GoalPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
goat_interfaces__msg__GoalPose__Sequence__destroy(goat_interfaces__msg__GoalPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    goat_interfaces__msg__GoalPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
goat_interfaces__msg__GoalPose__Sequence__are_equal(const goat_interfaces__msg__GoalPose__Sequence * lhs, const goat_interfaces__msg__GoalPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!goat_interfaces__msg__GoalPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
goat_interfaces__msg__GoalPose__Sequence__copy(
  const goat_interfaces__msg__GoalPose__Sequence * input,
  goat_interfaces__msg__GoalPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(goat_interfaces__msg__GoalPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    goat_interfaces__msg__GoalPose * data =
      (goat_interfaces__msg__GoalPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!goat_interfaces__msg__GoalPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          goat_interfaces__msg__GoalPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!goat_interfaces__msg__GoalPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
