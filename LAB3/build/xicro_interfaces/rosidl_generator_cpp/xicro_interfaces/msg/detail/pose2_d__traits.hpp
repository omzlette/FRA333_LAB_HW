// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xicro_interfaces:msg/Pose2D.idl
// generated code does not contain a copyright notice

#ifndef XICRO_INTERFACES__MSG__DETAIL__POSE2_D__TRAITS_HPP_
#define XICRO_INTERFACES__MSG__DETAIL__POSE2_D__TRAITS_HPP_

#include "xicro_interfaces/msg/detail/pose2_d__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xicro_interfaces::msg::Pose2D>()
{
  return "xicro_interfaces::msg::Pose2D";
}

template<>
inline const char * name<xicro_interfaces::msg::Pose2D>()
{
  return "xicro_interfaces/msg/Pose2D";
}

template<>
struct has_fixed_size<xicro_interfaces::msg::Pose2D>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xicro_interfaces::msg::Pose2D>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xicro_interfaces::msg::Pose2D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XICRO_INTERFACES__MSG__DETAIL__POSE2_D__TRAITS_HPP_
