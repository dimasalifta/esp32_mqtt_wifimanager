
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>
#include "ScioSense_ENS160.h"  // ENS160 library

#include "global_variable.h"
#include "wifii_managerr.h"
#include "mqtt.h"
#include "dht22.h"
#include "lux.h"
#include "ens.h"


void setup() {
//  wm.resetSettings();
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(3000);
  Serial.println("\n Starting");

  wifii_managerr_setup();
  mqtt_setup();
  dht_setup();
  lux_setup();
  ens_setup();
  }

void loop() {
  if (wm_nonblocking) wm.process();
  checkButton();

  if (!client.connected()) {
    reconnect();
  }
  read_dht();
  read_lux();
  read_ens();
  client.loop();
}
