// Haptic Device
// Authors: Savannah Benbrook, Tim McCormick, Brian Sakhuja
// December 1, 2016
//
// Lilypad Pin Layout Reference: http://pighixxx.com/lilypadbase.pdf

// Define pins
const int sensorPin = 17; //A3 on Uno ANALOG INPUT
const int motorPin = 15; //A1 on Uno ANALOG OUTPUT

// Define global variables
long sensorData, inches, cm, delayTime, feedToVibratePattern;
long motorStrength = 200; //constant motor strength
int index;


void setup() {

  //Initialize
  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while(! Serial);
}

void vibratePattern(long distance) {
  delayTime = 1/distance;
  analogWrite(motorPin, motorStrength);
  for (int x = 0; x < delayTime; x++) {
    index = 0;
    index++;
  }
  analogWrite(motorPin, 0);
//  for (int x = 0; x < delayTime; x++) {
//    index = 0;
//    index++;
//  }
}

void loop() {
  // Read in data from sensor
  sensorData = analogRead(sensorPin);
  feedToVibratePattern = sensorData;
  delayTime = (1/feedToVibratePattern)*1000;
  
  if(feedToVibratePattern > 130) {
    analogWrite(motorPin, 0);
  } else if(feedToVibratePattern < 20) {
    analogWrite(motorPin, 0);
  } else {
    vibratePattern(feedToVibratePattern); 
  }
 

  // Convert sensorData to inches and print
  inches = sensorData/1.959 ;
  Serial.print(sensorData);
  Serial.print(" delay in ms. ");
  Serial.print(inches);
  Serial.print("in ");
  Serial.println();

}
