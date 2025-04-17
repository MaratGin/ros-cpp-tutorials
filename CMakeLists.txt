cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

## Specify the package's name here.
## It should match with the content of <name> tag in package.xml.
project(catkin_package_template)

## Compile as C++17, supported in ROS Kinetic and newer.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find catkin macros and libraries.
## If COMPONENTS list such as find_package(catkin REQUIRED COMPONENTS xyz) is used,
## also find other catkin packages (i.e. populate catkin_* variables).
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  roslib
  std_msgs
)

## System dependencies can be found with CMake's conventions.
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py.
## This macro ensures modules and global scripts declared therein get installed.
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html.
# catkin_python_setup()

## Declare ROS messages, services and actions.
##
## To declare and build messages, services or actions from within this package, follow these steps:
##
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
##
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * if MSG_DEP_SET isn't empty the following dependency has been pulled in,
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
##
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder.
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder.
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder.
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here.
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

## Declare ROS dynamic reconfigure parameters.
##
## To declare and build dynamic reconfigure parameters within this package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder.
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

## catkin specific configuration.
##
## The catkin_package macro generates cmake config files for your package.
## Declare things to be passed to dependent projects:
##  INCLUDE_DIRS: header files directory
##  LIBRARIES: libraries you create in this project
##  CATKIN_DEPENDS: catkin packages
##  DEPENDS: system dependencies of this project
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rospy roslib std_msgs
#  DEPENDS system_lib
)

## Declare a C++ interface library.
add_library(catkin_deps INTERFACE)
target_link_libraries(catkin_deps INTERFACE ${catkin_LIBRARIES})
target_include_directories(catkin_deps INTERFACE include ${catkin_INCLUDE_DIRS})

## Declare a C++ library.
add_library(${PROJECT_NAME}
  src/lib.cpp include/package/lib.hpp
)

## Specify libraries to link a library target against.
target_link_libraries(${PROJECT_NAME} PUBLIC catkin_deps)

## Specify directories with header files fo the target.
target_include_directories(${PROJECT_NAME} PUBLIC include)

## Add CMake target dependencies of the library.
##
## As an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure.
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable.
add_executable(cpp_node src/cpp_node.cpp)

## Specify libraries to link an executable target against.
target_link_libraries(cpp_node PRIVATE
  ${PROJECT_NAME}
)


## Install.
##
# All install targets should use catkin DESTINATION variables.
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html.

## Mark executable scripts (Python etc.) for installation.
## In contrast to setup.py, you can choose the destination.
catkin_install_python(PROGRAMS
  scripts/py_node.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark executables for installation.
## See http://docs.ros.org/en/melodic/api/catkin/html/howto/format2/building_executables.html.
install(TARGETS cpp_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark libraries for installation.
## See http://docs.ros.org/en/melodic/api/catkin/html/howto/format2/building_libraries.html.
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

## Mark cpp header files for installation.
install(DIRECTORY include/package
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)

install(DIRECTORY
  config
  launch
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})


## Testing.

## Add gtest based cpp test target and link libraries.
# catkin_add_gtest(${PROJECT_NAME}-test tests/test_package_name.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}_lib)
# endif()

## Add folders to be run by python nosetests.
# catkin_add_nosetests(tests)
