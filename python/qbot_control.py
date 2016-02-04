import serial, time

port = "/dev/tty.usbserial-FTCTLN1J"
ser = serial.Serial(port, 57600)
ser.bytesize = serial.EIGHTBITS #number of bits per bytes
ser.parity = serial.PARITY_NONE #set parity check: no parity
ser.stopbits = serial.STOPBITS_ONE #number of stop bits
ser.timeout = 1            #non-block read
ser.xonxoff = False     #disable software flow control
ser.rtscts = False     #disable hardware (RTS/CTS) flow control
ser.dsrdtr = False       #disable hardware (DSR/DTR) flow control
ser.writeTimeout = 2     #timeout for write


if ser.isOpen():
	ser.flush()
	ser.write([chr(128), chr(132), chr(139), chr(2), chr(0), chr(0)])
	time.sleep(.2)

else:
	print("isnt open")
	ser.open()
	ser.flush()
	ser.write([chr(128), chr(132), chr(139), chr(2), chr(0), chr(0)])
	time.sleep(.2)

#ser.write(startCmd)
#ser.write(loadSong0)
#ser.write(playSong0)
#ser.write(startStream)
ser.close()