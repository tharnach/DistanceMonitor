const int trigPin = 8;
const int echoPin = 7;

long duration, distance;

#include <Adafruit_NeoPixel.h>

#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //int colorNumber=0;
  //int difference;
}

void loop() {
  int colorNumber;
  int difference;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
   
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
   
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
  
  if((distance > 1) && (distance < 5)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 255){
      difference = 255-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if((distance > 4) && (distance < 6)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 220){
      difference = 220-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if((distance > 5) && (distance < 8)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 185){
      difference = 185-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if((distance > 7) && (distance < 10)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 150){
      difference = 150-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if((distance > 9) && (distance < 12)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 115){
      difference = 115-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if((distance > 11) && (distance < 15)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 80){
      difference = 80-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if((distance > 14) && (distance < 18)){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 45){
      difference = 45-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }else if(distance > 17){
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("colorNumber: " + colorNumber);
    if(colorNumber != 0){
      difference = 0-colorNumber;
      Serial.println("Difference: " + difference);
      if(difference < 0){
        colorNumber++;
      }else if (difference > 0){
        colorNumber--;
      }
    }
    colorWipe(strip.Color(colorNumber, colorNumber, colorNumber));
    delay(100);
  }
}

void colorWipe(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
  }
}
