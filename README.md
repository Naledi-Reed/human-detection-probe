<div align="center">

# 🚨 Human Detection Probe

**Arduino prototype with PIR detection, LCD status and audio-visual alerts**

[![Firmware](https://img.shields.io/badge/OPEN_ARDUINO_FIRMWARE-B6FF00?style=for-the-badge&logo=arduino&logoColor=07110D)](firmware/human_detection_probe/human_detection_probe.ino)
[![Pin Map](https://img.shields.io/badge/OPEN_PIN_MAP-101820?style=for-the-badge&logo=arduino&logoColor=B6FF00)](docs/PIN-MAP.csv)
[![Download](https://img.shields.io/badge/DOWNLOAD_COMPLETE_PROJECT-B6FF00?style=for-the-badge&logo=github&logoColor=07110D)](https://github.com/Naledi-Reed/human-detection-probe/archive/refs/heads/main.zip)

</div>

## Purpose

This search-and-rescue concept uses a PIR sensor as a basic presence-detection input. When infrared movement is detected, the Arduino activates an LED, buzzer and LCD warning. A pushbutton runs a diagnostic output test.

## Actual project files

| File | Purpose |
|---|---|
| [human_detection_probe.ino](firmware/human_detection_probe/human_detection_probe.ino) | Complete Arduino firmware |
| [BILL-OF-MATERIALS.csv](docs/BILL-OF-MATERIALS.csv) | Editable component list |
| [PIN-MAP.csv](docs/PIN-MAP.csv) | Editable wiring and pin allocation |
| [technical-summary.md](docs/technical-summary.md) | Technical explanation |
| [circuit-schematic.png](evidence/circuit-schematic.png) | Circuit schematic |
| [tinkercad-circuit-diagram.png](evidence/tinkercad-circuit-diagram.png) | Prototype layout |

## Run it

1. Download the repository ZIP or clone it.
2. Open the INO file in Arduino IDE or recreate it in Tinkercad Circuits.
3. Build the circuit using the pin map and diagrams.
4. Start the simulation.
5. Trigger the PIR sensor and test the diagnostic button.

## Important limitation

A PIR sensor detects changes in infrared energy; it does not prove that a human has been identified. A real rescue device requires additional sensors, environmental protection and professional validation.

**Module origin:** IOT261 — Internet of Things  
**Status:** Functional portfolio prototype with firmware and editable build files
