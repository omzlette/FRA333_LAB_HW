// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice

#ifndef DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__BUILDER_HPP_
#define DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__BUILDER_HPP_

#include "doppelt_interfaces/srv/detail/enabler__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace doppelt_interfaces
{

namespace srv
{

namespace builder
{

class Init_Enabler_Request_enable
{
public:
  Init_Enabler_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doppelt_interfaces::srv::Enabler_Request enable(::doppelt_interfaces::srv::Enabler_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doppelt_interfaces::srv::Enabler_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doppelt_interfaces::srv::Enabler_Request>()
{
  return doppelt_interfaces::srv::builder::Init_Enabler_Request_enable();
}

}  // namespace doppelt_interfaces


namespace doppelt_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doppelt_interfaces::srv::Enabler_Response>()
{
  return ::doppelt_interfaces::srv::Enabler_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doppelt_interfaces

#endif  // DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__BUILDER_HPP_
