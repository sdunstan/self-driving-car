# Self Driving Car

This project uses a cheap RC car, an Arudino 101 and BLE Beacons to have fun building a self driving car.

The Arduino 101 has onboard Bluetooth Low Energy (BLE) and an Inertial Measurement Unit (IMU). I got a development kit of BLE beacons
to simulate GPS/location services.

The software uses a triangulation algorithm to figure out where the vehicle is. The vehicle then uses a simple probabilistic classifier
to figure out how to drive. Basically, somthing like this:

  Sensor Data -> Classifier -> Effectors
  
Where the effectors are the steering and the accelerator.

This is a pretty simple setup. The steering can either be 100% left, 0, or 100% right. Likewise, the accelerator can either be 100% forward, 
stopped, or 100% backwards.

All the parts are less than $100.

Fun.
