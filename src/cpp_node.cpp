#include <string>
#include <iostream>  // cout

#include <ros/ros.h>      // NodeHandle
#include <ros/package.h>  // ros::package::getPath

#include "package/lib.hpp"

static constexpr auto NODE_NAME = "cpp_node";

int main(int argc, char **argv) {

  ros::init(argc, argv, NODE_NAME);

  ros::NodeHandle nh;

  if (nh.ok()) {
    ROS_INFO_STREAM("Node path " << ros::package::getPath("catkin_package_template"));
  }

  return 0;
}