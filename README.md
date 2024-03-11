# ESP32 Solar Tracker

## Description

The ESP32 Solar Tracker is a system designed to optimize solar panel positioning for maximum sunlight exposure. This project utilizes an ESP32 microcontroller to control the movement of two servo motors, adjusting the solar panel's orientation based on real-time sunlight tracking.

## Features

- **Real-time Solar Tracking:** The system continuously monitors sunlight intensity using Light Dependent Resistors (LDRs) and adjusts the position of the solar panel to maximize sunlight exposure.
- **Efficiency Optimization:** By dynamically tracking the sun's position, the system maximizes solar energy harvesting, resulting in increased efficiency.
- **Bluetooth Control:** The ESP32 integrates Bluetooth functionality, allowing users to remotely control and monitor the solar tracking system via a smartphone or other Bluetooth-enabled device.
- **Emergency Mode (Panic):** In case of emergencies or adverse conditions, the system can be activated into a panic mode, where the solar panel moves to a predefined safe position.

## Requirements

The ESP32 Solar Tracker has the following hardware requirements:

- **Minimum MCU:** 256-512kB Flash, 16-24kB SRAM, 16MHz
- **Recommended:** 512kB-1MB+ Flash, 24-32kB+ SRAM, 32-48MHz+

The system is compatible with various microcontrollers, including but not limited to:

- **Definitely Works:** GIGA, Portenta (any), ESP32/8266, Teensy 3.5+, STM32 (>256kB), Pico/RP2040 (any)
- **May Work (with external data/minimal UI):** Uno R4, Nano 33 (any), MKR (any), Due/Zero, STM32 (256kB)
- **May Work (with heavy adjustments/limited build):** ATMega2560, Genuino 101, Teensy 3.2 (/3.1), STM32F0
- **Definitely Won't Work:** Uno (classic up to R3), Nano (classic and Every), Leonardo/Duemilanove, Micro, Pro, Esplora, Teensy 2/LC, STM8 (|32<256kB), ATtiny (any)

## Components

The ESP32 Solar Tracker requires the following components:

- ESP32
- 4x Light Dependent Resistors (LDRs)
- 2x Servo Motors
- 1x Bluetooth Module (integrated into ESP32)
- Resistors

## Connection Scheme

![Arduino Connection Scheme]([link_to_scheme_image.png]([https://i.postimg.cc/SQ6hHyhy/esquema-solar-tracker.png](https://csg.tinkercad.com/things/36ccajL4mU0/t725.png?rev=1710183076127000000&s=&v=1&type=circuits)))

This connection scheme illustrates the project setup using an Arduino to control the components. The connection details include the pins used on the Arduino and how they are connected to various project components such as sensors, actuators, and communication modules.

Detailed description of the connection scheme, explaining each component and its function.

## Installation and Setup

1. **Clone the Repository:** 
   ```bash
   git clone https://github.com/Yagoox/ESP32-Light-Tracker
