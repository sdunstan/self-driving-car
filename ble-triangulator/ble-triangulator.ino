// Need to wait for 2.0 release of Curie/Arduino101 firmware. According to this post (http://forum.arduino.cc/index.php?topic=425387.0)
// it will have support for BLE Central Role. We need the BLE Central Role to be able to search for BLE Beacons.
// In the mean time, we can wire up the H-Bridge and start working on the code to triangulate the beacons, etc.

#include "NaiveBayes.h"

#define HEADLIGHTS 2
#define TAILLIGHTS 3

// motor 1 drive
int enA = 5;
int in1 = 10;
int in2 = 11;
// motor two steering
int enB = 6;
int in3 = 12;
int in4 = 13;

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps
  Serial.print("starting up...\n");
  // put your setup code here, to run once:
  pinMode(HEADLIGHTS, OUTPUT);
  pinMode(TAILLIGHTS, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

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

  forward(255);
  delay(1000);
  stop();
  delay(500);
  backward(255);
  delay(1000);
  stop();

  left();
  delay(1000);
  right();
  delay(1000);
  center();
}

void loop() {
  forward(255);
  delay(2000);
  stop();
  delay(2000);
  backward(255);
  delay(2000);
  stop();
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

/*
 * Speed is a number between 0 and 255.
 */
void forward(int speed) {
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);  
  headlights(true);
  taillights(false);
}

/*
 * Speed is a number between 0 and 255.
 */
void backward(int speed) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enA, speed);
  headlights(false);
  taillights(true);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  headlights(false);
  taillights(false);
}

void left() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);  
}

void right() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);  
}

void center() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}

void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  delay(2000);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


