import serial
import time

arduino = serial.Serial('COM3', 9600)  # Create Serial object named arduino
time.sleep(2)  # wait for 2 seconds for the communication to get established

print('Enter your commands below.\r\nInsert "exit" to leave the application.')

while 1:
    val = input("Enter object (bottle, ballpoint, hp, home, key, button): ")  # get input from user

    if val == 'exit':
        arduino.close()
        break
    elif val == 'bottle':
        arduino.write(str.encode('60,60,60,60'))  # send angle to serial port
    elif val == 'hp':
        arduino.write(str.encode('0,0,0,60'))  # send angle to serial port
    elif val == 'ballpoint':
        arduino.write(str.encode('90,90,0,60'))  # send angle to serial port
    elif val == 'key':
        arduino.write(str.encode('90,0,0,60'))  # send angle to serial port
    elif val == 'button':
        arduino.write(str.encode('120,120,0,120'))  # send angle to serial port
    elif val == 'home':
        arduino.write(str.encode('0,0,0,0'))  # send angle to serial port
    else:
        print("Invalid input. Please enter either 'bottle', 'ballpoint', 'hp', 'key', 'button', or 'home'.")

    print("Angles sent")
