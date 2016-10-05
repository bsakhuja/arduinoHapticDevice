//Feel free to use this code.

//Please be respectful by acknowledging the author in the code if you use or modify it.

//Author: Bruce Allen

//Date: 23/07/09



//Digital pin 7 for reading in the pulse width from the MaxSonar device.

//This variable is a constant because the pin will not change throughout execution of this code.

const int sensorPin = 7;
const int motorPin = 6;

int timeOnPWM = 0;
int timeOffPWM = 0;



//variables needed to store values

long pulse, inches, cm, pwmTime, pwmfrom0to255, pulse2;



void setup() {

  //This opens up a serial connection to shoot the results back to the PC console
  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while(! Serial);

}

void loop() {

  //Used to read in the pulse that is being sent by the MaxSonar device.
  //Pulse Width representation with a scale factor of 147 uS per Inch.

//  pulse = pulseIn(sensorPin, HIGH);
//  pwmTime = pulse;
//  pwmfrom0to255 = pwmTime / 147; // duty cycle 0 (always off) 255 (always on)
//  Serial.print(pulse);
//  Serial.print(" pulse, ");
//  Serial.print(pwmfrom0to255);
//  Serial.print(" duty cycle, ");
//  
//  // Vibrate motor
//  analogWrite(motorPin, pwmfrom0to255);


  pulse2 = analogRead(5);
  pwmTime = pulse2;
  pwmfrom0to255 = pwmTime / 147; // duty cycle 0 (always off) 255 (always on)
  Serial.print(pulse2);
  Serial.print(" pulse, ");
  Serial.print(pwmfrom0to255);
  Serial.print(" duty cycle, ");
  
  // Vibrate motor
  analogWrite(motorPin, 200-pulse2);
  
  
  //147uS per inch

  inches = pulse2 / 147;

  //change inches to centimetres

  cm = inches * 2.54;



  Serial.print(inches);
  Serial.print("in ");
//  Serial.print(cm);
//  Serial.print("cm");
  Serial.println();



  delay(50);

}
