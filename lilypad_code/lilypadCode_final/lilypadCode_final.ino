/* 
 *  Harris Haptic Device
 *  Authors: Savannah Benbrook, Tim McCormick, and Brian Sakhuja
 *  Date: December 1, 2016
 */

// Define pins
const int pwPin = 5; // sensor pin
const int motorPin = 14; // motor pin


// Variables needed to store values
long pulse, inches, cm, pulse2analog;

void setup() {
  //This opens up a serial connection to shoot the results back to the PC console
  Serial.begin(9600);
}



void loop() {

  pinMode(pwPin, INPUT); // define sensor pin as input
  pinMode(motorPin, OUTPUT); // define motor pin as output
  
  //Used to read in the pulse that is being sent by the MaxSonar device.

  //Pulse Width representation with a scale factor of 147 uS per Inch.

  pulse = pulseIn(pwPin, HIGH);

  //147uS per inch
  inches = pulse / 147;

  //change inches to centimetres
  cm = inches * 2.54;
  pulse2analog = 255/(254*147);

  if (inches <= 120 && inches > 100) { // Object between 120 and 100 inches
    analogWrite(motorPin, 255);
    delay(50);
    analogWrite(motorPin,0);
    delay(450);
  } else if (inches <= 100 && inches > 80) { // Object between 100 and 80 inches
    analogWrite(motorPin, 255);
    delay(100);
    analogWrite(motorPin,0);
    delay(400);  
  } else if (inches <= 80 && inches > 60) { // Object between 80 and 60 inches
     analogWrite(motorPin, 255);
    delay(200);
    analogWrite(motorPin,0);
    delay(300);
  } else if (inches <= 60 && inches > 50) { // Object between 60 and 50 inches
    analogWrite(motorPin, 255);
    delay(200);
    analogWrite(motorPin,0);
    delay(250);
  } else if(inches <= 50 && inches > 40) { // Object between 50 and 40 inches
    analogWrite(motorPin, 255);
    delay(200);
    analogWrite(motorPin,0);
    delay(200);
  } else if (inches <= 40 && inches > 30) { // Object between 40 and 30 inches
    analogWrite(motorPin, 255);
    delay(200);
    analogWrite(motorPin,0);
    delay(150);
  } else if(inches <= 30 && inches > 20) { // Object between 30 and 20 inches
    analogWrite(motorPin, 255);
    delay(200);
    analogWrite(motorPin,0);
    delay(100);
  } else if(inches <= 20 && inches > 15) { // Object between 20 and 15 inches
    analogWrite(motorPin, 255);
    delay(150);
    analogWrite(motorPin,0);
    delay(100);
  } else if(inches <= 15 && inches > 5) { // Object between 15 and 5 inches
    analogWrite(motorPin, 255);
    delay(150);
    analogWrite(motorPin,0);
    delay(50);
  } else { // Object is too close or too far. No vibration.
    analogWrite(motorPin,0);
  }


  Serial.print(pulse);

  Serial.print(" = pulse ");
  
  Serial.print(inches);

  Serial.print("in, ");

  Serial.print(cm);

  Serial.print("cm");

  Serial.println();



  delay(300);

}
