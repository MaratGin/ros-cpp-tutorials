cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

## Specify the package's name here.
## It should match with the content of <name> tag in package.xml.
project(ros_cpp_tutorials)

## Compile as C++17, supported in ROS Kinetic and newer.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find catkin macros and libraries.
## If COMPONENTS list such as find_package(catkin REQUIRED COMPONENTS xyz) is used,
## also find other catkin packages (i.e. populate catkin_* variables).
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp std_msgs
)

## Declare a C++ interface library.
add_library(catkin_deps INTERFACE)
target_link_libraries(catkin_deps INTERFACE ${catkin_LIBRARIES})
target_include_directories(catkin_deps INTERFACE include ${catkin_INCLUDE_DIRS})

## Declare a C++ library.
add_library(${PROJECT_NAME}
  src/lib.cpp include/ros_cpp_tutorials/lib.hpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC catkin_deps)
target_include_directories(${PROJECT_NAME} PUBLIC include)

## Add CMake target dependencies of the library.
##
## As an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure.
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable.
add_executable(cpp_node nodes/cpp_node.cpp)
target_link_libraries(cpp_node PRIVATE ${PROJECT_NAME})

add_executable(oop src/oop.cpp)
add_executable(inheritance src/inheritance/base.cpp)
add_executable(poly src/inheritance/polymorphism.cpp)
add_executable(raii src/raii.cpp)
add_executable(smart_pointers src/smart_pointers.cpp)
add_executable(smart_pointers_poly src/smart_pointers_poly.cpp)


## Mark executables for installation.
## See http://docs.ros.org/en/melodic/api/catkin/html/howto/format2/building_executables.html.
install(
  TARGETS cpp_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark libraries for installation.
## See http://docs.ros.org/en/melodic/api/catkin/html/howto/format2/building_libraries.html.
install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

## Mark cpp header files for installation.
install(
  DIRECTORY include/package
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)

install(
  DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)


## Testing.

## Add gtest based cpp test target and link libraries.
# catkin_add_gtest(${PROJECT_NAME}-test tests/test_package_name.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}_lib)
# endif()

## Add folders to be run by python nosetests.
# catkin_add_nosetests(tests)
