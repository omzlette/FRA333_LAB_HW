// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sandevistan_interface:msg/IMUMessage.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__STRUCT_HPP_
#define SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__sandevistan_interface__msg__IMUMessage __attribute__((deprecated))
#else
# define DEPRECATED__sandevistan_interface__msg__IMUMessage __declspec(deprecated)
#endif

namespace sandevistan_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IMUMessage_
{
  using Type = IMUMessage_<ContainerAllocator>;

  explicit IMUMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->linear_acceleration.begin(), this->linear_acceleration.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->angular_velocity.begin(), this->angular_velocity.end(), 0.0);
    }
  }

  explicit IMUMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : linear_acceleration(_alloc),
    angular_velocity(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->linear_acceleration.begin(), this->linear_acceleration.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->angular_velocity.begin(), this->angular_velocity.end(), 0.0);
    }
  }

  // field types and members
  using _linear_acceleration_type =
    std::array<double, 3>;
  _linear_acceleration_type linear_acceleration;
  using _angular_velocity_type =
    std::array<double, 3>;
  _angular_velocity_type angular_velocity;

  // setters for named parameter idiom
  Type & set__linear_acceleration(
    const std::array<double, 3> & _arg)
  {
    this->linear_acceleration = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const std::array<double, 3> & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sandevistan_interface::msg::IMUMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const sandevistan_interface::msg::IMUMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sandevistan_interface::msg::IMUMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sandevistan_interface::msg::IMUMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sandevistan_interface__msg__IMUMessage
    std::shared_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sandevistan_interface__msg__IMUMessage
    std::shared_ptr<sandevistan_interface::msg::IMUMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IMUMessage_ & other) const
  {
    if (this->linear_acceleration != other.linear_acceleration) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const IMUMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IMUMessage_

// alias to use template instance with default allocator
using IMUMessage =
  sandevistan_interface::msg::IMUMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sandevistan_interface

#endif  // SANDEVISTAN_INTERFACE__MSG__DETAIL__IMU_MESSAGE__STRUCT_HPP_
