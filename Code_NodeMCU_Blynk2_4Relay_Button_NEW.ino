

#define BLYNK_TEMPLATE_ID "TMPL3ZZnrQYLb"
#define BLYNK_TEMPLATE_NAME "HomeAutomantion"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define BLYNK_DEBUG
#define USE_NODE_MCU_BOARD

#define RelayPin1 5  //D1
#define VPIN_BUTTON_1    V1


// Relay State
bool toggleState_1 = LOW;

#include "BlynkEdgent.h"

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_BUTTON_1);
  
}

// When App button is pushed - switch the state

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
  digitalWrite(RelayPin1, HIGH);
  
  BlynkEdgent.begin();

  Blynk.virtualWrite(VPIN_BUTTON_1, toggleState_1);
  
}

void loop() {

    BlynkEdgent.run();
    
  
}
