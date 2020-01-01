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


//Code for the traffic light arduino
//declare LED pins
const int redLight = 12;
const int greenLight = 11;
const int redLight2 = 10;
const int greenLight2 = 9;
const int yellowLight = 8;

//Declare button
const int lightButton = 2;


void setup() {
  //Set up LEDs
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(redLight2, OUTPUT);
  pinMode(greenLight2, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  Serial.begin(9600); 
  pinMode(lightButton, INPUT); //Button
}

int buttonState = LOW; //Store button state


void loop() {
  
  //Brooklyn Debounce
  
  int valUp;                        // variable for reading the pin status
  int valUp2;                       // variable for reading the delayed/debounced status
  valUp = digitalRead(lightButton);      // read input value and store it in val
  delay(10);                         // 10 milliseconds 
  valUp2 = digitalRead(lightButton);     // read the input again to check for bounces
 
  if (valUp == valUp2)                 // make sure we got 2 consistant readings
  { 
    // save the new state in our variable
    buttonState = valUp;  
  }
  //If light button was pressed
  if(buttonState == HIGH){
    digitalWrite(redLight,HIGH);
    digitalWrite(greenLight,HIGH);
    digitalWrite(redLight2,HIGH);
    digitalWrite(greenLight2,HIGH);
    digitalWrite(yellowLight,HIGH);
  } //End if
  else{ //If button was not pressed
    digitalWrite(redLight,LOW);
    digitalWrite(greenLight,LOW);
    digitalWrite(redLight2,LOW);
    digitalWrite(greenLight2,LOW);
    digitalWrite(yellowLight,LOW);

  } //End else
     
}//End loop 
