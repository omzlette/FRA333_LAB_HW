// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doppelt_interfaces:srv/Enabler.idl
// generated code does not contain a copyright notice

#ifndef DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__STRUCT_HPP_
#define DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'enable'
#include "std_msgs/msg/detail/bool__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__doppelt_interfaces__srv__Enabler_Request __attribute__((deprecated))
#else
# define DEPRECATED__doppelt_interfaces__srv__Enabler_Request __declspec(deprecated)
#endif

namespace doppelt_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Enabler_Request_
{
  using Type = Enabler_Request_<ContainerAllocator>;

  explicit Enabler_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : enable(_init)
  {
    (void)_init;
  }

  explicit Enabler_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : enable(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _enable_type =
    std_msgs::msg::Bool_<ContainerAllocator>;
  _enable_type enable;

  // setters for named parameter idiom
  Type & set__enable(
    const std_msgs::msg::Bool_<ContainerAllocator> & _arg)
  {
    this->enable = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doppelt_interfaces__srv__Enabler_Request
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doppelt_interfaces__srv__Enabler_Request
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Enabler_Request_ & other) const
  {
    if (this->enable != other.enable) {
      return false;
    }
    return true;
  }
  bool operator!=(const Enabler_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Enabler_Request_

// alias to use template instance with default allocator
using Enabler_Request =
  doppelt_interfaces::srv::Enabler_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doppelt_interfaces


#ifndef _WIN32
# define DEPRECATED__doppelt_interfaces__srv__Enabler_Response __attribute__((deprecated))
#else
# define DEPRECATED__doppelt_interfaces__srv__Enabler_Response __declspec(deprecated)
#endif

namespace doppelt_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Enabler_Response_
{
  using Type = Enabler_Response_<ContainerAllocator>;

  explicit Enabler_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Enabler_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doppelt_interfaces__srv__Enabler_Response
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doppelt_interfaces__srv__Enabler_Response
    std::shared_ptr<doppelt_interfaces::srv::Enabler_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Enabler_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Enabler_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Enabler_Response_

// alias to use template instance with default allocator
using Enabler_Response =
  doppelt_interfaces::srv::Enabler_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doppelt_interfaces

namespace doppelt_interfaces
{

namespace srv
{

struct Enabler
{
  using Request = doppelt_interfaces::srv::Enabler_Request;
  using Response = doppelt_interfaces::srv::Enabler_Response;
};

}  // namespace srv

}  // namespace doppelt_interfaces

#endif  // DOPPELT_INTERFACES__SRV__DETAIL__ENABLER__STRUCT_HPP_
