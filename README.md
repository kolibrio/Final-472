# Final-472

# Advanced Listening Unit

This project uses a Teensy microcontroller with SN754410NE to drive an areay of TCT40 16-T 40kHz ultrasonic transducers, combined with the HC SR04 ultrasonic distance sensor.

The idea behind this project is to make a strange feedback loop to influence amplitude modulation with the 40kHz tone in order to produce a beam of disruptive sound into the viewers head.I am inspired by sound weapons used by the military and anti riot police. I am also inspired by neuroelectric frequencies which shape our emotion and cognition.

The device works as follows: the sensor picks up the viewers distance and stores this as a variable. This variable is used to modulate the amplitude of the 40kHz PWM signal sent to the transducer driver. The signal is very erratic and wavers, but the closer you get, the slower it switches between audible frequency. It also influences the pitch range, though unpredictably.

When the viewer is not directly in front of the device, they will hear only an annoying high pitched buzz. Directly in front, however, up to a 3 meters away, they will feel a sound produced as the air vibrates into their ears and skull. This will sound very distorted and much lower pitch.

My experience with it was very intriguing and somewhat uncomfortable. I think this device is safe, but there isn't a lot of understanding of the risks to ones mind if they are in prolonged exposure to it.

