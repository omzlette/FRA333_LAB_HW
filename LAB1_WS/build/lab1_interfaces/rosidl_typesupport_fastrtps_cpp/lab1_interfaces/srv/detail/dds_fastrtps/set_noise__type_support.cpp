// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from lab1_interfaces:srv/SetNoise.idl
// generated code does not contain a copyright notice
#include "lab1_interfaces/srv/detail/set_noise__rosidl_typesupport_fastrtps_cpp.hpp"
#include "lab1_interfaces/srv/detail/set_noise__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Float64 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Float64 &);
size_t get_serialized_size(
  const std_msgs::msg::Float64 &,
  size_t current_alignment);
size_t
max_serialized_size_Float64(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Float64 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Float64 &);
size_t get_serialized_size(
  const std_msgs::msg::Float64 &,
  size_t current_alignment);
size_t
max_serialized_size_Float64(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace lab1_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
cdr_serialize(
  const lab1_interfaces::srv::SetNoise_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mean
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.mean,
    cdr);
  // Member: variance
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.variance,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lab1_interfaces::srv::SetNoise_Request & ros_message)
{
  // Member: mean
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.mean);

  // Member: variance
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.variance);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
get_serialized_size(
  const lab1_interfaces::srv::SetNoise_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mean

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.mean, current_alignment);
  // Member: variance

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.variance, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
max_serialized_size_SetNoise_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: mean
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Float64(
        full_bounded, current_alignment);
    }
  }

  // Member: variance
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Float64(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _SetNoise_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lab1_interfaces::srv::SetNoise_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetNoise_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lab1_interfaces::srv::SetNoise_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetNoise_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lab1_interfaces::srv::SetNoise_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetNoise_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SetNoise_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _SetNoise_Request__callbacks = {
  "lab1_interfaces::srv",
  "SetNoise_Request",
  _SetNoise_Request__cdr_serialize,
  _SetNoise_Request__cdr_deserialize,
  _SetNoise_Request__get_serialized_size,
  _SetNoise_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetNoise_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetNoise_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace lab1_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lab1_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<lab1_interfaces::srv::SetNoise_Request>()
{
  return &lab1_interfaces::srv::typesupport_fastrtps_cpp::_SetNoise_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab1_interfaces, srv, SetNoise_Request)() {
  return &lab1_interfaces::srv::typesupport_fastrtps_cpp::_SetNoise_Request__handle;
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

namespace lab1_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
cdr_serialize(
  const lab1_interfaces::srv::SetNoise_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lab1_interfaces::srv::SetNoise_Response & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
get_serialized_size(
  const lab1_interfaces::srv::SetNoise_Response & ros_message,
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
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab1_interfaces
max_serialized_size_SetNoise_Response(
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

static bool _SetNoise_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lab1_interfaces::srv::SetNoise_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetNoise_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lab1_interfaces::srv::SetNoise_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetNoise_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lab1_interfaces::srv::SetNoise_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetNoise_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SetNoise_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _SetNoise_Response__callbacks = {
  "lab1_interfaces::srv",
  "SetNoise_Response",
  _SetNoise_Response__cdr_serialize,
  _SetNoise_Response__cdr_deserialize,
  _SetNoise_Response__get_serialized_size,
  _SetNoise_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetNoise_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetNoise_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace lab1_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lab1_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<lab1_interfaces::srv::SetNoise_Response>()
{
  return &lab1_interfaces::srv::typesupport_fastrtps_cpp::_SetNoise_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab1_interfaces, srv, SetNoise_Response)() {
  return &lab1_interfaces::srv::typesupport_fastrtps_cpp::_SetNoise_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace lab1_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SetNoise__callbacks = {
  "lab1_interfaces::srv",
  "SetNoise",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab1_interfaces, srv, SetNoise_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab1_interfaces, srv, SetNoise_Response)(),
};

static rosidl_service_type_support_t _SetNoise__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetNoise__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace lab1_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lab1_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<lab1_interfaces::srv::SetNoise>()
{
  return &lab1_interfaces::srv::typesupport_fastrtps_cpp::_SetNoise__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab1_interfaces, srv, SetNoise)() {
  return &lab1_interfaces::srv::typesupport_fastrtps_cpp::_SetNoise__handle;
}

#ifdef __cplusplus
}
#endif
