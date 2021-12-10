//William Cashen 
//Iowa State University
//Joystick Control with Servo
//AERE 361 Final Project

//Include the Library For Servo Functions
#include <Servo.h>

//Define the pin number the servo uses with a signal wire
int ServoPin1 = 0 ;
int ServoPin2 = 1 ;
//Initializing the Pins

int VRx = A5;  //Analog Related Pin -> VRx on Joystick
int VRy = A4;  //Analog Related Pin -> VRy on Joystick
int SW = 9; //RX Pin(needs to be the physical pin number)

//Initializing the variables
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
int WVx = 0;

//Creating a Servo Object
Servo Servo1;
Servo Servo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  pinMode(ServoPin2, OUTPUT);

  //Attach the Servo to the used pin number
  Servo1.attach(ServoPin1);
  Servo2.attach(ServoPin2);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  xPosition = analogRead(VRx);    //gets the read value of the x posistion on the joystick
  WVx = (180./1023.)*xPosition;  //uses a write value using the slope curve of 180/1023
  
  yPosition = analogRead(VRy);    //gets the value of the y posistion on the joystick
  SW_state = digitalRead(SW);     //gets the value of the button press on the joystick
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  //Sets the linear servo to the desired posistion based on the joystick movement
  Servo2.write(WVx);  
  
  //Set the servo to rest posistion
  Servo1.write(90);
  
  //Pressing the Joystick Triggers the kick
  if (SW_state == 0){
    //Move the Servo back to 20 degrees
    Servo1.write(30);
    delay(500);
    //Move the Servo to 160 degrees
    Servo1.write(200);
    delay(1000);
  }
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);
  
}
