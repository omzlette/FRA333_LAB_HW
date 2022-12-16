// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice
#include "doppelt_interfaces/srv/detail/enabler__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
doppelt_interfaces__srv__Enabler_Request__init(doppelt_interfaces__srv__Enabler_Request * msg)
{
  if (!msg) {
    return false;
  }
  // enable
  return true;
}

void
doppelt_interfaces__srv__Enabler_Request__fini(doppelt_interfaces__srv__Enabler_Request * msg)
{
  if (!msg) {
    return;
  }
  // enable
}

bool
doppelt_interfaces__srv__Enabler_Request__are_equal(const doppelt_interfaces__srv__Enabler_Request * lhs, const doppelt_interfaces__srv__Enabler_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enable
  if (lhs->enable != rhs->enable) {
    return false;
  }
  return true;
}

bool
doppelt_interfaces__srv__Enabler_Request__copy(
  const doppelt_interfaces__srv__Enabler_Request * input,
  doppelt_interfaces__srv__Enabler_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // enable
  output->enable = input->enable;
  return true;
}

doppelt_interfaces__srv__Enabler_Request *
doppelt_interfaces__srv__Enabler_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doppelt_interfaces__srv__Enabler_Request * msg = (doppelt_interfaces__srv__Enabler_Request *)allocator.allocate(sizeof(doppelt_interfaces__srv__Enabler_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doppelt_interfaces__srv__Enabler_Request));
  bool success = doppelt_interfaces__srv__Enabler_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doppelt_interfaces__srv__Enabler_Request__destroy(doppelt_interfaces__srv__Enabler_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doppelt_interfaces__srv__Enabler_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doppelt_interfaces__srv__Enabler_Request__Sequence__init(doppelt_interfaces__srv__Enabler_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doppelt_interfaces__srv__Enabler_Request * data = NULL;

  if (size) {
    data = (doppelt_interfaces__srv__Enabler_Request *)allocator.zero_allocate(size, sizeof(doppelt_interfaces__srv__Enabler_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doppelt_interfaces__srv__Enabler_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doppelt_interfaces__srv__Enabler_Request__fini(&data[i - 1]);
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
doppelt_interfaces__srv__Enabler_Request__Sequence__fini(doppelt_interfaces__srv__Enabler_Request__Sequence * array)
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
      doppelt_interfaces__srv__Enabler_Request__fini(&array->data[i]);
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

doppelt_interfaces__srv__Enabler_Request__Sequence *
doppelt_interfaces__srv__Enabler_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doppelt_interfaces__srv__Enabler_Request__Sequence * array = (doppelt_interfaces__srv__Enabler_Request__Sequence *)allocator.allocate(sizeof(doppelt_interfaces__srv__Enabler_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doppelt_interfaces__srv__Enabler_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doppelt_interfaces__srv__Enabler_Request__Sequence__destroy(doppelt_interfaces__srv__Enabler_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doppelt_interfaces__srv__Enabler_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doppelt_interfaces__srv__Enabler_Request__Sequence__are_equal(const doppelt_interfaces__srv__Enabler_Request__Sequence * lhs, const doppelt_interfaces__srv__Enabler_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doppelt_interfaces__srv__Enabler_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doppelt_interfaces__srv__Enabler_Request__Sequence__copy(
  const doppelt_interfaces__srv__Enabler_Request__Sequence * input,
  doppelt_interfaces__srv__Enabler_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doppelt_interfaces__srv__Enabler_Request);
    doppelt_interfaces__srv__Enabler_Request * data =
      (doppelt_interfaces__srv__Enabler_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doppelt_interfaces__srv__Enabler_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          doppelt_interfaces__srv__Enabler_Request__fini(&data[i]);
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
    if (!doppelt_interfaces__srv__Enabler_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
doppelt_interfaces__srv__Enabler_Response__init(doppelt_interfaces__srv__Enabler_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
doppelt_interfaces__srv__Enabler_Response__fini(doppelt_interfaces__srv__Enabler_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
doppelt_interfaces__srv__Enabler_Response__are_equal(const doppelt_interfaces__srv__Enabler_Response * lhs, const doppelt_interfaces__srv__Enabler_Response * rhs)
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
doppelt_interfaces__srv__Enabler_Response__copy(
  const doppelt_interfaces__srv__Enabler_Response * input,
  doppelt_interfaces__srv__Enabler_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

doppelt_interfaces__srv__Enabler_Response *
doppelt_interfaces__srv__Enabler_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doppelt_interfaces__srv__Enabler_Response * msg = (doppelt_interfaces__srv__Enabler_Response *)allocator.allocate(sizeof(doppelt_interfaces__srv__Enabler_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doppelt_interfaces__srv__Enabler_Response));
  bool success = doppelt_interfaces__srv__Enabler_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doppelt_interfaces__srv__Enabler_Response__destroy(doppelt_interfaces__srv__Enabler_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doppelt_interfaces__srv__Enabler_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doppelt_interfaces__srv__Enabler_Response__Sequence__init(doppelt_interfaces__srv__Enabler_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doppelt_interfaces__srv__Enabler_Response * data = NULL;

  if (size) {
    data = (doppelt_interfaces__srv__Enabler_Response *)allocator.zero_allocate(size, sizeof(doppelt_interfaces__srv__Enabler_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doppelt_interfaces__srv__Enabler_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doppelt_interfaces__srv__Enabler_Response__fini(&data[i - 1]);
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
doppelt_interfaces__srv__Enabler_Response__Sequence__fini(doppelt_interfaces__srv__Enabler_Response__Sequence * array)
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
      doppelt_interfaces__srv__Enabler_Response__fini(&array->data[i]);
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

doppelt_interfaces__srv__Enabler_Response__Sequence *
doppelt_interfaces__srv__Enabler_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doppelt_interfaces__srv__Enabler_Response__Sequence * array = (doppelt_interfaces__srv__Enabler_Response__Sequence *)allocator.allocate(sizeof(doppelt_interfaces__srv__Enabler_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doppelt_interfaces__srv__Enabler_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doppelt_interfaces__srv__Enabler_Response__Sequence__destroy(doppelt_interfaces__srv__Enabler_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doppelt_interfaces__srv__Enabler_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doppelt_interfaces__srv__Enabler_Response__Sequence__are_equal(const doppelt_interfaces__srv__Enabler_Response__Sequence * lhs, const doppelt_interfaces__srv__Enabler_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doppelt_interfaces__srv__Enabler_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doppelt_interfaces__srv__Enabler_Response__Sequence__copy(
  const doppelt_interfaces__srv__Enabler_Response__Sequence * input,
  doppelt_interfaces__srv__Enabler_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doppelt_interfaces__srv__Enabler_Response);
    doppelt_interfaces__srv__Enabler_Response * data =
      (doppelt_interfaces__srv__Enabler_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doppelt_interfaces__srv__Enabler_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          doppelt_interfaces__srv__Enabler_Response__fini(&data[i]);
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
    if (!doppelt_interfaces__srv__Enabler_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
