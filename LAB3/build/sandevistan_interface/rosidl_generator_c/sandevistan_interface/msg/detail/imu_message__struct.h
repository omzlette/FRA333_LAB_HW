// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__STRUCT_H_
#define SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/IMUMessage in the package sandevistan_interface.
typedef struct sandevistan_interface__msg__IMUMessage
{
  double linear_acceleration[3];
  double angular_velocity[3];
} sandevistan_interface__msg__IMUMessage;

// Struct for a sequence of sandevistan_interface__msg__IMUMessage.
typedef struct sandevistan_interface__msg__IMUMessage__Sequence
{
  sandevistan_interface__msg__IMUMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sandevistan_interface__msg__IMUMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__STRUCT_H_
