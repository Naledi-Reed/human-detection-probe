# Human Detection Probe

An Arduino-based search-and-rescue concept that detects changes in infrared energy and produces immediate visual and audio alerts.

**Status:** Functional portfolio prototype  
**Module:** IOT261 - Internet of Things  
**Platform:** Arduino Uno and Tinkercad

## The problem

After an earthquake or structural collapse, rescuers need simple tools that can indicate possible human presence in areas that are difficult to inspect safely.

This prototype uses a PIR sensor as a basic presence-detection input. When movement is detected, the system activates an LED, buzzer and LCD warning.

## Hardware design

- Arduino Uno
- PIR motion sensor
- 16x2 LCD
- LED
- Piezo buzzer
- Pushbutton for diagnostics
- Resistors and breadboard wiring

## System behaviour

```text
PIR detects movement
        |
        v
Arduino evaluates input
        |
        +--> LED warning
        +--> Buzzer alert
        +--> LCD message

Diagnostic button
        |
        +--> Tests LED and buzzer
```

## Firmware

[Open the Arduino source code](firmware/human_detection_probe/human_detection_probe.ino)

The firmware includes:

- PIR input monitoring
- Audio and visual alert control
- LCD status messages
- Pushbutton diagnostic test
- Basic button debounce
- Automatic return to the ready state

## Run the simulation

1. Rebuild the circuit using the diagram in the evidence folder.
2. Open the Arduino sketch in the Arduino IDE or Tinkercad Circuits.
3. Confirm the pin allocation in the source comments.
4. Start the simulation.
5. Trigger the PIR sensor to test the detection alert.
6. Press the diagnostic button to test the output components.

## Evidence

[View the circuit diagram and schematic](evidence/)

## Limitations

A PIR sensor indicates changes in infrared energy; it does not prove that a person has been identified. A real rescue device would require additional sensors, environmental protection, testing and professional validation.

## Skills demonstrated

- Embedded-system design
- Arduino C++
- Sensor input and actuator output
- Circuit modelling
- Safety-aware technical documentation
