// Team 51
// Jordan Chen, jchen292
// Bryan Nguyen, bnguye39
// Alex Mendoza, amendo38
// Driving Test
/*
 * Our project will consist of us utilizing one arduino to act as a
  traffic light, which will utilize multiple LEDS: red, yellow,
  green, and white. The other Arduino will act as a "car" which will
  respond to the LEDS that light up from the traffic light arduino. 
  The motor will emulate the activation of a car accelerating/deaccelerating. 
  If the motor spins up to a certain speed and exceed a fixed
  limit, player's score will decrease. There will be a point system for every correct
  speed change based on traffic light.
 * 
 */


#define joystick  A0  //Analog Pin A0 -> Joystick
#define pin_Fan    9  //Digital Pin 9 -> DC Motor
 
int motor;            //Speed
 
void setup() {
  pinMode(pin_Fan, OUTPUT);
  pinMode(joystick, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  motor = analogRead(joystick);
  motor >>= 1;

  //If Joystick is pushed forward, accelerate
  //Speed will slow if push joystick slowly back, but not completely
  if(motor > 255){
    analogWrite(pin_Fan, (motor - 256));
    Serial.write('O');
  }
  //If not pushed forward, speed is 0
  else{
    digitalWrite(pin_Fan, 0);
    Serial.write('F');
  }


   delay(1000);
  
}//End Loop
