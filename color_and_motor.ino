const int trigPin = 10; // Ultrasonic sensor trigger pin
const int echoPin = 9; // Ultrasonic sensor echo pin
const int motor1Pin1 = 13; // Motor 1 input 1 pin
const int motor1Pin2 = 8; // Motor 1 input 2 pin
const int motor2Pin1 = 0; // Motor 2 input 1 pin
const int motor2Pin2 = 1; // Motor 2 input 2 pin
const int servoPin = 5; // Servo motor signal pin
const int minDistance = 15; // Minimum distance to obstacle
const int maxDistance = 40; // Maximum distance to obstacle
const int speed = 200; // Motor speed
const int turnDelay = 500; // Time to turn (in ms)

// Motor Pins
const int enA = 11;
const int in1 = 13;
const int in2 = 8;

// TCS230 or TCS3200 pins wiring to Arduino
#define S0 2
#define S1 3
#define S2 4
#define S3 6
#define sensorOut 7

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
// int blueFrequency = 0;

// Stores the red. green and blue colors
int redColor = 0;
int greenColor = 0;
// int blueColor = 0;

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);
}

void loop() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // redColor = map(redFrequency, 70, 120, 255,0);
  redColor = map(redFrequency, 70, 120, 255,0);
  
  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redColor);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // greenColor = map(greenFrequency, 100, 199, 255, 0);
  greenColor = map(greenFrequency, 100, 199, 255, 0);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenColor);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  // blueFrequency = pulseIn(sensorOut, LOW);
  // // Remaping the value of the BLUE (B) frequency from 0 to 255
  // // You must replace with your own values. Here's an example: 
  // // blueColor = map(blueFrequency, 38, 84, 255, 0);
  // blueColor = map(blueFrequency, 38, 84, 255, 0);
  
  // Printing the BLUE (B) value 
  // Serial.print(" B = ");
  // Serial.print(blueColor);
  // delay(500);


  analogWrite(enA, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // digitalWrite(motor1Pin1, HIGH);
  // digitalWrite(motor1Pin2, LOW);
  // digitalWrite(motor2Pin1, HIGH);
  // digitalWrite(motor2Pin2, LOW);

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > greenColor){
      Serial.println(" - RED detected!");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
  }
  if(greenColor > redColor){
    Serial.println(" - GREEN detected!");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);    
  }
  // if(blueColor > redColor && blueColor > greenColor){
  //   Serial.println(" - BLUE detected!");
  // }
}