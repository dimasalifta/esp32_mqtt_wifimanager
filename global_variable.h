
#define TRIGGER_PIN 0
#define DHTPIN 15     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT22     // DHT 22 (AM2302)

const char* mqtt_server = "dimasalifta.tech";
const char* mqtt_topic = "smarturbanfarming/kit/1";

bool wm_nonblocking = false; // change to true to use non blocking
