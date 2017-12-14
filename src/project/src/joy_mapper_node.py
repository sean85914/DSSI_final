#!/usr/bin/env python

import rospy
import serial
from sensor_msgs.msg import Joy


class JoyMapper(object):
	def __init__(self):
		self.node_name = rospy.get_name()
		rospy.loginfo("[%s] Initializing." %(self.node_name))
		self.joy = None
		self.ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
		self.gain = 40
		self.steer_gain = 0.3
		self.car_linear  = None
		self.car_angular = None 
		self.sub_joy = rospy.Subscriber("joy", Joy, self.cbJoy, queue_size=1)
	def cbJoy(self, joy_msg):
		self.joy = joy_msg
		self.publishControl()
	def publishControl(self):
		self.car_linear  = self.joy.axes[1] * self.gain
		self.car_angular = self.joy.axes[3] * self.steer_gain
		self.ser.write(str(self.car_linear)+str(" ")+str(self.car_angular))
		print self.car_linear
		print self.car_angular
	def on_shutdown(self):
		self.ser.write(str(0)+str(" ")+str(0))
		rospy.loginfo("[%s] Shutting down." %(self.node_name))
if __name__ == '__main__':
	rospy.init_node("joy_mapper", anonymous = False)
	joy_mapper = JoyMapper()
	rospy.spin()
