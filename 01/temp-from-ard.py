import serial
import time  

s = None  

def my_setup():   
    global s   
    # open serial COM port to /dev/ttyS0, which maps to UART0(D0/D1)   
    # the baudrate is set to 57600 and should be the same as the one   
    # specified in the Arduino sketch uploaded to ATmega32U4.
    s = serial.Serial("/dev/ttyS0", 57600);  

def my_loop():  
    # read string from the Arduino sketch on ATmega32U4.   
    # the sketch will turn on the LED attached to D13 on the board   
    my_line = s.readline()
    print my_line;
    #print "*C";

if __name__ == '__main__':   
    my_setup();   
    while True:    
        my_loop();