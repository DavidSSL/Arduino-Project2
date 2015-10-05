const int sensorPin = A0;
const float baselineTemp = 26.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port

  for(int pinNumber =2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

  Serial.println(String("Sensor value: ") + sensorVal);

  // Convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.println(String("Volts: ") + voltage);

  // Convert the voltage to temperature in degrees
  float temperature = (voltage - 0.5) *100;
  
  Serial.println(String("Degrees celcius: ") + temperature);

  Serial.println("======================");

  if(temperature < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp+2 
    && temperature < baselineTemp +4)
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    }
  else if (temperature >= baselineTemp + 4
    && temperature < baselineTemp +6)
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    }
  else if (temperature >= baselineTemp + 6)
  {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
  }

  delay(3000);


  
}
