// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lab1_interfaces:srv/SetNoise.idl
// generated code does not contain a copyright notice
#include "lab1_interfaces/srv/detail/set_noise__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `mean`
// Member `variance`
#include "std_msgs/msg/detail/float64__functions.h"

bool
lab1_interfaces__srv__SetNoise_Request__init(lab1_interfaces__srv__SetNoise_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mean
  if (!std_msgs__msg__Float64__init(&msg->mean)) {
    lab1_interfaces__srv__SetNoise_Request__fini(msg);
    return false;
  }
  // variance
  if (!std_msgs__msg__Float64__init(&msg->variance)) {
    lab1_interfaces__srv__SetNoise_Request__fini(msg);
    return false;
  }
  return true;
}

void
lab1_interfaces__srv__SetNoise_Request__fini(lab1_interfaces__srv__SetNoise_Request * msg)
{
  if (!msg) {
    return;
  }
  // mean
  std_msgs__msg__Float64__fini(&msg->mean);
  // variance
  std_msgs__msg__Float64__fini(&msg->variance);
}

bool
lab1_interfaces__srv__SetNoise_Request__are_equal(const lab1_interfaces__srv__SetNoise_Request * lhs, const lab1_interfaces__srv__SetNoise_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mean
  if (!std_msgs__msg__Float64__are_equal(
      &(lhs->mean), &(rhs->mean)))
  {
    return false;
  }
  // variance
  if (!std_msgs__msg__Float64__are_equal(
      &(lhs->variance), &(rhs->variance)))
  {
    return false;
  }
  return true;
}

bool
lab1_interfaces__srv__SetNoise_Request__copy(
  const lab1_interfaces__srv__SetNoise_Request * input,
  lab1_interfaces__srv__SetNoise_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mean
  if (!std_msgs__msg__Float64__copy(
      &(input->mean), &(output->mean)))
  {
    return false;
  }
  // variance
  if (!std_msgs__msg__Float64__copy(
      &(input->variance), &(output->variance)))
  {
    return false;
  }
  return true;
}

