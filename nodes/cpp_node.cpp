#include <string>
#include <iostream>  // cout

#include <ros/ros.h>  // NodeHandle

#include "package/lib.hpp"

int main(int argc, char **argv) {
  ros::init(argc, argv, "cpp_node");

  ros::NodeHandle nh;

  if (nh.ok()) {
    ROS_INFO("Node has been started.");
  }

  return 0;
}
