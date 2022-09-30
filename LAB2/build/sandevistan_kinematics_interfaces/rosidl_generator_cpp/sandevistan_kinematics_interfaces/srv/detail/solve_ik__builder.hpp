// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sandevistan_kinematics_interfaces:srv/SolveIK.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__BUILDER_HPP_
#define SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__BUILDER_HPP_

#include "sandevistan_kinematics_interfaces/srv/detail/solve_ik__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace sandevistan_kinematics_interfaces
{

namespace srv
{

namespace builder
{

class Init_SolveIK_Request_jointconfig
{
public:
  explicit Init_SolveIK_Request_jointconfig(::sandevistan_kinematics_interfaces::srv::SolveIK_Request & msg)
  : msg_(msg)
  {}
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Request jointconfig(::sandevistan_kinematics_interfaces::srv::SolveIK_Request::_jointconfig_type arg)
  {
    msg_.jointconfig = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Request msg_;
};

class Init_SolveIK_Request_armconfig
{
public:
  explicit Init_SolveIK_Request_armconfig(::sandevistan_kinematics_interfaces::srv::SolveIK_Request & msg)
  : msg_(msg)
  {}
  Init_SolveIK_Request_jointconfig armconfig(::sandevistan_kinematics_interfaces::srv::SolveIK_Request::_armconfig_type arg)
  {
    msg_.armconfig = std::move(arg);
    return Init_SolveIK_Request_jointconfig(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Request msg_;
};

class Init_SolveIK_Request_position
{
public:
  Init_SolveIK_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SolveIK_Request_armconfig position(::sandevistan_kinematics_interfaces::srv::SolveIK_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_SolveIK_Request_armconfig(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sandevistan_kinematics_interfaces::srv::SolveIK_Request>()
{
  return sandevistan_kinematics_interfaces::srv::builder::Init_SolveIK_Request_position();
}

}  // namespace sandevistan_kinematics_interfaces


namespace sandevistan_kinematics_interfaces
{

namespace srv
{

namespace builder
{

class Init_SolveIK_Response_success
{
public:
  explicit Init_SolveIK_Response_success(::sandevistan_kinematics_interfaces::srv::SolveIK_Response & msg)
  : msg_(msg)
  {}
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Response success(::sandevistan_kinematics_interfaces::srv::SolveIK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Response msg_;
};

class Init_SolveIK_Response_joint
{
public:
  Init_SolveIK_Response_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SolveIK_Response_success joint(::sandevistan_kinematics_interfaces::srv::SolveIK_Response::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_SolveIK_Response_success(msg_);
  }

private:
  ::sandevistan_kinematics_interfaces::srv::SolveIK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sandevistan_kinematics_interfaces::srv::SolveIK_Response>()
{
  return sandevistan_kinematics_interfaces::srv::builder::Init_SolveIK_Response_joint();
}

}  // namespace sandevistan_kinematics_interfaces

#endif  // SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__BUILDER_HPP_
