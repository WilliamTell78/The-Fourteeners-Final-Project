/* FSR testing sketch. 

Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */

/*#include <Adafruit_NeoPixel.h>*/
#include <Adafruit_CircuitPlayground.h>
#include <math.h>

//pressure sensor variables
int fsrAnalogPin = 4; // FSR is connected to analog 0, Resistive measurement
int fsrAnalogPin2 = 5;
int fsrReading;      // the analog reading from the FSR resistor divider //value output
int fsrReading2;

//ultrasonic sensor variables
int trigPin = 0; //Sets value of where the treshhold is triggered //A6
int echoPin = 9; //Sets the return value of where threshold 
//is triggered//A2
int pingTravelTime = 0; //Value telling whether or not a ball has scored
int maxPing = 500; //Comparative threshold to deteremine a score or not
 
void setup() {
  CircuitPlayground.begin();
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop() {
  fsrReading = analogRead(fsrAnalogPin);
  fsrReading2 = analogRead(fsrAnalogPin2);
  //Debugging Lines
  //Serial.print("Analog reading = ");
  //Serial.println(fsrReading);

  //Serial.print("Analog reading 2 = ");
  //Serial.println(fsrReading2);

  /Send Ultrasonic Pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);

  digitalWrite(trigPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH);
  delay(1);



  //Debugging Lines
  //Serial.print("pingTravelTime\n");
  //Serial.println(pingTravelTime);
   
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map
  LEDbrightness = map(fsrReading2, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
  //Debugging Lines
  Serial.print("LEDbrightness = ");
  Serial.println(LEDbrightness);
  //Thresholds change with every reset of the system
  //Matt helped with a solution to this by using an averaging of the first set of sensor results
  //to change the thresholds based on how the sensor is reading when it is initiated
  //low 50
  //mid 70-80
  //high 80<

  //missed goal
  if (pingTravelTime > maxPing){
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
    
  }

  //In goal didn't register on pressure sensor
  if (LEDbrightness < 90 && pingTravelTime < maxPing ){
    CircuitPlayground.setPixelColor(0, 255, 0, 255);
    CircuitPlayground.setPixelColor(1, 255, 0, 255);
    CircuitPlayground.setPixelColor(2, 255, 0, 255);
    CircuitPlayground.setPixelColor(3, 255, 0, 255);
    CircuitPlayground.setPixelColor(4, 255, 0, 255);
    CircuitPlayground.setPixelColor(5, 255, 0, 255);
    CircuitPlayground.setPixelColor(6, 255, 0, 255);
    CircuitPlayground.setPixelColor(7, 255, 0, 255);
    CircuitPlayground.setPixelColor(8, 255, 0, 255);
    CircuitPlayground.setPixelColor(9, 255, 0, 255);
  
  }

  //In goal soft kick as register on pressure sensor
  if (LEDbrightness >= 90 && LEDbrightness < 110 && pingTravelTime < maxPing){
  
    CircuitPlayground.setPixelColor(0, 255, 255, 0);
    CircuitPlayground.setPixelColor(1, 255, 255, 0);
    CircuitPlayground.setPixelColor(2, 255, 255, 0);
    CircuitPlayground.setPixelColor(3, 255, 255, 0);
    CircuitPlayground.setPixelColor(4, 255, 255, 0);
    CircuitPlayground.setPixelColor(5, 255, 255, 0);
    CircuitPlayground.setPixelColor(6, 255, 255, 0);
    CircuitPlayground.setPixelColor(7, 255, 255, 0);
    CircuitPlayground.setPixelColor(8, 255, 255, 0);
    CircuitPlayground.setPixelColor(9, 255, 255, 0);
  }

  //In goal hard kick as register on pressure sensor
  if (LEDbrightness >= 110 && pingTravelTime < maxPing){
  
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0);
  }

  
  delay(1);
}
