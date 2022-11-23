// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xicro_interfaces:msg/DemoInput.idl
// generated code does not contain a copyright notice
#include "xicro_interfaces/msg/detail/demo_input__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xicro_interfaces/msg/detail/demo_input__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace xicro_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
cdr_serialize(
  const xicro_interfaces::msg::DemoInput & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: buttonstate
  {
    cdr << ros_message.buttonstate;
  }
  // Member: poten
  cdr << ros_message.poten;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xicro_interfaces::msg::DemoInput & ros_message)
{
  // Member: buttonstate
  {
    cdr >> ros_message.buttonstate;
  }

  // Member: poten
  cdr >> ros_message.poten;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
get_serialized_size(
  const xicro_interfaces::msg::DemoInput & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: buttonstate
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.buttonstate[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: poten
  {
    size_t item_size = sizeof(ros_message.poten);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
max_serialized_size_DemoInput(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: buttonstate
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: poten
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _DemoInput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xicro_interfaces::msg::DemoInput *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DemoInput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xicro_interfaces::msg::DemoInput *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DemoInput__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xicro_interfaces::msg::DemoInput *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DemoInput__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_DemoInput(full_bounded, 0);
}

static message_type_support_callbacks_t _DemoInput__callbacks = {
  "xicro_interfaces::msg",
  "DemoInput",
  _DemoInput__cdr_serialize,
  _DemoInput__cdr_deserialize,
  _DemoInput__get_serialized_size,
  _DemoInput__max_serialized_size
};

static rosidl_message_type_support_t _DemoInput__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DemoInput__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xicro_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xicro_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<xicro_interfaces::msg::DemoInput>()
{
  return &xicro_interfaces::msg::typesupport_fastrtps_cpp::_DemoInput__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xicro_interfaces, msg, DemoInput)() {
  return &xicro_interfaces::msg::typesupport_fastrtps_cpp::_DemoInput__handle;
}

#ifdef __cplusplus
}
#endif
