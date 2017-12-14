#!/usr/bin/env python
import rospy
import tf
import serial
def isfloat(value):
	try:
		float(value)
		return True
	except ValueError:
		return False

class Serial(object):
	def __init__(self):
		self.node_name = rospy.get_name()
		self.ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
		self.ser.xonxoff = 1
		self.read_time = 0.1 # 10 Hz
		self.read_timer = rospy.Timer(rospy.Duration.from_sec(self.read_time), self.read_serial)
		self.br = tf.TransformBroadcaster()
		rospy.loginfo("[%s] Initialized."  %(self.node_name))
	def on_shutdown(self):
		rospy.loginfo("[%s] Shutting down." %(self.node_name))
	def read_serial(self, event):
		while self.ser.in_waiting:
			str = self.ser.readline()
			#str = str.decode('utf-8')
			pose = str.split()
			if len(pose) == 3 and isfloat(pose[0]) and isfloat(pose[1]) and isfloat(pose[2]):
				x = float(pose[0])
				y = float(pose[1])
				theta = float(pose[2])
				self.br.sendTransform((x, y, 0),
							tf.transformations.quaternion_from_euler(0, 0, theta),
							rospy.Time.now(),
							"base_link",
							"map")
if __name__ == '__main__':
	rospy.init_node('serial_node', anonymous = False)
	node = Serial()
	rospy.on_shutdown(node.on_shutdown)
	rospy.spin()
