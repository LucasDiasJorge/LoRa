#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Transmitter");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.println("Sending packet...");

  // Send a packet
  LoRa.beginPacket();
  LoRa.print("Hello LoRa!");
  LoRa.endPacket();

  delay(1000);
}
