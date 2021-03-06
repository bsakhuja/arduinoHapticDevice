// Haptic Device
// Authors: Savannah Benbrook, Tim McCormick, Brian Sakhuja
// December 1, 2016
//
// Lilypad Pin Layout Reference: http://pighixxx.com/lilypadbase.pdf

// Define pins
const int sensorPin = 17; //A3 on Lilypad ANALOG INPUT
const int motorPin = 15; //A1 on Lilypad ANALOG OUTPUT

// Define global variables
long sensorData, inches, cm, dutyCycle;



void setup() {

  //Initialize
  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while(! Serial);
}

void loop() {
  // Read in data from sensor
  sensorData = analogRead(sensorPin);
  dutyCycle = 200-sensorData;
  
  // Vibrate motor with if statments
  // Motor behavior:
  // if (dutyCycle > 180), object is too close
  // if (dutyCycle < 50), object is too far away
  // else write the appropriate duty cycle to the motor
 
  if (dutyCycle > 180) {
    analogWrite(motorPin, 0);
  } else if (dutyCycle < 50) {
    analogWrite(motorPin, 0);
  }  else {
    analogWrite(motorPin, dutyCycle);
  }
  
  // Convert sensorData to inches and print
  inches = sensorData/1.959 ;
  Serial.print(sensorData);
  Serial.print(" raw sensor data. ");
  Serial.print(inches);
  Serial.print("in ");
  Serial.println();


  delay(50);

}
