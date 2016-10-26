// Need to wait for 2.0 release of Curie/Arduino101 firmware. According to this post (http://forum.arduino.cc/index.php?topic=425387.0)
// it will have support for BLE Central Role. We need the BLE Central Role to be able to search for BLE Beacons.
// In the mean time, we can wire up the H-Bridge and start working on the code to triangulate the beacons, etc.

#include "NaiveBayes.h"

#define HEADLIGHTS 2
#define TAILLIGHTS 3

void setup() {
  Serial.print("starting up...\n");
  Serial.begin(9600);      // open the serial port at 9600 bps
  // put your setup code here, to run once:
  pinMode(HEADLIGHTS, OUTPUT);
  pinMode(TAILLIGHTS, OUTPUT);

  NaiveBayes nb;
  nb.addModel(1, 0.01, 0.001);
  nb.addModel(2, 0.02, 0.002);

  Category categories[2];
  categories[0].id = 1;
  categories[1].id = 2;
  double observations[2];
  observations[0] = -0.01;
  observations[1] = 0.15;
  nb.classify(categories, 2, observations, 2);  
}

void loop() {
  Serial.print("Lights on\n");
  headlights(true);
  taillights(false);
  delay(2000);
  Serial.print("Lights off\n");
  headlights(false);
  taillights(true);
  delay(2000);

}

void lights(int pin, boolean on) {
  if (on) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }  
}

void headlights(boolean on) {
  lights(HEADLIGHTS, on);
}

void taillights(boolean on) {
  lights(TAILLIGHTS, on);
}


