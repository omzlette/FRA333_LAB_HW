// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "sandevistan_interface/msg/detail/imu_message__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace sandevistan_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IMUMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) sandevistan_interface::msg::IMUMessage(_init);
}

void IMUMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<sandevistan_interface::msg::IMUMessage *>(message_memory);
  typed_message->~IMUMessage();
}

size_t size_function__IMUMessage__linear_acceleration(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__IMUMessage__linear_acceleration(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__IMUMessage__linear_acceleration(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__IMUMessage__angular_velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__IMUMessage__angular_velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__IMUMessage__angular_velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IMUMessage_message_member_array[2] = {
  {
    "linear_acceleration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(sandevistan_interface::msg::IMUMessage, linear_acceleration),  // bytes offset in struct
    nullptr,  // default value
    size_function__IMUMessage__linear_acceleration,  // size() function pointer
    get_const_function__IMUMessage__linear_acceleration,  // get_const(index) function pointer
    get_function__IMUMessage__linear_acceleration,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(sandevistan_interface::msg::IMUMessage, angular_velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__IMUMessage__angular_velocity,  // size() function pointer
    get_const_function__IMUMessage__angular_velocity,  // get_const(index) function pointer
    get_function__IMUMessage__angular_velocity,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IMUMessage_message_members = {
  "sandevistan_interface::msg",  // message namespace
  "IMUMessage",  // message name
  2,  // number of fields
  sizeof(sandevistan_interface::msg::IMUMessage),
  IMUMessage_message_member_array,  // message members
  IMUMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  IMUMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IMUMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IMUMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace sandevistan_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sandevistan_interface::msg::IMUMessage>()
{
  return &::sandevistan_interface::msg::rosidl_typesupport_introspection_cpp::IMUMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sandevistan_interface, msg, IMUMessage)() {
  return &::sandevistan_interface::msg::rosidl_typesupport_introspection_cpp::IMUMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
