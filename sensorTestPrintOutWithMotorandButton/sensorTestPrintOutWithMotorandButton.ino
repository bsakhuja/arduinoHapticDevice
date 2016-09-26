// Haptic Device
// Authors: Savannah Benbrook, Tim McCormick, Brian Sakhuja
// September 25, 2016
// 

// Define pins
const int sensorPin = 5;
const int motorPin = 6;
const int buttonPin = 2;

// Define global variables
long sensorData, inches, cm, dutyCycle;
boolean currentState = LOW; // for pushbutton
boolean lastState = LOW; // for pushbutton



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
  //
  if (dutyCycle > 180) {
    analogWrite(motorPin, 0);
  } else if (dutyCycle < 50) {
    analogWrite(motorPin, 0);
  }  else {
    analogWrite(motorPin, dutyCycle);
  }

  // Button behavior
  currentState = digitalRead(buttonPin);
  Serial.println(currentState);
  if (currentState == HIGH && lastState == LOW) {
    Serial.println("pressed");
    delay(500); // button debouncing
  } 
  lastState = currentState;
  
  // Convert sensorData to inches and print
  inches = sensorData/1.959 ;
  Serial.print(inches);
  Serial.print("in ");
  Serial.println();


  delay(500);

}
