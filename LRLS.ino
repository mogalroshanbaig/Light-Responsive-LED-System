//Light Responsive LED System
const int ledPin = 9; // Pin for the single LED
const int buzzerPin = 7; // Pin for the piezo buzzer
const int lightSensorPin = A0; // Analog pin for the light sensor

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialize the Serial Monitor with a baud rate of 9600
}

void loop() {
  int lightValue = analogRead(lightSensorPin);
  
  int ledhighbright = 2500; 
  int ledlowbright=0;
  int beephigh=4000;
  //Increase the Brightness level when lightsensor value is low
  if(lightValue<=6){
  analogWrite(ledPin, ledhighbright);//Turn on LED
  tone(buzzerPin, beephigh);//Start beep
  delay(100); 
  noTone(buzzerPin);//stop beep 
  }else{
  analogWrite(ledPin,ledlowbright);//Turn off LED
  }
  // Print the light sensor value to the Serial Monitor
  Serial.print("Light Sensor Value: ");
  Serial.println(lightValue);

  delay(100); // Adjust the delay as needed
  
}
