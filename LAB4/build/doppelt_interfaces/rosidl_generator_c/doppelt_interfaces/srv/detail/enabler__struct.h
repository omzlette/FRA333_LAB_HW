// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice

#ifndef DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__STRUCT_H_
#define DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'enable'
#include "std_msgs/msg/detail/bool__struct.h"

// Struct defined in srv/Enabler in the package doppelt_interfaces.
typedef struct doppelt_interfaces__srv__Enabler_Request
{
  std_msgs__msg__Bool enable;
} doppelt_interfaces__srv__Enabler_Request;

// Struct for a sequence of doppelt_interfaces__srv__Enabler_Request.
typedef struct doppelt_interfaces__srv__Enabler_Request__Sequence
{
  doppelt_interfaces__srv__Enabler_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doppelt_interfaces__srv__Enabler_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Enabler in the package doppelt_interfaces.
typedef struct doppelt_interfaces__srv__Enabler_Response
{
  uint8_t structure_needs_at_least_one_member;
} doppelt_interfaces__srv__Enabler_Response;

// Struct for a sequence of doppelt_interfaces__srv__Enabler_Response.
typedef struct doppelt_interfaces__srv__Enabler_Response__Sequence
{
  doppelt_interfaces__srv__Enabler_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doppelt_interfaces__srv__Enabler_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__STRUCT_H_
