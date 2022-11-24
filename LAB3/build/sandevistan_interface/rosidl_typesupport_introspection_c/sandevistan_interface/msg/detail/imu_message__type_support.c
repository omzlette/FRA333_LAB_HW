// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sandevistan_interface/msg/detail/imu_message__rosidl_typesupport_introspection_c.h"
#include "sandevistan_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sandevistan_interface/msg/detail/imu_message__functions.h"
#include "sandevistan_interface/msg/detail/imu_message__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sandevistan_interface__msg__IMUMessage__init(message_memory);
}

void IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_fini_function(void * message_memory)
{
  sandevistan_interface__msg__IMUMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_member_array[2] = {
  {
    "linear_acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(sandevistan_interface__msg__IMUMessage, linear_acceleration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(sandevistan_interface__msg__IMUMessage, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_members = {
  "sandevistan_interface__msg",  // message namespace
  "IMUMessage",  // message name
  2,  // number of fields
  sizeof(sandevistan_interface__msg__IMUMessage),
  IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_member_array,  // message members
  IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_type_support_handle = {
  0,
  &IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sandevistan_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sandevistan_interface, msg, IMUMessage)() {
  if (!IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_type_support_handle.typesupport_identifier) {
    IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &IMUMessage__rosidl_typesupport_introspection_c__IMUMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
