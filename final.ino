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

// Color Sensor Pins
const int S0 = 2;
const int S1 = 3;
const int S2 = 4;
const int S3 = 6;
const int OUT = 7;

// Motor Pins
const int enA = 11;
const int in1 = 13;
const int in2 = 8;

// Color Thresholds
const int redThreshold = 200;
const int greenThreshold = 500;

// Color Frequencies
const int redFrequency = 500;
const int greenFrequency = 1000;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(servoPin, OUTPUT);

    // Color Sensor Setup
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  
  // Motor Setup
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // Color Sensor Frequency Scaling
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
  // Ultrasonic sensor distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration / 58;
  
  // If an obstacle is detected
  if (distance > minDistance && distance < maxDistance) {
    // Stop the car
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    
    // Change direction
    for (int angle = 0; angle <= 180; angle++) {
      digitalWrite(servoPin, HIGH);
      delayMicroseconds(500 + angle * 5);
      digitalWrite(servoPin, LOW);
      delayMicroseconds(19500 - angle * 5);
    }
    
    // Start moving forward again
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(500);
  } else {
    // Move the car forward
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  }

  // Read Color Sensor Values
  int red = 0;
  int green = 0;
  for (int i = 0; i < 5; i++) {
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    delay(10);
    red += pulseIn(OUT, LOW);
    
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    delay(10);
    green += pulseIn(OUT, LOW);
  }
  
  // Detect Red Color
  if (red > redThreshold && green < greenThreshold) {
    // Stop the Car
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    
  }
  // Detect Green Color
  else if (green > greenThreshold && red < redThreshold) {
    // Move the Car Forward
    analogWrite(enA, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
  }
  // No Color Detected
  else {
    // Move the Car Forward
    analogWrite(enA, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }  
}

