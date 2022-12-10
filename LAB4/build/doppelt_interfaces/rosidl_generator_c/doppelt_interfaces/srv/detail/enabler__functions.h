// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice

#ifndef DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__FUNCTIONS_H_
#define DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "doppelt_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "doppelt_interfaces/srv/detail/enabler__struct.h"

/// Initialize srv/Enabler message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * doppelt_interfaces__srv__Enabler_Request
 * )) before or use
 * doppelt_interfaces__srv__Enabler_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Request__init(doppelt_interfaces__srv__Enabler_Request * msg);

/// Finalize srv/Enabler message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Request__fini(doppelt_interfaces__srv__Enabler_Request * msg);

/// Create srv/Enabler message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * doppelt_interfaces__srv__Enabler_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
doppelt_interfaces__srv__Enabler_Request *
doppelt_interfaces__srv__Enabler_Request__create();

/// Destroy srv/Enabler message.
/**
 * It calls
 * doppelt_interfaces__srv__Enabler_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Request__destroy(doppelt_interfaces__srv__Enabler_Request * msg);

/// Check for srv/Enabler message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Request__are_equal(const doppelt_interfaces__srv__Enabler_Request * lhs, const doppelt_interfaces__srv__Enabler_Request * rhs);

/// Copy a srv/Enabler message.
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
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Request__copy(
  const doppelt_interfaces__srv__Enabler_Request * input,
  doppelt_interfaces__srv__Enabler_Request * output);

/// Initialize array of srv/Enabler messages.
/**
 * It allocates the memory for the number of elements and calls
 * doppelt_interfaces__srv__Enabler_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Request__Sequence__init(doppelt_interfaces__srv__Enabler_Request__Sequence * array, size_t size);

/// Finalize array of srv/Enabler messages.
/**
 * It calls
 * doppelt_interfaces__srv__Enabler_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Request__Sequence__fini(doppelt_interfaces__srv__Enabler_Request__Sequence * array);

/// Create array of srv/Enabler messages.
/**
 * It allocates the memory for the array and calls
 * doppelt_interfaces__srv__Enabler_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
doppelt_interfaces__srv__Enabler_Request__Sequence *
doppelt_interfaces__srv__Enabler_Request__Sequence__create(size_t size);

/// Destroy array of srv/Enabler messages.
/**
 * It calls
 * doppelt_interfaces__srv__Enabler_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Request__Sequence__destroy(doppelt_interfaces__srv__Enabler_Request__Sequence * array);

/// Check for srv/Enabler message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Request__Sequence__are_equal(const doppelt_interfaces__srv__Enabler_Request__Sequence * lhs, const doppelt_interfaces__srv__Enabler_Request__Sequence * rhs);

/// Copy an array of srv/Enabler messages.
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
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Request__Sequence__copy(
  const doppelt_interfaces__srv__Enabler_Request__Sequence * input,
  doppelt_interfaces__srv__Enabler_Request__Sequence * output);

/// Initialize srv/Enabler message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * doppelt_interfaces__srv__Enabler_Response
 * )) before or use
 * doppelt_interfaces__srv__Enabler_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Response__init(doppelt_interfaces__srv__Enabler_Response * msg);

/// Finalize srv/Enabler message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Response__fini(doppelt_interfaces__srv__Enabler_Response * msg);

/// Create srv/Enabler message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * doppelt_interfaces__srv__Enabler_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
doppelt_interfaces__srv__Enabler_Response *
doppelt_interfaces__srv__Enabler_Response__create();

/// Destroy srv/Enabler message.
/**
 * It calls
 * doppelt_interfaces__srv__Enabler_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Response__destroy(doppelt_interfaces__srv__Enabler_Response * msg);

/// Check for srv/Enabler message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Response__are_equal(const doppelt_interfaces__srv__Enabler_Response * lhs, const doppelt_interfaces__srv__Enabler_Response * rhs);

/// Copy a srv/Enabler message.
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
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Response__copy(
  const doppelt_interfaces__srv__Enabler_Response * input,
  doppelt_interfaces__srv__Enabler_Response * output);

/// Initialize array of srv/Enabler messages.
/**
 * It allocates the memory for the number of elements and calls
 * doppelt_interfaces__srv__Enabler_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Response__Sequence__init(doppelt_interfaces__srv__Enabler_Response__Sequence * array, size_t size);

/// Finalize array of srv/Enabler messages.
/**
 * It calls
 * doppelt_interfaces__srv__Enabler_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Response__Sequence__fini(doppelt_interfaces__srv__Enabler_Response__Sequence * array);

/// Create array of srv/Enabler messages.
/**
 * It allocates the memory for the array and calls
 * doppelt_interfaces__srv__Enabler_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
doppelt_interfaces__srv__Enabler_Response__Sequence *
doppelt_interfaces__srv__Enabler_Response__Sequence__create(size_t size);

/// Destroy array of srv/Enabler messages.
/**
 * It calls
 * doppelt_interfaces__srv__Enabler_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
void
doppelt_interfaces__srv__Enabler_Response__Sequence__destroy(doppelt_interfaces__srv__Enabler_Response__Sequence * array);

/// Check for srv/Enabler message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Response__Sequence__are_equal(const doppelt_interfaces__srv__Enabler_Response__Sequence * lhs, const doppelt_interfaces__srv__Enabler_Response__Sequence * rhs);

/// Copy an array of srv/Enabler messages.
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
ROSIDL_GENERATOR_C_PUBLIC_doppelt_interfaces
bool
doppelt_interfaces__srv__Enabler_Response__Sequence__copy(
  const doppelt_interfaces__srv__Enabler_Response__Sequence * input,
  doppelt_interfaces__srv__Enabler_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__FUNCTIONS_H_
