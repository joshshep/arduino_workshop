int PIEZO_PIN = 2;
int RED_PIN = 6;
int GREEN_PIN = 5;
int BLUE_PIN = 3;

void setup() 
{
  // everything here gets run once at the beginning

  // set all of the pins for output (not input)
  pinMode(RED_PIN,  OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(PIEZO_PIN,OUTPUT);
  
}

void loop() 
{
  // everything here gets run repeatedly

  // turn on the red pin
  digitalWrite(RED_PIN,HIGH);
  
  // wait 0.5 seconds
  delay(500);

  //turn off the red pin
  digitalWrite(RED_PIN,LOW);

  // turn on the green pin, etc
  digitalWrite(GREEN_PIN,HIGH);
  delay(500);
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,HIGH);
  delay(500);
  digitalWrite(BLUE_PIN,LOW);

  // turn on the red *and* green pin (r+g=yellow)
  digitalWrite(RED_PIN,HIGH); digitalWrite(GREEN_PIN,HIGH);
  delay(500); // wait 0.5 seconds
  // turn off the red and green pin
  digitalWrite(RED_PIN,LOW); digitalWrite(GREEN_PIN,LOW);

  // turn on the green *and* blue pin (g+b=cyan), etc
  digitalWrite(GREEN_PIN,HIGH); digitalWrite(BLUE_PIN,HIGH);
  delay(500);
  digitalWrite(GREEN_PIN,LOW); digitalWrite(BLUE_PIN,LOW);

  digitalWrite(BLUE_PIN,HIGH); digitalWrite(RED_PIN,HIGH);
  delay(500);
  digitalWrite(BLUE_PIN,LOW); digitalWrite(RED_PIN,LOW);

  // beep the buzzer for 0.25 seconds
  digitalWrite(PIEZO_PIN,HIGH);
  delay(250);
  digitalWrite(PIEZO_PIN,LOW);
}
