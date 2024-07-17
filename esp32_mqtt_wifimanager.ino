
#include <PubSubClient.h>
#include "global_variable.h"
#include "wifii_managerr.h"
#include "mqtt.h"

void setup() {
  //  wm.resetSettings();
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(3000);
  Serial.println("\n Starting");

  wifii_managerr_setup();
  mqtt_setup();
}

void loop() {
  if (wm_nonblocking) wm.process();
  checkButton();

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
