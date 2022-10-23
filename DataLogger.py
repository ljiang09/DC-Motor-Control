import serial
import time


serial_port = serial.Serial(port='COM5', baudrate=9600, timeout=1)   # /dev/ttyACM0


def fetch_data():
    '''
    TODO: fill out docstring here
    '''
    file = open("C:/Users/ljiang/OneDrive - Olin College of Engineering/Desktop/Olin 2022-2023/PIE/DC-Motor-Control/recording_data_3.csv", "w")
    file.write("left_sensor,right_sensor,left_speed,right_speed\n")

    while True:
        data_line = serial_port.readline()
        
        try:
            data_line = data_line.decode("utf-8")

            if data_line == "Motor Shield found.":
                continue

            if data_line == "STOP\r\n":
                break

            write_to_file(file, data_line)
        except:
            print("Couldn't decode line")

    print("closing file")
    file.close()


def write_to_file(file, data_line):
    '''
    converts lines of string data to array and writes it as CSV

    file: the file to write to
    data_line: a string that will be parsed into a CSV line and written to the file
    '''
    split = data_line.split(" ")
    print(split)
    for data in split:
        file.write(data + ",")
    file.write("\n")


fetch_data()
