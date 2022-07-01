// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#define USE_NODE_MCU_BOARD

// define the GPIO connected with Relays and switches
#define RelayPin1 5  //D1

//Change the virtual pins according the rooms
#define VPIN_BUTTON_1    V1

// Relay State
bool toggleState_1 = LOW; //Define integer to remember the toggle state for relay 1

#include "BlynkEdgent.h"

BLYNK_WRITE(VPIN_BUTTON_1) {
  toggleState_1 = param.asInt();
  if(toggleState_1 == 1){
    digitalWrite(RelayPin1, LOW);
  }
  else { 
    digitalWrite(RelayPin1, HIGH);
  }
}



void setup()
{
  Serial.begin(115200);
  delay(100);
  
  pinMode(RelayPin1, OUTPUT);
  
  
  
  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  
  BlynkEdgent.begin();

  Blynk.virtualWrite(VPIN_BUTTON_1, toggleState_1);
}

void loop() {

    BlynkEdgent.run();  
}
