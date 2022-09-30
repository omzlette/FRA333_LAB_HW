// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sandevistan_kinematics_interfaces:srv/GetPosition.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__GET_POSITION__BUILDER_HPP_
#define SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__GET_POSITION__BUILDER_HPP_

#include "sandevistan_kinematics_interfaces/srv/detail/get_position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace sandevistan_kinematics_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPosition_Request_joint
{
public:
  Init_GetPosition_Request_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sandevistan_kinematics_interfaces::srv::GetPosition_Request joint(::sandevistan_kinematics_interfaces::srv::GetPosition_Request::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::GetPosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sandevistan_kinematics_interfaces::srv::GetPosition_Request>()
{
  return sandevistan_kinematics_interfaces::srv::builder::Init_GetPosition_Request_joint();
}

}  // namespace sandevistan_kinematics_interfaces


namespace sandevistan_kinematics_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetPosition_Response_position
{
public:
  Init_GetPosition_Response_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sandevistan_kinematics_interfaces::srv::GetPosition_Response position(::sandevistan_kinematics_interfaces::srv::GetPosition_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::GetPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sandevistan_kinematics_interfaces::srv::GetPosition_Response>()
{
  return sandevistan_kinematics_interfaces::srv::builder::Init_GetPosition_Response_position();
}

}  // namespace sandevistan_kinematics_interfaces

#endif  // SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__GET_POSITION__BUILDER_HPP_
