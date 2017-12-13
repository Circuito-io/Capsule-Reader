// Include Libraries
#include "Arduino.h"
#include "LED.h"
#include "Switchable.h"
#include "SparkFunISL29125.h"
#include "SoftwareSerial.h"
#include "SerLCD.h"

// Pin Definitions
#define LEDRed_PIN_VIN  3
#define SERLCD_PIN_RX 2

// Global variables and defines

uint16_t rgbSensorR,rgbSensorG,rgbSensorB;

int thresh = 20;
int ledState = LOW;
bool detect = 0;
const long interval = 4000;
unsigned long previousMillis = 0;

// object initialization
SoftwareSerial serlcdNSS(0,SERLCD_PIN_RX);
LED ledR(LEDRed_PIN_VIN);
SerLCD serlcd(serlcdNSS); 
SFE_ISL29125 rgbSensor;

//initializing the capsule by color

int cosi[3] = {161, 311, 300};
int dulsao[3] = {142, 253, 191};
int roma[3] = {83, 196, 177};
int livanto[3] = {188, 299, 187};
int vivalto_lungo [3] = {134, 294, 449};
int bukeela_lungo[3] = {330, 452, 319};
int kazaar[3] = {60, 165, 180};
int volluto[3] = {263, 421, 248};

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    pinMode(LEDRed_PIN_VIN, OUTPUT);
    serlcd.begin();  
    serlcd.setBrightness(20);
   
    // Initialize the rgbSensor
    bool rgbSensorInitStatus = rgbSensor.init();
    if (rgbSensor.init())
        Serial.println("rgbSensor Init OK!");
    else
        Serial.println("rgbSensor Init Failed! Check your wiring."); 
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
  unsigned long currentMillis = millis();
  
  int red = rgbSensor.readRed();
  int green = rgbSensor.readGreen();
  int blue = rgbSensor.readBlue();

  if (blue < 3) {
    Serial.println("sensor rgb");
    ledState = HIGH;
    digitalWrite(LEDRed_PIN_VIN, HIGH);
    detect = 1;
  }

  if (currentMillis - previousMillis >= interval && ledState == HIGH) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    digitalWrite(LEDRed_PIN_VIN, LOW);
    detect = 0;
    
  }
      Serial.print("Red:");
      Serial.print(rgbSensor.readRed());
      Serial.print("    Green:");
      Serial.print(rgbSensor.readGreen());
      Serial.print("    Blue:");
      Serial.print(rgbSensor.readBlue());
      Serial.println();
      delay(500);
      
  if (detect) {
   

    //Cosi
    if (abs(red - cosi[0]) < thresh && abs(green - cosi[1]) < thresh && abs(blue - cosi[2]) < thresh ) {
      
      Serial.println("Cosi");
      serlcd.setBrightness(28);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cosi");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 4/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 40ml");
      serlcd.setPosition(2,1);
      serlcd.print("Fruity");
      delay(2500);
      serlcd.clear();
    }


    //Dulsao
    if (abs(red - dulsao[0]) < thresh && abs(green - dulsao[1]) < thresh && abs(blue - dulsao[2]) < thresh ) {
      
      Serial.println("Dulsao");
      serlcd.setBrightness(28);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Dulsao");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 4/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 40ml");
      serlcd.setPosition(2,1);
      serlcd.print("Sweet Cereal");
      delay(2500);
      serlcd.clear();
    }

    //Roma
    if (abs(red - roma[0]) < thresh && abs(green - roma[1]) < thresh && abs(blue - roma[2]) < thresh ) {
      Serial.println("Roma");
      serlcd.setBrightness(28);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Roma");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 8/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 25ml");
      serlcd.setPosition(2,1);
      serlcd.print("Woody");
      delay(2500);
      serlcd.clear();
    }

    //Livanto

    if (abs(red - livanto[0]) < thresh && abs(green - livanto[1]) < thresh && abs(blue - livanto[2]) < thresh ) {
      Serial.println("Livanto");
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Livanto");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 6/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 40ml");
      serlcd.setPosition(2,1);
      serlcd.print("Caramel");
      delay(2500);
      serlcd.clear();
    }

    //Vivalto Lungo
    if (abs(red - vivalto_lungo[0]) < thresh && abs(green - vivalto_lungo[1]) < thresh && abs(blue - vivalto_lungo[2]) < thresh ) {
      Serial.println("Vivalto Lungo");
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Vivalto Lungo");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 4/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 110ml");
      serlcd.setPosition(2,1);
      serlcd.print("Floral,Roasted");
      delay(2500);
      serlcd.clear();
    }

    //Bukeela Lungo
    if (abs(red - bukeela_lungo[0]) < thresh && abs(green - bukeela_lungo[1]) < thresh && abs(blue - bukeela_lungo[2]) < thresh ) {
      Serial.println("Bukeela Lungo");
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Bukeela Lungo");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 3/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 110ml");
      serlcd.setPosition(2,1);
      serlcd.print("Wild, Floral");
      delay(2500);
      serlcd.clear(); 
    }

    //Kazaar
    if (abs(red - kazaar[0]) < thresh && abs(green - kazaar[1]) < thresh && abs(blue - kazaar[2]) < thresh ) {
      Serial.println("Kazaar");
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Rough morning ");
      serlcd.setPosition(2,1);
      serlcd.print("huh ?  ");
      delay(4000);
      serlcd.clear();
    }

    //Volluto
    if (abs(red - volluto[0]) < thresh && abs(green - volluto[1]) < thresh && abs(blue - volluto[2]) < thresh ) {
      Serial.println("Volluto");
      serlcd.clear();
      serlcd.setPosition(1,1); 
      serlcd.print("Volluto");
      serlcd.setPosition(2,1);
      serlcd.print("Intensity: 4/10");
      delay(2500);
      serlcd.clear();
      serlcd.setPosition(1,1);
      serlcd.print("Cup Size: 40ml");
      serlcd.setPosition(2,1);
      serlcd.print("Cereal Fruity");
      delay(2500);
      serlcd.clear();
    }
  }
}
  

   
   

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
