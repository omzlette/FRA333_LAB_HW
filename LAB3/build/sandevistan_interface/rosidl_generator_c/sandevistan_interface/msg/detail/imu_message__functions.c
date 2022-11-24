// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice
#include "sandevistan_interface/msg/detail/imu_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sandevistan_interface__msg__IMUMessage__init(sandevistan_interface__msg__IMUMessage * msg)
{
  if (!msg) {
    return false;
  }
  // linear_acceleration
  // angular_velocity
  return true;
}

void
sandevistan_interface__msg__IMUMessage__fini(sandevistan_interface__msg__IMUMessage * msg)
{
  if (!msg) {
    return;
  }
  // linear_acceleration
  // angular_velocity
}

bool
sandevistan_interface__msg__IMUMessage__are_equal(const sandevistan_interface__msg__IMUMessage * lhs, const sandevistan_interface__msg__IMUMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // linear_acceleration
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->linear_acceleration[i] != rhs->linear_acceleration[i]) {
      return false;
    }
  }
  // angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->angular_velocity[i] != rhs->angular_velocity[i]) {
      return false;
    }
  }
  return true;
}

bool
sandevistan_interface__msg__IMUMessage__copy(
  const sandevistan_interface__msg__IMUMessage * input,
  sandevistan_interface__msg__IMUMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // linear_acceleration
  for (size_t i = 0; i < 3; ++i) {
    output->linear_acceleration[i] = input->linear_acceleration[i];
  }
  // angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    output->angular_velocity[i] = input->angular_velocity[i];
  }
  return true;
}

sandevistan_interface__msg__IMUMessage *
sandevistan_interface__msg__IMUMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sandevistan_interface__msg__IMUMessage * msg = (sandevistan_interface__msg__IMUMessage *)allocator.allocate(sizeof(sandevistan_interface__msg__IMUMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sandevistan_interface__msg__IMUMessage));
  bool success = sandevistan_interface__msg__IMUMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sandevistan_interface__msg__IMUMessage__destroy(sandevistan_interface__msg__IMUMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sandevistan_interface__msg__IMUMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sandevistan_interface__msg__IMUMessage__Sequence__init(sandevistan_interface__msg__IMUMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sandevistan_interface__msg__IMUMessage * data = NULL;

  if (size) {
    data = (sandevistan_interface__msg__IMUMessage *)allocator.zero_allocate(size, sizeof(sandevistan_interface__msg__IMUMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sandevistan_interface__msg__IMUMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sandevistan_interface__msg__IMUMessage__fini(&data[i - 1]);
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
sandevistan_interface__msg__IMUMessage__Sequence__fini(sandevistan_interface__msg__IMUMessage__Sequence * array)
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
      sandevistan_interface__msg__IMUMessage__fini(&array->data[i]);
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

sandevistan_interface__msg__IMUMessage__Sequence *
sandevistan_interface__msg__IMUMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sandevistan_interface__msg__IMUMessage__Sequence * array = (sandevistan_interface__msg__IMUMessage__Sequence *)allocator.allocate(sizeof(sandevistan_interface__msg__IMUMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sandevistan_interface__msg__IMUMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sandevistan_interface__msg__IMUMessage__Sequence__destroy(sandevistan_interface__msg__IMUMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sandevistan_interface__msg__IMUMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sandevistan_interface__msg__IMUMessage__Sequence__are_equal(const sandevistan_interface__msg__IMUMessage__Sequence * lhs, const sandevistan_interface__msg__IMUMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sandevistan_interface__msg__IMUMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sandevistan_interface__msg__IMUMessage__Sequence__copy(
  const sandevistan_interface__msg__IMUMessage__Sequence * input,
  sandevistan_interface__msg__IMUMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sandevistan_interface__msg__IMUMessage);
    sandevistan_interface__msg__IMUMessage * data =
      (sandevistan_interface__msg__IMUMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sandevistan_interface__msg__IMUMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          sandevistan_interface__msg__IMUMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sandevistan_interface__msg__IMUMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
