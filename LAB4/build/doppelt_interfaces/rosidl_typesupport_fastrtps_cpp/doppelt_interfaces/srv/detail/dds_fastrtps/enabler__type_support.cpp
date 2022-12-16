// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice
#include "doppelt_interfaces/srv/detail/enabler__rosidl_typesupport_fastrtps_cpp.hpp"
#include "doppelt_interfaces/srv/detail/enabler__struct.hpp"

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

namespace doppelt_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
cdr_serialize(
  const doppelt_interfaces::srv::Enabler_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enable
  cdr << (ros_message.enable ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  doppelt_interfaces::srv::Enabler_Request & ros_message)
{
  // Member: enable
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.enable = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
get_serialized_size(
  const doppelt_interfaces::srv::Enabler_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enable
  {
    size_t item_size = sizeof(ros_message.enable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
max_serialized_size_Enabler_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: enable
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Enabler_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const doppelt_interfaces::srv::Enabler_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Enabler_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<doppelt_interfaces::srv::Enabler_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Enabler_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const doppelt_interfaces::srv::Enabler_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Enabler_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Enabler_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _Enabler_Request__callbacks = {
  "doppelt_interfaces::srv",
  "Enabler_Request",
  _Enabler_Request__cdr_serialize,
  _Enabler_Request__cdr_deserialize,
  _Enabler_Request__get_serialized_size,
  _Enabler_Request__max_serialized_size
};

static rosidl_message_type_support_t _Enabler_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Enabler_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace doppelt_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_doppelt_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<doppelt_interfaces::srv::Enabler_Request>()
{
  return &doppelt_interfaces::srv::typesupport_fastrtps_cpp::_Enabler_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doppelt_interfaces, srv, Enabler_Request)() {
  return &doppelt_interfaces::srv::typesupport_fastrtps_cpp::_Enabler_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace doppelt_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
cdr_serialize(
  const doppelt_interfaces::srv::Enabler_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  doppelt_interfaces::srv::Enabler_Response & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
get_serialized_size(
  const doppelt_interfaces::srv::Enabler_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doppelt_interfaces
max_serialized_size_Enabler_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _Enabler_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const doppelt_interfaces::srv::Enabler_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Enabler_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<doppelt_interfaces::srv::Enabler_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Enabler_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const doppelt_interfaces::srv::Enabler_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Enabler_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Enabler_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _Enabler_Response__callbacks = {
  "doppelt_interfaces::srv",
  "Enabler_Response",
  _Enabler_Response__cdr_serialize,
  _Enabler_Response__cdr_deserialize,
  _Enabler_Response__get_serialized_size,
  _Enabler_Response__max_serialized_size
};

static rosidl_message_type_support_t _Enabler_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Enabler_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace doppelt_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_doppelt_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<doppelt_interfaces::srv::Enabler_Response>()
{
  return &doppelt_interfaces::srv::typesupport_fastrtps_cpp::_Enabler_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doppelt_interfaces, srv, Enabler_Response)() {
  return &doppelt_interfaces::srv::typesupport_fastrtps_cpp::_Enabler_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace doppelt_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _Enabler__callbacks = {
  "doppelt_interfaces::srv",
  "Enabler",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doppelt_interfaces, srv, Enabler_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doppelt_interfaces, srv, Enabler_Response)(),
};

static rosidl_service_type_support_t _Enabler__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Enabler__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace doppelt_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_doppelt_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<doppelt_interfaces::srv::Enabler>()
{
  return &doppelt_interfaces::srv::typesupport_fastrtps_cpp::_Enabler__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doppelt_interfaces, srv, Enabler)() {
  return &doppelt_interfaces::srv::typesupport_fastrtps_cpp::_Enabler__handle;
}

#ifdef __cplusplus
}
#endif
