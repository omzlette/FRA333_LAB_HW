// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from xicro_interfaces:msg/Twist.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "xicro_interfaces/msg/detail/twist__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace xicro_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Twist_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) xicro_interfaces::msg::Twist(_init);
}

void Twist_fini_function(void * message_memory)
{
  auto typed_message = static_cast<xicro_interfaces::msg::Twist *>(message_memory);
  typed_message->~Twist();
}

size_t size_function__Twist__linear(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__Twist__linear(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__Twist__linear(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__Twist__angular(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__Twist__angular(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__Twist__angular(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Twist_message_member_array[2] = {
  {
    "linear",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xicro_interfaces::msg::Twist, linear),  // bytes offset in struct
    nullptr,  // default value
    size_function__Twist__linear,  // size() function pointer
    get_const_function__Twist__linear,  // get_const(index) function pointer
    get_function__Twist__linear,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "angular",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(xicro_interfaces::msg::Twist, angular),  // bytes offset in struct
    nullptr,  // default value
    size_function__Twist__angular,  // size() function pointer
    get_const_function__Twist__angular,  // get_const(index) function pointer
    get_function__Twist__angular,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Twist_message_members = {
  "xicro_interfaces::msg",  // message namespace
  "Twist",  // message name
  2,  // number of fields
  sizeof(xicro_interfaces::msg::Twist),
  Twist_message_member_array,  // message members
  Twist_init_function,  // function to initialize message memory (memory has to be allocated)
  Twist_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Twist_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Twist_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace xicro_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<xicro_interfaces::msg::Twist>()
{
  return &::xicro_interfaces::msg::rosidl_typesupport_introspection_cpp::Twist_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, xicro_interfaces, msg, Twist)() {
  return &::xicro_interfaces::msg::rosidl_typesupport_introspection_cpp::Twist_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