lab1_interfaces__srv__SetNoise_Request *
lab1_interfaces__srv__SetNoise_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab1_interfaces__srv__SetNoise_Request * msg = (lab1_interfaces__srv__SetNoise_Request *)allocator.allocate(sizeof(lab1_interfaces__srv__SetNoise_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab1_interfaces__srv__SetNoise_Request));
  bool success = lab1_interfaces__srv__SetNoise_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab1_interfaces__srv__SetNoise_Request__destroy(lab1_interfaces__srv__SetNoise_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab1_interfaces__srv__SetNoise_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab1_interfaces__srv__SetNoise_Request__Sequence__init(lab1_interfaces__srv__SetNoise_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab1_interfaces__srv__SetNoise_Request * data = NULL;

  if (size) {
    data = (lab1_interfaces__srv__SetNoise_Request *)allocator.zero_allocate(size, sizeof(lab1_interfaces__srv__SetNoise_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab1_interfaces__srv__SetNoise_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab1_interfaces__srv__SetNoise_Request__fini(&data[i - 1]);
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
lab1_interfaces__srv__SetNoise_Request__Sequence__fini(lab1_interfaces__srv__SetNoise_Request__Sequence * array)
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
      lab1_interfaces__srv__SetNoise_Request__fini(&array->data[i]);
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

lab1_interfaces__srv__SetNoise_Request__Sequence *
lab1_interfaces__srv__SetNoise_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab1_interfaces__srv__SetNoise_Request__Sequence * array = (lab1_interfaces__srv__SetNoise_Request__Sequence *)allocator.allocate(sizeof(lab1_interfaces__srv__SetNoise_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab1_interfaces__srv__SetNoise_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab1_interfaces__srv__SetNoise_Request__Sequence__destroy(lab1_interfaces__srv__SetNoise_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab1_interfaces__srv__SetNoise_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab1_interfaces__srv__SetNoise_Request__Sequence__are_equal(const lab1_interfaces__srv__SetNoise_Request__Sequence * lhs, const lab1_interfaces__srv__SetNoise_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab1_interfaces__srv__SetNoise_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab1_interfaces__srv__SetNoise_Request__Sequence__copy(
  const lab1_interfaces__srv__SetNoise_Request__Sequence * input,
  lab1_interfaces__srv__SetNoise_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab1_interfaces__srv__SetNoise_Request);
    lab1_interfaces__srv__SetNoise_Request * data =
      (lab1_interfaces__srv__SetNoise_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab1_interfaces__srv__SetNoise_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          lab1_interfaces__srv__SetNoise_Request__fini(&data[i]);
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
    if (!lab1_interfaces__srv__SetNoise_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
lab1_interfaces__srv__SetNoise_Response__init(lab1_interfaces__srv__SetNoise_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
lab1_interfaces__srv__SetNoise_Response__fini(lab1_interfaces__srv__SetNoise_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
lab1_interfaces__srv__SetNoise_Response__are_equal(const lab1_interfaces__srv__SetNoise_Response * lhs, const lab1_interfaces__srv__SetNoise_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
lab1_interfaces__srv__SetNoise_Response__copy(
  const lab1_interfaces__srv__SetNoise_Response * input,
  lab1_interfaces__srv__SetNoise_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

lab1_interfaces__srv__SetNoise_Response *
lab1_interfaces__srv__SetNoise_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab1_interfaces__srv__SetNoise_Response * msg = (lab1_interfaces__srv__SetNoise_Response *)allocator.allocate(sizeof(lab1_interfaces__srv__SetNoise_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab1_interfaces__srv__SetNoise_Response));
  bool success = lab1_interfaces__srv__SetNoise_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab1_interfaces__srv__SetNoise_Response__destroy(lab1_interfaces__srv__SetNoise_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab1_interfaces__srv__SetNoise_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab1_interfaces__srv__SetNoise_Response__Sequence__init(lab1_interfaces__srv__SetNoise_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab1_interfaces__srv__SetNoise_Response * data = NULL;

  if (size) {
    data = (lab1_interfaces__srv__SetNoise_Response *)allocator.zero_allocate(size, sizeof(lab1_interfaces__srv__SetNoise_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab1_interfaces__srv__SetNoise_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab1_interfaces__srv__SetNoise_Response__fini(&data[i - 1]);
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
lab1_interfaces__srv__SetNoise_Response__Sequence__fini(lab1_interfaces__srv__SetNoise_Response__Sequence * array)
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
      lab1_interfaces__srv__SetNoise_Response__fini(&array->data[i]);
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

lab1_interfaces__srv__SetNoise_Response__Sequence *
lab1_interfaces__srv__SetNoise_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab1_interfaces__srv__SetNoise_Response__Sequence * array = (lab1_interfaces__srv__SetNoise_Response__Sequence *)allocator.allocate(sizeof(lab1_interfaces__srv__SetNoise_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab1_interfaces__srv__SetNoise_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab1_interfaces__srv__SetNoise_Response__Sequence__destroy(lab1_interfaces__srv__SetNoise_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab1_interfaces__srv__SetNoise_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab1_interfaces__srv__SetNoise_Response__Sequence__are_equal(const lab1_interfaces__srv__SetNoise_Response__Sequence * lhs, const lab1_interfaces__srv__SetNoise_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab1_interfaces__srv__SetNoise_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab1_interfaces__srv__SetNoise_Response__Sequence__copy(
  const lab1_interfaces__srv__SetNoise_Response__Sequence * input,
  lab1_interfaces__srv__SetNoise_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab1_interfaces__srv__SetNoise_Response);
    lab1_interfaces__srv__SetNoise_Response * data =
      (lab1_interfaces__srv__SetNoise_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab1_interfaces__srv__SetNoise_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          lab1_interfaces__srv__SetNoise_Response__fini(&data[i]);
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
    if (!lab1_interfaces__srv__SetNoise_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
