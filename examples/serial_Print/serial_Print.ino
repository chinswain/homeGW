#include <homeGW.h>
#include <digoo.h>

HomeGW gw(1);
digoo station1;

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

}
