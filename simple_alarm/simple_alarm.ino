int RED_PIN = 4;
int GREEN_PIN = 6;
int BLUE_PIN = 9;
int PIEZO_PIN = 11;
int PHOTORESISTOR_PIN = 13;
int max_photoresistor_read = 0;

void setup() 
{
  // everything here gets run once at the beginning

  // set the red pin to output (not input)
  pinMode(RED_PIN,  OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(PIEZO_PIN,OUTPUT);
  pinMode(PHOTORESISTOR_PIN,INPUT);
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(GREEN_PIN,HIGH);
  digitalWrite(BLUE_PIN,HIGH);

  unsigned long current_time = millis();
  unsigned long target_time = current_time + 5000;
  while(current_time < target_time)
  {
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
}

void loop() 
{
  // everything here gets run repeatedly
  int current_photoresistor_read = analogRead(PHOTORESISTOR_PIN);
  if(current_photoresistor_read > max_photoresistor_read)
  {
    //sound the alarm!
    digitalWrite(PHOTORESISTOR_PIN,HIGH);
    delay(1000);
    digitalWrite(PHOTORESISTOR_PIN,LOW);
  }
  delay(1);
}
