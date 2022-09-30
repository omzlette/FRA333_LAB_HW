// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sandevistan_kinematics_interfaces:srv/SolveIK.idl
// generated code does not contain a copyright notice

#ifndef SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__STRUCT_HPP_
#define SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Request __attribute__((deprecated))
#else
# define DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Request __declspec(deprecated)
#endif

namespace sandevistan_kinematics_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SolveIK_Request_
{
  using Type = SolveIK_Request_<ContainerAllocator>;

  explicit SolveIK_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->armconfig = 0l;
      this->jointconfig = 0.0;
    }
  }

  explicit SolveIK_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->armconfig = 0l;
      this->jointconfig = 0.0;
    }
  }

  // field types and members
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _armconfig_type =
    int32_t;
  _armconfig_type armconfig;
  using _jointconfig_type =
    double;
  _jointconfig_type jointconfig;

  // setters for named parameter idiom
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__armconfig(
    const int32_t & _arg)
  {
    this->armconfig = _arg;
    return *this;
  }
  Type & set__jointconfig(
    const double & _arg)
  {
    this->jointconfig = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Request
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Request
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SolveIK_Request_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->armconfig != other.armconfig) {
      return false;
    }
    if (this->jointconfig != other.jointconfig) {
      return false;
    }
    return true;
  }
  bool operator!=(const SolveIK_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SolveIK_Request_

// alias to use template instance with default allocator
using SolveIK_Request =
  sandevistan_kinematics_interfaces::srv::SolveIK_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sandevistan_kinematics_interfaces


// Include directives for member types
// Member 'joint'
#include "sensor_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Response __attribute__((deprecated))
#else
# define DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Response __declspec(deprecated)
#endif

namespace sandevistan_kinematics_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SolveIK_Response_
{
  using Type = SolveIK_Response_<ContainerAllocator>;

  explicit SolveIK_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SolveIK_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _joint_type =
    sensor_msgs::msg::JointState_<ContainerAllocator>;
  _joint_type joint;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__joint(
    const sensor_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->joint = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Response
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sandevistan_kinematics_interfaces__srv__SolveIK_Response
    std::shared_ptr<sandevistan_kinematics_interfaces::srv::SolveIK_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SolveIK_Response_ & other) const
  {
    if (this->joint != other.joint) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SolveIK_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SolveIK_Response_

// alias to use template instance with default allocator
using SolveIK_Response =
  sandevistan_kinematics_interfaces::srv::SolveIK_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sandevistan_kinematics_interfaces

namespace sandevistan_kinematics_interfaces
{

namespace srv
{

struct SolveIK
{
  using Request = sandevistan_kinematics_interfaces::srv::SolveIK_Request;
  using Response = sandevistan_kinematics_interfaces::srv::SolveIK_Response;
};

}  // namespace srv

}  // namespace sandevistan_kinematics_interfaces

#endif  // SANDEVISTAN_KINEMATICS_INTERFACES__SRV__DETAIL__SOLVE_IK__STRUCT_HPP_
