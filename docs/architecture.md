# Architecture & Control Logic

## Overview
The self-driving (line-following) car uses six digital reflectance sensors aligned laterally across the front underside of the chassis to detect the position of a contrasting track (typically black line on white surface). The firmware translates sensor activation into differential motor speed adjustments.

## Pin Mapping
```
Line Sensors: 2,3,4,5,12,13  (Left->Right order to be verified)
IR Sensor:    8 (future obstacle detection)
Left Motor:   9 (forward PWM), 6 (reverse PWM)
Right Motor:  10 (forward PWM), 11 (reverse PWM)
```

## Data Flow
1. Read all six line sensors (digital HIGH/LOW)
2. Evaluate in priority order with `if/else if` cascade
3. Apply one correction per loop iteration (first match wins)
4. Default: mild forward speed if no sensor is HIGH

## Current Limitations
- Priority cascade ignores multi-sensor combinations (no weighted center calculation)
- No debounce / filtering on sensor noise
- IR sensor unused
- No speed ramping or acceleration limiting

## Planned Improvements
| Area | Improvement | Benefit |
|------|-------------|---------|
| Steering | Weighted steering (array -> error value) | Smoother tracking |
| Sensors | Calibration routine | Robustness across lighting |
| Obstacle | Use IR sensor for stop/avoid | Added autonomy |
| Code | Modularize into motor, sensors, control files | Maintainability |
| Control | PID or PD correction | Reduced oscillation |

## Proposed Refactor Structure
```
firmware/
  include/
    sensors.h
    motors.h
    control.h
  src/
    main.cpp
    sensors.cpp
    motors.cpp
    control.cpp
  platformio.ini
```

## High-Level Control Pseudocode
```
loop() {
  readSensors(values);
  int error = computeLineError(values); // negative=left, positive=right
  int correction = Kp * error; // (future: + Kd * (error - lastError))
  driveBase(baseSpeed - correction, baseSpeed + correction);
}
```

## Calibration Concept
- Place car over white background: record baseline (min reflectance)
- Place over line: record max
- Derive threshold = (min + max)/2 per sensor

---
(Adjust this document as hardware details are confirmed.)
