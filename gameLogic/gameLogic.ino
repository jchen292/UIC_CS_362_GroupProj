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
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2,3,4,5,6,7);
int score;//Player score
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
int value;          // Store value from photoresistor (0-1023)
int light;//light value
char didGo;
void setup()
{
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  score = 50;//Player score
  lcd.print("hi");
  // Print a message to the LCD.
   Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop()
{
  light = analogRead(pResistor); //reads amount of light
  lcd.setCursor(0,0);
  if(Serial.available() > 0)
  {
    didGo = Serial.read();//Reads button input
    Serial.println(didGo);
    if(didGo == 'O' && light >= 255)//If you are driving and the light is go
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Keep Going");
      lcd.setCursor(0,1);
      lcd.print(score);
      Serial.println("Keep going");
      
    }
    else if(didGo == 'O' && light < 255)//If you are driving and the light is stop
    {
      lcd.clear();
      Serial.println(score);
      Serial.print(" Nahhhh");
      lcd.setCursor(0,0);
      lcd.print("Losing");//Losing points
      lcd.setCursor(0,1);
      lcd.print(score);
      score--;
    }
    
  }
  if(score == 0)//If the score is zero you lose
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You Lose!!");
  }
  delay(1000);
}
