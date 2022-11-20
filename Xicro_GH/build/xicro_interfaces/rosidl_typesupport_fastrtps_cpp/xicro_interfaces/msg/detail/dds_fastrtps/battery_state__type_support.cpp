// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xicro_interfaces:msg/BatteryState.idl
// generated code does not contain a copyright notice
#include "xicro_interfaces/msg/detail/battery_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xicro_interfaces/msg/detail/battery_state__struct.hpp"

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
  const xicro_interfaces::msg::BatteryState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: voltage
  cdr << ros_message.voltage;
  // Member: temperature
  cdr << ros_message.temperature;
  // Member: current
  cdr << ros_message.current;
  // Member: charge
  cdr << ros_message.charge;
  // Member: capacity
  cdr << ros_message.capacity;
  // Member: design_capacity
  cdr << ros_message.design_capacity;
  // Member: percentage
  cdr << ros_message.percentage;
  // Member: power_supply_status
  cdr << ros_message.power_supply_status;
  // Member: power_supply_health
  cdr << ros_message.power_supply_health;
  // Member: power_supply_technology
  cdr << ros_message.power_supply_technology;
  // Member: present
  cdr << (ros_message.present ? true : false);
  // Member: cell_voltage
  {
    cdr << ros_message.cell_voltage;
  }
  // Member: cell_temperature
  {
    cdr << ros_message.cell_temperature;
  }
  // Member: location
  cdr << ros_message.location;
  // Member: serial_number
  cdr << ros_message.serial_number;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xicro_interfaces::msg::BatteryState & ros_message)
{
  // Member: voltage
  cdr >> ros_message.voltage;

  // Member: temperature
  cdr >> ros_message.temperature;

  // Member: current
  cdr >> ros_message.current;

  // Member: charge
  cdr >> ros_message.charge;

  // Member: capacity
  cdr >> ros_message.capacity;

  // Member: design_capacity
  cdr >> ros_message.design_capacity;

  // Member: percentage
  cdr >> ros_message.percentage;

  // Member: power_supply_status
  cdr >> ros_message.power_supply_status;

  // Member: power_supply_health
  cdr >> ros_message.power_supply_health;

  // Member: power_supply_technology
  cdr >> ros_message.power_supply_technology;

  // Member: present
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.present = tmp ? true : false;
  }

  // Member: cell_voltage
  {
    cdr >> ros_message.cell_voltage;
  }

  // Member: cell_temperature
  {
    cdr >> ros_message.cell_temperature;
  }

  // Member: location
  cdr >> ros_message.location;

  // Member: serial_number
  cdr >> ros_message.serial_number;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
get_serialized_size(
  const xicro_interfaces::msg::BatteryState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: voltage
  {
    size_t item_size = sizeof(ros_message.voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature
  {
    size_t item_size = sizeof(ros_message.temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current
  {
    size_t item_size = sizeof(ros_message.current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: charge
  {
    size_t item_size = sizeof(ros_message.charge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: capacity
  {
    size_t item_size = sizeof(ros_message.capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: design_capacity
  {
    size_t item_size = sizeof(ros_message.design_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: percentage
  {
    size_t item_size = sizeof(ros_message.percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: power_supply_status
  {
    size_t item_size = sizeof(ros_message.power_supply_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: power_supply_health
  {
    size_t item_size = sizeof(ros_message.power_supply_health);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: power_supply_technology
  {
    size_t item_size = sizeof(ros_message.power_supply_technology);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: present
  {
    size_t item_size = sizeof(ros_message.present);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cell_voltage
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.cell_voltage[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cell_temperature
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.cell_temperature[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: location
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.location.size() + 1);
  // Member: serial_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.serial_number.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xicro_interfaces
max_serialized_size_BatteryState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: voltage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temperature
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: charge
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: capacity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: design_capacity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: percentage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: power_supply_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: power_supply_health
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: power_supply_technology
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: present
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cell_voltage
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: cell_temperature
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: location
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: serial_number
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _BatteryState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xicro_interfaces::msg::BatteryState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BatteryState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xicro_interfaces::msg::BatteryState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BatteryState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xicro_interfaces::msg::BatteryState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BatteryState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_BatteryState(full_bounded, 0);
}

static message_type_support_callbacks_t _BatteryState__callbacks = {
  "xicro_interfaces::msg",
  "BatteryState",
  _BatteryState__cdr_serialize,
  _BatteryState__cdr_deserialize,
  _BatteryState__get_serialized_size,
  _BatteryState__max_serialized_size
};

static rosidl_message_type_support_t _BatteryState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BatteryState__callbacks,
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
get_message_type_support_handle<xicro_interfaces::msg::BatteryState>()
{
  return &xicro_interfaces::msg::typesupport_fastrtps_cpp::_BatteryState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xicro_interfaces, msg, BatteryState)() {
  return &xicro_interfaces::msg::typesupport_fastrtps_cpp::_BatteryState__handle;
}

#ifdef __cplusplus
}
#endif
