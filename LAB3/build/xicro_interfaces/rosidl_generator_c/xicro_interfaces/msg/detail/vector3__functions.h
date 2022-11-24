// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xicro_interfaces:msg/Vector3.idl
// generated code does not contain a copyright notice

#ifndef XICRO_INTERFACES__MSG__DETAIL__VECTOR3__FUNCTIONS_H_
#define XICRO_INTERFACES__MSG__DETAIL__VECTOR3__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xicro_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "xicro_interfaces/msg/detail/vector3__struct.h"

/// Initialize msg/Vector3 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xicro_interfaces__msg__Vector3
 * )) before or use
 * xicro_interfaces__msg__Vector3__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Vector3__init(xicro_interfaces__msg__Vector3 * msg);

/// Finalize msg/Vector3 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Vector3__fini(xicro_interfaces__msg__Vector3 * msg);

/// Create msg/Vector3 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xicro_interfaces__msg__Vector3__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
xicro_interfaces__msg__Vector3 *
xicro_interfaces__msg__Vector3__create();

/// Destroy msg/Vector3 message.
/**
 * It calls
 * xicro_interfaces__msg__Vector3__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Vector3__destroy(xicro_interfaces__msg__Vector3 * msg);

/// Check for msg/Vector3 message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Vector3__are_equal(const xicro_interfaces__msg__Vector3 * lhs, const xicro_interfaces__msg__Vector3 * rhs);

/// Copy a msg/Vector3 message.
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
xicro_interfaces__msg__Vector3__copy(
  const xicro_interfaces__msg__Vector3 * input,
  xicro_interfaces__msg__Vector3 * output);

/// Initialize array of msg/Vector3 messages.
/**
 * It allocates the memory for the number of elements and calls
 * xicro_interfaces__msg__Vector3__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Vector3__Sequence__init(xicro_interfaces__msg__Vector3__Sequence * array, size_t size);

/// Finalize array of msg/Vector3 messages.
/**
 * It calls
 * xicro_interfaces__msg__Vector3__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Vector3__Sequence__fini(xicro_interfaces__msg__Vector3__Sequence * array);

/// Create array of msg/Vector3 messages.
/**
 * It allocates the memory for the array and calls
 * xicro_interfaces__msg__Vector3__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
xicro_interfaces__msg__Vector3__Sequence *
xicro_interfaces__msg__Vector3__Sequence__create(size_t size);

/// Destroy array of msg/Vector3 messages.
/**
 * It calls
 * xicro_interfaces__msg__Vector3__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
void
xicro_interfaces__msg__Vector3__Sequence__destroy(xicro_interfaces__msg__Vector3__Sequence * array);

/// Check for msg/Vector3 message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xicro_interfaces
bool
xicro_interfaces__msg__Vector3__Sequence__are_equal(const xicro_interfaces__msg__Vector3__Sequence * lhs, const xicro_interfaces__msg__Vector3__Sequence * rhs);

/// Copy an array of msg/Vector3 messages.
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
xicro_interfaces__msg__Vector3__Sequence__copy(
  const xicro_interfaces__msg__Vector3__Sequence * input,
  xicro_interfaces__msg__Vector3__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XICRO_INTERFACES__MSG__DETAIL__VECTOR3__FUNCTIONS_H_
