// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__BUILDER_HPP_
#define SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__BUILDER_HPP_

#include "sandevistan_interface/msg/detail/imu_message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace sandevistan_interface
{

namespace msg
{

namespace builder
{

class Init_IMUMessage_angular_velocity
{
public:
  explicit Init_IMUMessage_angular_velocity(::sandevistan_interface::msg::IMUMessage & msg)
  : msg_(msg)
  {}
  ::sandevistan_interface::msg::IMUMessage angular_velocity(::sandevistan_interface::msg::IMUMessage::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sandevistan_interface::msg::IMUMessage msg_;
};

class Init_IMUMessage_linear_acceleration
{
public:
  Init_IMUMessage_linear_acceleration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUMessage_angular_velocity linear_acceleration(::sandevistan_interface::msg::IMUMessage::_linear_acceleration_type arg)
  {
    msg_.linear_acceleration = std::move(arg);
    return Init_IMUMessage_angular_velocity(msg_);
  }

private:
  ::sandevistan_interface::msg::IMUMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sandevistan_interface::msg::IMUMessage>()
{
  return sandevistan_interface::msg::builder::Init_IMUMessage_linear_acceleration();
}

}  // namespace sandevistan_interface

#endif  // SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__BUILDER_HPP_
