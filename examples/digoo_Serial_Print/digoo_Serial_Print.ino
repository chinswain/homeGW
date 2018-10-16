#include <homeGW.h>
#include <digoo.h>

HomeGW gw(3);
digoo station1;
digoo station2;
digoo station3;

uint64_t prev_p = 0;

#define RF_RECEIVER_PIN 23 

void setup() {
  Serial.begin(115200);
  // pull-down RF pin (less noise)
  pinMode(RF_RECEIVER_PIN, OUTPUT);
  digitalWrite(RF_RECEIVER_PIN, LOW);
  pinMode(RF_RECEIVER_PIN, INPUT);
  digitalWrite(RF_RECEIVER_PIN, LOW);
  gw.setup(RF_RECEIVER_PIN);
  gw.registerPlugin(&station1);
  gw.registerPlugin(&station2);
  gw.registerPlugin(&station3);
}

void loop() {

 
  uint64_t p = 0;

  if (station1.available())
    if ((p = station1.getPacket())) {
      if (p == prev_p) {

        Serial.print("ID: ");  Serial.print(station1.getId(p));
        Serial.print("\tChannel: ");  Serial.print(station1.getChannel(p));
        Serial.print("\tBattery: ");  Serial.print(station1.getBattery(p));
        Serial.print("\tTemperature: ");  Serial.print(station1.getTemperature(p));
        Serial.print("\tHumidity: ");  Serial.print(station1.getHumidity(p));
        Serial.print("\tString: ");  Serial.println(station1.getString(p));

        p = 0;
      }
      prev_p = p;
    }
  
  if (station2.available())
    if ((p = station2.getPacket())) {
      if (p == prev_p) {

        Serial.print("ID: ");  Serial.print(station2.getId(p));
        Serial.print("\tChannel: ");  Serial.print(station2.getChannel(p));
        Serial.print("\tBattery: ");  Serial.print(station2.getBattery(p));
        Serial.print("\tTemperature: ");  Serial.print(station2.getTemperature(p));
        Serial.print("\tHumidity: ");  Serial.print(station2.getHumidity(p));
        Serial.print("\tString: ");  Serial.println(station2.getString(p));

        p = 0;
      }
      prev_p = p;
    }

  if (station3.available())
    if ((p = station3.getPacket())) {
      if (p == prev_p) {

        Serial.print("ID: ");  Serial.print(station3.getId(p));
        Serial.print("\tChannel: ");  Serial.print(station3.getChannel(p));
        Serial.print("\tBattery: ");  Serial.print(station3.getBattery(p));
        Serial.print("\tTemperature: ");  Serial.print(station3.getTemperature(p));
        Serial.print("\tHumidity: ");  Serial.print(station3.getHumidity(p));
        Serial.print("\tString: ");  Serial.println(station3.getString(p));

        p = 0;
      }
      prev_p = p;
    }
  
}
