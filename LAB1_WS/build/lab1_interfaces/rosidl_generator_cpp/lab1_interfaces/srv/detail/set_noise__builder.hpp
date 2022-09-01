// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab1_interfaces:srv/SetNoise.idl
// generated code does not contain a copyright notice

#ifndef LAB1_INTERFACES__SRV__DETAIL__SET_NOISE__BUILDER_HPP_
#define LAB1_INTERFACES__SRV__DETAIL__SET_NOISE__BUILDER_HPP_

#include "lab1_interfaces/srv/detail/set_noise__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lab1_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab1_interfaces::srv::SetNoise_Request>()
{
  return ::lab1_interfaces::srv::SetNoise_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace lab1_interfaces


namespace lab1_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab1_interfaces::srv::SetNoise_Response>()
{
  return ::lab1_interfaces::srv::SetNoise_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace lab1_interfaces

#endif  // LAB1_INTERFACES__SRV__DETAIL__SET_NOISE__BUILDER_HPP_
