// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sandevistan_kinematics_interfaces:srv/SolveIK.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__FUNCTIONS_H_
#define SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sandevistan_kinematics_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "sandevistan_kinematics_interfaces/srv/detail/solve_ik__struct.h"

/// Initialize srv/SolveIK message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request
 * )) before or use
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Request__init(sandevistan_kinematics_interfaces__srv__SolveIK_Request * msg);

/// Finalize srv/SolveIK message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Request__fini(sandevistan_kinematics_interfaces__srv__SolveIK_Request * msg);

/// Create srv/SolveIK message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
sandevistan_kinematics_interfaces__srv__SolveIK_Request *
sandevistan_kinematics_interfaces__srv__SolveIK_Request__create();

/// Destroy srv/SolveIK message.
/**
 * It calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Request__destroy(sandevistan_kinematics_interfaces__srv__SolveIK_Request * msg);

/// Check for srv/SolveIK message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Request__are_equal(const sandevistan_kinematics_interfaces__srv__SolveIK_Request * lhs, const sandevistan_kinematics_interfaces__srv__SolveIK_Request * rhs);

/// Copy a srv/SolveIK message.
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
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Request__copy(
  const sandevistan_kinematics_interfaces__srv__SolveIK_Request * input,
  sandevistan_kinematics_interfaces__srv__SolveIK_Request * output);

/// Initialize array of srv/SolveIK messages.
/**
 * It allocates the memory for the number of elements and calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__init(sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * array, size_t size);

/// Finalize array of srv/SolveIK messages.
/**
 * It calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__fini(sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * array);

/// Create array of srv/SolveIK messages.
/**
 * It allocates the memory for the array and calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence *
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__create(size_t size);

/// Destroy array of srv/SolveIK messages.
/**
 * It calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__destroy(sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * array);

/// Check for srv/SolveIK message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__are_equal(const sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * lhs, const sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * rhs);

/// Copy an array of srv/SolveIK messages.
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
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence__copy(
  const sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * input,
  sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence * output);

/// Initialize srv/SolveIK message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response
 * )) before or use
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Response__init(sandevistan_kinematics_interfaces__srv__SolveIK_Response * msg);

/// Finalize srv/SolveIK message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Response__fini(sandevistan_kinematics_interfaces__srv__SolveIK_Response * msg);

/// Create srv/SolveIK message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
sandevistan_kinematics_interfaces__srv__SolveIK_Response *
sandevistan_kinematics_interfaces__srv__SolveIK_Response__create();

/// Destroy srv/SolveIK message.
/**
 * It calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Response__destroy(sandevistan_kinematics_interfaces__srv__SolveIK_Response * msg);

/// Check for srv/SolveIK message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Response__are_equal(const sandevistan_kinematics_interfaces__srv__SolveIK_Response * lhs, const sandevistan_kinematics_interfaces__srv__SolveIK_Response * rhs);

/// Copy a srv/SolveIK message.
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
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Response__copy(
  const sandevistan_kinematics_interfaces__srv__SolveIK_Response * input,
  sandevistan_kinematics_interfaces__srv__SolveIK_Response * output);

/// Initialize array of srv/SolveIK messages.
/**
 * It allocates the memory for the number of elements and calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__init(sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * array, size_t size);

/// Finalize array of srv/SolveIK messages.
/**
 * It calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__fini(sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * array);

/// Create array of srv/SolveIK messages.
/**
 * It allocates the memory for the array and calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence *
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__create(size_t size);

/// Destroy array of srv/SolveIK messages.
/**
 * It calls
 * sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
void
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__destroy(sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * array);

/// Check for srv/SolveIK message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__are_equal(const sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * lhs, const sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * rhs);

/// Copy an array of srv/SolveIK messages.
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
ROSIDL_GENERATOR_C_PUBLIC_sandevistan_kinematics_interfaces
bool
sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence__copy(
  const sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * input,
  sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__FUNCTIONS_H_
