#!/usr/bin/env python3

import rospy
from std_msgs.msg import String


def publisher():
    rospy.init_node('publisher_node', anonymous=True)
    pub = rospy.Publisher('Task1', String, queue_size=8)
    rate = rospy.Rate(0.5)

    while not rospy.is_shutdown():
        message = "Hi Subscriber node"
        message2 = "Sending message to Subscriber Node"
        rospy.loginfo(message2)
        pub.publish(message)
        rate.sleep()


if __name__ == '__main__':
    publisher()

