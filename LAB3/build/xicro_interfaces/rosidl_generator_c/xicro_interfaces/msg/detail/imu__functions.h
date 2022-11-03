// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xicro_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef XICRO_INTERFACES__MSG__DETAIL__IMU__FUNCTIONS_H_
#define XICRO_INTERFACES__MSG__DETAIL__IMU__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xicro_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "xicro_interfaces/msg/detail/imu__struct.h"

/// Initialize msg/Imu message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xicro_interfaces__msg__Imu
 * )) before or use
 * xicro_interfaces__msg__Imu__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Imu__init(xicro_interfaces__msg__Imu * msg);

/// Finalize msg/Imu message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Imu__fini(xicro_interfaces__msg__Imu * msg);

/// Create msg/Imu message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xicro_interfaces__msg__Imu__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
xicro_interfaces__msg__Imu *
xicro_interfaces__msg__Imu__create();

/// Destroy msg/Imu message.
/**
 * It calls
 * xicro_interfaces__msg__Imu__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Imu__destroy(xicro_interfaces__msg__Imu * msg);

/// Check for msg/Imu message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Imu__are_equal(const xicro_interfaces__msg__Imu * lhs, const xicro_interfaces__msg__Imu * rhs);

/// Copy a msg/Imu message.
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
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Imu__copy(
  const xicro_interfaces__msg__Imu * input,
  xicro_interfaces__msg__Imu * output);

/// Initialize array of msg/Imu messages.
/**
 * It allocates the memory for the number of elements and calls
 * xicro_interfaces__msg__Imu__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Imu__Sequence__init(xicro_interfaces__msg__Imu__Sequence * array, size_t size);

/// Finalize array of msg/Imu messages.
/**
 * It calls
 * xicro_interfaces__msg__Imu__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Imu__Sequence__fini(xicro_interfaces__msg__Imu__Sequence * array);

/// Create array of msg/Imu messages.
/**
 * It allocates the memory for the array and calls
 * xicro_interfaces__msg__Imu__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
xicro_interfaces__msg__Imu__Sequence *
xicro_interfaces__msg__Imu__Sequence__create(size_t size);

/// Destroy array of msg/Imu messages.
/**
 * It calls
 * xicro_interfaces__msg__Imu__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Imu__Sequence__destroy(xicro_interfaces__msg__Imu__Sequence * array);

/// Check for msg/Imu message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Imu__Sequence__are_equal(const xicro_interfaces__msg__Imu__Sequence * lhs, const xicro_interfaces__msg__Imu__Sequence * rhs);

/// Copy an array of msg/Imu messages.
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
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Imu__Sequence__copy(
  const xicro_interfaces__msg__Imu__Sequence * input,
  xicro_interfaces__msg__Imu__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XICRO_INTERFACES__MSG__DETAIL__IMU__FUNCTIONS_H_
