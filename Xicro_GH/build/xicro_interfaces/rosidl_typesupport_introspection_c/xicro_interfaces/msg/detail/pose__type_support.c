// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xicro_interfaces:msg/Pose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xicro_interfaces/msg/detail/pose__rosidl_typesupport_introspection_c.h"
#include "xicro_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xicro_interfaces/msg/detail/pose__functions.h"
#include "xicro_interfaces/msg/detail/pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Pose__rosidl_typesupport_introspection_c__Pose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xicro_interfaces__msg__Pose__init(message_memory);
}

void Pose__rosidl_typesupport_introspection_c__Pose_fini_function(void * message_memory)
{
  xicro_interfaces__msg__Pose__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Pose__rosidl_typesupport_introspection_c__Pose_message_member_array[2] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xicro_interfaces__msg__Pose, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orientation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(xicro_interfaces__msg__Pose, orientation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Pose__rosidl_typesupport_introspection_c__Pose_message_members = {
  "xicro_interfaces__msg",  // message namespace
  "Pose",  // message name
  2,  // number of fields
  sizeof(xicro_interfaces__msg__Pose),
  Pose__rosidl_typesupport_introspection_c__Pose_message_member_array,  // message members
  Pose__rosidl_typesupport_introspection_c__Pose_init_function,  // function to initialize message memory (memory has to be allocated)
  Pose__rosidl_typesupport_introspection_c__Pose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Pose__rosidl_typesupport_introspection_c__Pose_message_type_support_handle = {
  0,
  &Pose__rosidl_typesupport_introspection_c__Pose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xicro_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xicro_interfaces, msg, Pose)() {
  if (!Pose__rosidl_typesupport_introspection_c__Pose_message_type_support_handle.typesupport_identifier) {
    Pose__rosidl_typesupport_introspection_c__Pose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Pose__rosidl_typesupport_introspection_c__Pose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
