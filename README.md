# STM32 Arduino Projects

A collection of STM32 projects developed using the Arduino IDE and STM32 Arduino Core.

## Repository structure

```text
STM32_ARDUINO/
├── projects/
│   ├── LED_Blink/
│   │   └── LED_Blink.ino
│   ├── Digital_Read/
│   │   ├── Digital_Read.ino
│   │   ├── README.md
│   │   └── circuit_diagram.svg
│   └── Analog_Write/
│       ├── Analog_Write.ino
│       ├── README.md
│       └── circuit_diagram.svg
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

### Analog Write (PWM)

Basic LED brightness control tutorial using `analogWrite()` PWM on STM32 Blue Pill.

- PWM output pin: PA6 / TIM3 Channel 1
- Output device: External LED
- LED resistor: 220 Ω to 330 Ω
- PWM range used: 0 to 255
- Example behavior: Smooth fade from OFF to full brightness and back to OFF

[Open the Analog Write project](projects/Analog_Write/README.md)

## Tools and setup guides

### STM32CubeProgrammer

Installation and troubleshooting guide for STM32CubeProgrammer on Windows.

### FTDI to STM32 Blue Pill

Tagalog wiring and troubleshooting guide for connecting an FTDI adapter to the STM32 Blue Pill for Serial Monitor and UART upload.

[Open the FTDI to STM32 guide](tools/FTDI_STM32/README.md)
