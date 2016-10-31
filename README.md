# Self Driving Car

This project uses a cheap RC car, an Arudino 101 and BLE Beacons to have fun building a self driving car.

The Arduino 101 has onboard Bluetooth Low Energy (BLE) and an Inertial Measurement Unit (IMU). I got a development kit of BLE beacons
to simulate GPS/location services.

The software uses a triangulation algorithm to figure out where the vehicle is. The vehicle then uses a simple probabilistic classifier
to figure out how to drive. Basically, somthing like this:

  Sensor Data -> Classifier -> Effectors
  
Where the effectors are the steering and the accelerator.

This is a pretty simple setup. ~The steering can either be 100% left, 0, or 100% right. Likewise, the accelerator can either be 100% forward, stopped, or 100% backwards.~ Turns out the H-bridge will allow a continuious range. This will make the intelligence easier as I can now use z-score normalization (z = (x - mean)/std.dev.). Previously, I was going to have to have three models to figure out left vs. right. vs. center.

All the parts are less than $100.

Fun.

## The Plan

* As of now, we need to wait for the 2.0 firmware for Curie. The current version does not support the BLE Central Role. This is needed to implement the BLE beacon triangulation.
* To mitigate, we will write the BLE code on Android. When Curie is ready, we port to Arduino.
* In addition, we can implement the Bayesian control code and test that.

That's the plan!

## What is done, what is left to do

### Done
* Hardware deconstructed and reconstructed. Chassis still in good shape.
* H-bridge, front and rear LEDs, and power all working.
* Code for movement is complete.
* Code for Bayesian classificiation is complete and tested.

### To Do
* Ultrasonic range finder needs to be hooked up and telemetry code needs to be written
* A basic integration with the intelligence

