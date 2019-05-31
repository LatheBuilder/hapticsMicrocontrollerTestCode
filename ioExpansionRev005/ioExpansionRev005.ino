#include <Wire.h>
#include "Adafruit_MCP23008.h"

// Basic toggle test for i/o expansion. flips pin #0 of a MCP23008 i2c
// pin expander up and down. Public domain

// Connect pin #1 of the expander to Analog 5 (i2c clock)
// Connect pin #2 of the expander to Analog 4 (i2c data)
// Connect pins #3, 4 and 5 of the expander to ground (address selection)
// Connect pin #6 and 18 of the expander to 5V (power and reset disable)
// Connect pin #9 of the expander to ground (common ground)

// Output #0 is on pin 10 so connect an LED or whatever from that to ground

//rev 005 - 

Adafruit_MCP23008 mcp;
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
byte outputTestDelay = 50; //delay between state toggle in ms
byte ouputIndicatorDelay = 100; //indicator delay between state toggle in ms


  
void setup() {  
  mcp.begin();      // use default address 0
  mcp.pinMode(0, OUTPUT);
  mcp.pinMode(1, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.pinMode(3, OUTPUT);
  mcp.pinMode(4, OUTPUT);
  mcp.pinMode(5, OUTPUT);
  mcp.pinMode(6, OUTPUT);
  mcp.pinMode(7, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

//  Serial.begin(9600); //init the monitored serial com (see serial event example)
//  inputString.reserve(200); // reserve 200 bytes for the inputString:
  
}

void loop() {
  outputTest(); //temporarily commented out test method
//  serialEvent();
//  // print the string when a newline arrives:
//  if (stringComplete) {
//    Serial.println(inputString);
//    // clear the string:
//    inputString = "";
//    stringComplete = false;
//    }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
  NOTE TO CHARLIE: THIS DOESN'T WORK QUITE RIGHT YET
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void lightBuiltInLed(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(ouputIndicatorDelay);
    digitalWrite(LED_BUILTIN, LOW);

}

void outputTest() {
  mcp.digitalWrite(0, HIGH); // cycles through expander outputs one by one. on for 50ms, off for 50ms.
  delay(outputTestDelay);
  mcp.digitalWrite(0, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(1, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(1, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(2, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(2, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(3, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(3, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(4, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(4, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(5, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(5, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(6, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(6, LOW);
  delay(outputTestDelay);
  mcp.digitalWrite(7, HIGH);
  delay(outputTestDelay);
  mcp.digitalWrite(7, LOW);
  delay(outputTestDelay);

}

//temp space to save retyping:
//digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  Serial.println("text output to serial port");
