import rospy


def main():
  rospy.init_node("py_node")
  rospy.loginfo(f'Node URI: {rospy.get_node_uri()}')


if __name__ == '__main__':
  main()
