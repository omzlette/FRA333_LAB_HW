// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xicro_interfaces:msg/Twist.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xicro_interfaces/msg/detail/twist__rosidl_typesupport_introspection_c.h"
#include "xicro_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xicro_interfaces/msg/detail/twist__functions.h"
#include "xicro_interfaces/msg/detail/twist__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Twist__rosidl_typesupport_introspection_c__Twist_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xicro_interfaces__msg__Twist__init(message_memory);
}

void Twist__rosidl_typesupport_introspection_c__Twist_fini_function(void * message_memory)
{
  xicro_interfaces__msg__Twist__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Twist__rosidl_typesupport_introspection_c__Twist_message_member_array[2] = {
  {
    "linear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xicro_interfaces__msg__Twist, linear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xicro_interfaces__msg__Twist, angular),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Twist__rosidl_typesupport_introspection_c__Twist_message_members = {
  "xicro_interfaces__msg",  // message namespace
  "Twist",  // message name
  2,  // number of fields
  sizeof(xicro_interfaces__msg__Twist),
  Twist__rosidl_typesupport_introspection_c__Twist_message_member_array,  // message members
  Twist__rosidl_typesupport_introspection_c__Twist_init_function,  // function to initialize message memory (memory has to be allocated)
  Twist__rosidl_typesupport_introspection_c__Twist_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Twist__rosidl_typesupport_introspection_c__Twist_message_type_support_handle = {
  0,
  &Twist__rosidl_typesupport_introspection_c__Twist_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xicro_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xicro_interfaces, msg, Twist)() {
  if (!Twist__rosidl_typesupport_introspection_c__Twist_message_type_support_handle.typesupport_identifier) {
    Twist__rosidl_typesupport_introspection_c__Twist_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Twist__rosidl_typesupport_introspection_c__Twist_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif