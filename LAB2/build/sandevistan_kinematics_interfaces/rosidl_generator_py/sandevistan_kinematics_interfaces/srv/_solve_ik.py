# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sandevistan_kinematics_interfaces:srv/SolveIK.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SolveIK_Request(type):
    """Metaclass of message 'SolveIK_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sandevistan_kinematics_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sandevistan_kinematics_interfaces.srv.SolveIK_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__solve_ik__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__solve_ik__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__solve_ik__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__solve_ik__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__solve_ik__request

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ARMCONFIG__DEFAULT': 1,
        }

    @property
    def ARMCONFIG__DEFAULT(cls):
        """Return default value for message field 'armconfig'."""
        return 1


class SolveIK_Request(metaclass=Metaclass_SolveIK_Request):
    """Message class 'SolveIK_Request'."""

    __slots__ = [
        '_position',
        '_armconfig',
        '_jointconfig',
    ]

    _fields_and_field_types = {
        'position': 'geometry_msgs/Point',
        'armconfig': 'int32',
        'jointconfig': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.position = kwargs.get('position', Point())
        self.armconfig = kwargs.get(
            'armconfig', SolveIK_Request.ARMCONFIG__DEFAULT)
        self.jointconfig = kwargs.get('jointconfig', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.position != other.position:
            return False
        if self.armconfig != other.armconfig:
            return False
        if self.jointconfig != other.jointconfig:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position' field must be a sub message of type 'Point'"
        self._position = value

    @property
    def armconfig(self):
        """Message field 'armconfig'."""
        return self._armconfig

    @armconfig.setter
    def armconfig(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'armconfig' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'armconfig' field must be an integer in [-2147483648, 2147483647]"
        self._armconfig = value

    @property
    def jointconfig(self):
        """Message field 'jointconfig'."""
        return self._jointconfig

    @jointconfig.setter
    def jointconfig(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'jointconfig' field must be of type 'float'"
        self._jointconfig = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SolveIK_Response(type):
    """Metaclass of message 'SolveIK_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sandevistan_kinematics_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sandevistan_kinematics_interfaces.srv.SolveIK_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__solve_ik__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__solve_ik__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__solve_ik__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__solve_ik__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__solve_ik__response

            from sensor_msgs.msg import JointState
            if JointState.__class__._TYPE_SUPPORT is None:
                JointState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SolveIK_Response(metaclass=Metaclass_SolveIK_Response):
    """Message class 'SolveIK_Response'."""

    __slots__ = [
        '_joint',
        '_success',
    ]

    _fields_and_field_types = {
        'joint': 'sensor_msgs/JointState',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'JointState'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import JointState
        self.joint = kwargs.get('joint', JointState())
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.joint != other.joint:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def joint(self):
        """Message field 'joint'."""
        return self._joint

    @joint.setter
    def joint(self, value):
        if __debug__:
            from sensor_msgs.msg import JointState
            assert \
                isinstance(value, JointState), \
                "The 'joint' field must be a sub message of type 'JointState'"
        self._joint = value

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SolveIK(type):
    """Metaclass of service 'SolveIK'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sandevistan_kinematics_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sandevistan_kinematics_interfaces.srv.SolveIK')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__solve_ik

            from sandevistan_kinematics_interfaces.srv import _solve_ik
            if _solve_ik.Metaclass_SolveIK_Request._TYPE_SUPPORT is None:
                _solve_ik.Metaclass_SolveIK_Request.__import_type_support__()
            if _solve_ik.Metaclass_SolveIK_Response._TYPE_SUPPORT is None:
                _solve_ik.Metaclass_SolveIK_Response.__import_type_support__()


class SolveIK(metaclass=Metaclass_SolveIK):
    from sandevistan_kinematics_interfaces.srv._solve_ik import SolveIK_Request as Request
    from sandevistan_kinematics_interfaces.srv._solve_ik import SolveIK_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
