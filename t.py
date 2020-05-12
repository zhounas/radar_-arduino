import matplotlib.pyplot as plt
import numpy as np
import keyboard
import time
import serial
plt.ion()
r = 0.3
theta = 0.5 * np.pi
ax = plt.subplot(111, projection='polar')
Point = [None] * 181
arduino= serial.Serial('/dev/ttyUSB1',9600, timeout=.1)
time.sleep(1)
while True:
	arduino.flushInput()
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	if data:
		values = data.decode('ascii').split(':')
		a, b = [int(s) for s in values]
		print(data," a is :",a," b is :",b)
		if b<200:
			if Point[a] != None:
				Point[a].remove()
			ax = plt.subplot(111, projection='polar')
			Point[a], = ax.plot(a*np.pi/180, b,'ro', color='black')
			ax.set_rmax(200)
			ax.set_rticks(range(0, 220, 20))
			ax.set_rlabel_position(0)
			ax.grid(True)
			plt.pause(0.0001)