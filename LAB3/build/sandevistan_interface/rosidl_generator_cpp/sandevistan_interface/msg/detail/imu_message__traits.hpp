// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__TRAITS_HPP_
#define SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__TRAITS_HPP_

#include "sandevistan_interface/msg/detail/imu_message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sandevistan_interface::msg::IMUMessage>()
{
  return "sandevistan_interface::msg::IMUMessage";
}

template<>
inline const char * name<sandevistan_interface::msg::IMUMessage>()
{
  return "sandevistan_interface/msg/IMUMessage";
}

template<>
struct has_fixed_size<sandevistan_interface::msg::IMUMessage>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sandevistan_interface::msg::IMUMessage>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sandevistan_interface::msg::IMUMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__TRAITS_HPP_
