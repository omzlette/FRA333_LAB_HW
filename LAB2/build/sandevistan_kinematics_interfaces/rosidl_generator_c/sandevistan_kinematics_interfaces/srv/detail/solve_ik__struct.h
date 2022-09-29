// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sandevistan_kinematics_interfaces:srv/SolveIK.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__STRUCT_H_
#define SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/SolveIK in the package sandevistan_kinematics_interfaces.
typedef struct sandevistan_kinematics_interfaces__srv__SolveIK_Request
{
  uint8_t structure_needs_at_least_one_member;
} sandevistan_kinematics_interfaces__srv__SolveIK_Request;

// Struct for a sequence of sandevistan_kinematics_interfaces__srv__SolveIK_Request.
typedef struct sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence
{
  sandevistan_kinematics_interfaces__srv__SolveIK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sandevistan_kinematics_interfaces__srv__SolveIK_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SolveIK in the package sandevistan_kinematics_interfaces.
typedef struct sandevistan_kinematics_interfaces__srv__SolveIK_Response
{
  uint8_t structure_needs_at_least_one_member;
} sandevistan_kinematics_interfaces__srv__SolveIK_Response;

// Struct for a sequence of sandevistan_kinematics_interfaces__srv__SolveIK_Response.
typedef struct sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence
{
  sandevistan_kinematics_interfaces__srv__SolveIK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sandevistan_kinematics_interfaces__srv__SolveIK_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__STRUCT_H_
