// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice

#ifndef DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__TRAITS_HPP_
#define DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__TRAITS_HPP_

#include "doppelt_interfaces/srv/detail/enabler__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'enable'
#include "std_msgs/msg/detail/bool__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doppelt_interfaces::srv::Enabler_Request>()
{
  return "doppelt_interfaces::srv::Enabler_Request";
}

template<>
inline const char * name<doppelt_interfaces::srv::Enabler_Request>()
{
  return "doppelt_interfaces/srv/Enabler_Request";
}

template<>
struct has_fixed_size<doppelt_interfaces::srv::Enabler_Request>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Bool>::value> {};

template<>
struct has_bounded_size<doppelt_interfaces::srv::Enabler_Request>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Bool>::value> {};

template<>
struct is_message<doppelt_interfaces::srv::Enabler_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doppelt_interfaces::srv::Enabler_Response>()
{
  return "doppelt_interfaces::srv::Enabler_Response";
}

template<>
inline const char * name<doppelt_interfaces::srv::Enabler_Response>()
{
  return "doppelt_interfaces/srv/Enabler_Response";
}

template<>
struct has_fixed_size<doppelt_interfaces::srv::Enabler_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doppelt_interfaces::srv::Enabler_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doppelt_interfaces::srv::Enabler_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doppelt_interfaces::srv::Enabler>()
{
  return "doppelt_interfaces::srv::Enabler";
}

template<>
inline const char * name<doppelt_interfaces::srv::Enabler>()
{
  return "doppelt_interfaces/srv/Enabler";
}

template<>
struct has_fixed_size<doppelt_interfaces::srv::Enabler>
  : std::integral_constant<
    bool,
    has_fixed_size<doppelt_interfaces::srv::Enabler_Request>::value &&
    has_fixed_size<doppelt_interfaces::srv::Enabler_Response>::value
  >
{
};

template<>
struct has_bounded_size<doppelt_interfaces::srv::Enabler>
  : std::integral_constant<
    bool,
    has_bounded_size<doppelt_interfaces::srv::Enabler_Request>::value &&
    has_bounded_size<doppelt_interfaces::srv::Enabler_Response>::value
  >
{
};

template<>
struct is_service<doppelt_interfaces::srv::Enabler>
  : std::true_type
{
};

template<>
struct is_service_request<doppelt_interfaces::srv::Enabler_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doppelt_interfaces::srv::Enabler_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__TRAITS_HPP_
