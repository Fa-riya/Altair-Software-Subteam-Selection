#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo("%s", data.data)

def subscriber():
    rospy.init_node('subscriber_node', anonymous=True)
    rospy.Subscriber('Task1', String, callback)
    rospy.spin()

if __name__ == '__main__':
    subscriber()
