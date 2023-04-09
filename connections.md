### Ultrasonic Sensor:
VCC -> 5V on Arduino  
GND -> GND on Arduino  
Trig -> Pin 10 on Arduino  
Echo -> Pin 9 on Arduino

### Micro Servo Motor:
VCC -> 5V on Arduino  
GND -> GND on Arduino  
Signal -> Pin 5 on Arduino

### Colour Sensor:
GND -> GND on Arduino  
OUT -> Pin 7 on Arduino  
S0 -> Pin 2 on Arduino  
S1 -> Pin 3 on Arduino  
S2 -> Pin 4 on Arduino  
S3 -> Pin 6 on Arduino  

### L293 Motor Driver:
Enable 1 -> Pin 11 on Arduino  
Enable 2 -> Pin 12 on Arduino  
Input 1 -> Pin 13 on Arduino  
Input 2 -> Pin 8 on Arduino  
Input 3 -> Pin 0 on Arduino  
Input 4 -> Pin 1 on Arduino  
VCC1 -> 9V Battery Positive Terminal  
GND1 -> GND on Arduino  

### High Torque DC Motors:
Connect one motor to the outputs of the first H-bridge (OUT1 and OUT2), and the other motor to the outputs of the second H-bridge (OUT3 and OUT4).  
Connect the positive terminal of each motor to VCC1 on the motor driver and the negative terminal to OUT1 or OUT3 respectively.

### 9V Batteries:
Connect the positive terminal of both batteries to VCC1 and VCC2 respectively, and connect the negative terminal of both batteries to GND1 and GND2 respectively.
