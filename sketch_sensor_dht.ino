#include <dht11.h>


#define DHT11PIN 2
#define REDLEDPIN 3
#define GREENLEDPIN 4
#define BLUELEDPIN 5
dht11 DHT11;
int readingRate=1000;
void setup()
{
  Serial.begin(9600);
  pinMode(REDLEDPIN,OUTPUT);
  pinMode(GREENLEDPIN,OUTPUT);
  pinMode(BLUELEDPIN,OUTPUT);
}

void manageTempLeds(float temperature){
  if(temperature <= 16.0){
    digitalWrite(BLUELEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(REDLEDPIN, LOW);
  }
  if(temperature > 16.0 && temperature <= 30.0){
    digitalWrite(BLUELEDPIN, LOW);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(REDLEDPIN, LOW);
  }
  if(temperature > 30.0){
    digitalWrite(BLUELEDPIN, LOW);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(REDLEDPIN, HIGH);
  }  
}

void loop()
{
      if(Serial.available() > 0){
        readingRate = Serial.parseInt();        
      }   
      Serial.println(); 
    
      int chk = DHT11.read(DHT11PIN);
      float temp = (float)DHT11.temperature;      
      float hum = (float)DHT11.humidity;
      Serial.print(temp, 2);
      Serial.print("|");  
      Serial.print(hum, 2);    
      manageTempLeds(temp);
      delay(readingRate);
}
