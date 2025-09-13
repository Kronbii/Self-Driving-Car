# Self-Driving Car (Arduino Line Follower)

An educational self-driving / autonomous car prototype built with Arduino. The vehicle uses six reflective (black/white) line sensors and an IR sensor to follow a track and perform basic steering corrections by modulating two DC motors through an H-bridge.

## Features

- Six digital line (black/white) sensors for detecting track position
- IR sensor (spare / future obstacle detection)
- Differential drive using two DC motors (Left / Right)
- Simple proportional steering logic via discrete sensor triggers
- Modular firmware structure (planned refactor) and PlatformIO support (to be added)

## Repository Structure

```
firmware/            # Arduino / PlatformIO source (refactored sketch will live here)
src/                 # Original raw Arduino sketch (kept for reference)
CAD-Models/          # CAD images / models of chassis
assets/              # Images and media for documentation
docs/                # Extended documentation (architecture, wiring, calibration)
README.md            # Project overview (this file)
LICENSE              # Open-source license (MIT by default)
```

## Hardware Overview

| Component | Pins Used | Notes |
|-----------|-----------|-------|
| Line Sensors (6x) | 2,3,4,5,12,13 | Digital read (HIGH = detection) |
| IR Sensor | 8 | Currently only read; logic extension TBD |
| Left Motor | 9 (forward), 6 (reverse) | PWM capable |
| Right Motor | 10 (forward), 11 (reverse) | PWM capable |

## Current Control Logic (Summary)

On every loop:
1. Read six line sensors (V1..V6)
2. Default to forward motion (moderate speed)
3. If a specific sensor is HIGH, adjust motor speeds to steer back toward center

The existing logic uses prioritized `if/else` branches—only the first matching sensor triggers a correction.

## Roadmap

- [ ] Refactor sketch into clearer modules (sensors, motor control, navigation)
- [ ] Add PlatformIO configuration for reproducible builds
- [ ] Implement basic calibration routine
- [ ] Add obstacle detection using IR sensor
- [ ] Introduce PID-like weighted steering instead of discrete branches
- [ ] Add unit-testable logic segments (where feasible with Arduino mocks)

## Getting Started

1. Open `src/Finalprojectcodeeee.ino` in the Arduino IDE (board: Arduino Uno assumed)
2. Wire sensors and motors per the pin table above
3. Upload and place the car on a track with a solid contrasting line

PlatformIO instructions will be added once `platformio.ini` is committed.

## Contributing

Issues and pull requests are welcome. Please open a discussion for larger changes first.

## License

Released under the MIT License. See `LICENSE` for details.
