// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sandevistan_kinematics_interfaces:srv/SolveIK.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__TRAITS_HPP_
#define SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__TRAITS_HPP_

#include "sandevistan_kinematics_interfaces/srv/detail/solve_ik__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sandevistan_kinematics_interfaces::srv::SolveIK_Request>()
{
  return "sandevistan_kinematics_interfaces::srv::SolveIK_Request";
}

template<>
inline const char * name<sandevistan_kinematics_interfaces::srv::SolveIK_Request>()
{
  return "sandevistan_kinematics_interfaces/srv/SolveIK_Request";
}

template<>
struct has_fixed_size<sandevistan_kinematics_interfaces::srv::SolveIK_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sandevistan_kinematics_interfaces::srv::SolveIK_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sandevistan_kinematics_interfaces::srv::SolveIK_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sandevistan_kinematics_interfaces::srv::SolveIK_Response>()
{
  return "sandevistan_kinematics_interfaces::srv::SolveIK_Response";
}

template<>
inline const char * name<sandevistan_kinematics_interfaces::srv::SolveIK_Response>()
{
  return "sandevistan_kinematics_interfaces/srv/SolveIK_Response";
}

template<>
struct has_fixed_size<sandevistan_kinematics_interfaces::srv::SolveIK_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sandevistan_kinematics_interfaces::srv::SolveIK_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sandevistan_kinematics_interfaces::srv::SolveIK_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sandevistan_kinematics_interfaces::srv::SolveIK>()
{
  return "sandevistan_kinematics_interfaces::srv::SolveIK";
}

template<>
inline const char * name<sandevistan_kinematics_interfaces::srv::SolveIK>()
{
  return "sandevistan_kinematics_interfaces/srv/SolveIK";
}

template<>
struct has_fixed_size<sandevistan_kinematics_interfaces::srv::SolveIK>
  : std::integral_constant<
    bool,
    has_fixed_size<sandevistan_kinematics_interfaces::srv::SolveIK_Request>::value &&
    has_fixed_size<sandevistan_kinematics_interfaces::srv::SolveIK_Response>::value
  >
{
};

template<>
struct has_bounded_size<sandevistan_kinematics_interfaces::srv::SolveIK>
  : std::integral_constant<
    bool,
    has_bounded_size<sandevistan_kinematics_interfaces::srv::SolveIK_Request>::value &&
    has_bounded_size<sandevistan_kinematics_interfaces::srv::SolveIK_Response>::value
  >
{
};

template<>
struct is_service<sandevistan_kinematics_interfaces::srv::SolveIK>
  : std::true_type
{
};

template<>
struct is_service_request<sandevistan_kinematics_interfaces::srv::SolveIK_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sandevistan_kinematics_interfaces::srv::SolveIK_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__TRAITS_HPP_
