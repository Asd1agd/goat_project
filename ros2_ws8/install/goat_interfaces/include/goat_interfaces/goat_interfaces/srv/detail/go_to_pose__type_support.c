// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from goat_interfaces:srv/GoToPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "goat_interfaces/srv/detail/go_to_pose__rosidl_typesupport_introspection_c.h"
#include "goat_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "goat_interfaces/srv/detail/go_to_pose__functions.h"
#include "goat_interfaces/srv/detail/go_to_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  goat_interfaces__srv__GoToPose_Request__init(message_memory);
}

void goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_fini_function(void * message_memory)
{
  goat_interfaces__srv__GoToPose_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(goat_interfaces__srv__GoToPose_Request, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(goat_interfaces__srv__GoToPose_Request, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(goat_interfaces__srv__GoToPose_Request, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_members = {
  "goat_interfaces__srv",  // message namespace
  "GoToPose_Request",  // message name
  3,  // number of fields
  sizeof(goat_interfaces__srv__GoToPose_Request),
  goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_member_array,  // message members
  goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_type_support_handle = {
  0,
  &goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_goat_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose_Request)() {
  if (!goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_type_support_handle.typesupport_identifier) {
    goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &goat_interfaces__srv__GoToPose_Request__rosidl_typesupport_introspection_c__GoToPose_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "goat_interfaces/srv/detail/go_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "goat_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "goat_interfaces/srv/detail/go_to_pose__functions.h"
// already included above
// #include "goat_interfaces/srv/detail/go_to_pose__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  goat_interfaces__srv__GoToPose_Response__init(message_memory);
}

void goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_fini_function(void * message_memory)
{
  goat_interfaces__srv__GoToPose_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(goat_interfaces__srv__GoToPose_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(goat_interfaces__srv__GoToPose_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_members = {
  "goat_interfaces__srv",  // message namespace
  "GoToPose_Response",  // message name
  2,  // number of fields
  sizeof(goat_interfaces__srv__GoToPose_Response),
  goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_member_array,  // message members
  goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_type_support_handle = {
  0,
  &goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_goat_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose_Response)() {
  if (!goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_type_support_handle.typesupport_identifier) {
    goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &goat_interfaces__srv__GoToPose_Response__rosidl_typesupport_introspection_c__GoToPose_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "goat_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "goat_interfaces/srv/detail/go_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_members = {
  "goat_interfaces__srv",  // service namespace
  "GoToPose",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_Request_message_type_support_handle,
  NULL  // response message
  // goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_Response_message_type_support_handle
};

static rosidl_service_type_support_t goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_type_support_handle = {
  0,
  &goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_goat_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose)() {
  if (!goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_type_support_handle.typesupport_identifier) {
    goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, goat_interfaces, srv, GoToPose_Response)()->data;
  }

  return &goat_interfaces__srv__detail__go_to_pose__rosidl_typesupport_introspection_c__GoToPose_service_type_support_handle;
}
