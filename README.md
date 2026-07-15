# STM32 Arduino Projects

A collection of STM32 projects developed using the Arduino IDE and STM32 Arduino Core.

## Repository structure

```text
STM32_ARDUINO/
├── projects/
│   ├── LED_Blink/
│   │   └── LED_Blink.ino
│   └── Digital_Read/
│       ├── Digital_Read.ino
│       ├── README.md
│       └── circuit_diagram.svg
├── libraries/
│   └── GY87_MPU6050/
│       ├── src/
│       │   ├── GY87_MPU6050.h
│       │   └── GY87_MPU6050.cpp
│       ├── examples/
│       │   └── BasicRead/
│       │       └── BasicRead.ino
│       └── README.md
├── tools/
│   ├── STM32CubeProgrammer/
│   │   └── README.md
│   └── FTDI_STM32/
│       ├── README.md
│       └── ftdi_stm32_wiring.svg
└── README.md
```

## Requirements

- Arduino IDE
- STM32 Arduino Core
- STM32CubeProgrammer
- STM32 development board such as the Blue Pill
- ST-LINK or supported USB/UART programmer

## Projects

### LED Blink

Basic onboard LED test for an STM32 Blue Pill using Arduino IDE.

### Digital Read

Basic push button input tutorial using `digitalRead()` on STM32 Blue Pill.

- Input pin: PA0
- Output pin: PC13 onboard LED
- Button wiring: PA0 to push button to GND
- Uses internal pull-up resistor

[Open the Digital Read project](projects/Digital_Read/README.md)

## Libraries

### GY87_MPU6050

Simple Arduino-style library for reading the MPU6050 part of the GY-87 10DOF IMU module.

Features:

- raw accelerometer and gyroscope reading
- gyro calibration
- acceleration in `g`
- angular velocity in `deg/s`
- basic roll and pitch angle calculation

[Open the GY87_MPU6050 library](libraries/GY87_MPU6050/README.md)

## Tools and setup guides

### STM32CubeProgrammer

Installation and troubleshooting guide for STM32CubeProgrammer on Windows.

### FTDI to STM32 Blue Pill

Tagalog wiring and troubleshooting guide for connecting an FTDI adapter to the STM32 Blue Pill for Serial Monitor and UART upload.

[Open the FTDI to STM32 guide](tools/FTDI_STM32/README.md)
