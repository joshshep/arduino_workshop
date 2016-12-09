/*
 * Calibrate the alarm by blocking the sensor for the first 5 seconds
 * Then the alarm will sound when the block is removed!
 * 
 * 
 */

int PIEZO_PIN = 2;
int RED_PIN = 3;
int GREEN_PIN = 5;
int BLUE_PIN = 6;
int PHOTORESISTOR_PIN = 5;
int max_photoresistor_read = 0;

void setup() 
{
  // everything here gets run once at the beginning

  Serial.begin(9600);
  // set the red pin to output (not input)
  pinMode(RED_PIN,  OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(PIEZO_PIN,OUTPUT);
  pinMode(PHOTORESISTOR_PIN,INPUT);

  // turn all of the LED pins on
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(GREEN_PIN,HIGH);
  digitalWrite(BLUE_PIN,HIGH);

  // get the maximum value for the photoresistor
  Serial.println("Calibrating...");
  unsigned long current_time = millis();
  unsigned long target_time = current_time + 5000;
  while(current_time < target_time)
  { // for 5 seconds, find the maximum value of the photoresistor
    int current_photoresistor_read = analogRead(PHOTORESISTOR_PIN);
    if(current_photoresistor_read > max_photoresistor_read)
    {
      max_photoresistor_read = current_photoresistor_read;
    }
    current_time = millis();
  }
  max_photoresistor_read *= 1.1;
  if(max_photoresistor_read >= 1023)
  {
    Serial.println("It's very bright in here!");
  }
  Serial.print("Photoresistor threshold = ");
  Serial.println(max_photoresistor_read);
  
}

void loop() 
{
  // everything here gets run repeatedly
  int current_photoresistor_read = analogRead(PHOTORESISTOR_PIN);
  if(current_photoresistor_read > max_photoresistor_read)
  {
    //sound the alarm!
    digitalWrite(PIEZO_PIN,HIGH);
    delay(1000);
    digitalWrite(PIEZO_PIN,LOW);
  }
  Serial.print("current read = ");
  Serial.println(current_photoresistor_read);
  //pause for a millisecond before looping
  delay(50);
}
