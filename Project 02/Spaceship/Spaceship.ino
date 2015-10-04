int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT); // Switch  
  
  pinMode(3, OUTPUT); // Green Led
  pinMode(4, OUTPUT); // Red Led  
  pinMode(5, OUTPUT); // Red Led  

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW); // Switch onboard Led off
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  // Button is not pressed
  if(switchState == LOW)
  {
    digitalWrite(3, HIGH); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, LOW); // red LED
  }
  else // Button is pressed
  {
    digitalWrite(3, LOW); // green LED
    digitalWrite(4, HIGH); // red LED
    digitalWrite(5, HIGH); // red LED
  }
}
