const int sensorPin = A0;
const int LEDPin = 10;

int lightAmount = 0;
long timerLED = 0;
long timerSensor = 0;
boolean toggleLED = true;

void setup(){
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}
void loop(){
  receiver();
  transmitter();
}
void receiver(){
    if(millis()>= timerSensor + 100){
    lightAmount = analogRead(sensorPin);

    Serial.print("Light Intensity: ");
    Serial.println(lightAmount);
  }

  
}
void transmitter(){
  if (millis() >= timerLED + 2000){
    toggleLED = !toggleLED;
    digitalWrite(LEDPin, toggleLED);
    timerLED = millis();
  }
}

