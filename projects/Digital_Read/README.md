# STM32 Blue Pill Digital Read

Basic `digitalRead()` tutorial for STM32 Blue Pill using Arduino IDE.

This example reads a push button connected to **PA0** and controls the onboard LED on **PC13**.

## Goal

When the button is pressed, the onboard LED turns ON.

When the button is released, the onboard LED turns OFF.

## Components

- STM32 Blue Pill / STM32F103 board
- Push button
- Jumper wires
- ST-LINK or FTDI uploader
- Arduino IDE with STM32 board support

## Pin connection

| Component | STM32 Blue Pill pin |
|---|---|
| Push button side 1 | PA0 |
| Push button side 2 | GND |
| Onboard LED | PC13 |

This code uses the STM32 internal pull-up resistor using:

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
```

So the button logic is:

| Button state | Pin reading |
|---|---|
| Released | HIGH |
| Pressed | LOW |

## Circuit diagram

Open the SVG file:

[`circuit_diagram.svg`](circuit_diagram.svg)

Simple connection:

```text
STM32 PA0 ---- Push Button ---- GND
STM32 PC13 --- Onboard LED
```

## Arduino IDE settings

Recommended settings for Blue Pill:

```text
Board: Generic STM32F1 series
Board part number: BluePill F103C8 or your actual chip
Upload method: STM32CubeProgrammer SWD, ST-LINK, or Serial depending on your setup
```

## Code behavior

```text
Button released → PA0 reads HIGH → PC13 LED OFF
Button pressed  → PA0 reads LOW  → PC13 LED ON
```

## Notes

- PC13 onboard LED on many Blue Pill boards is active LOW.
- Use 3.3V logic only for STM32 pins.
- Do not connect 5V signal directly to STM32 GPIO.
- If the button reading is unstable, check wiring and add a small debounce delay or software debounce.

## Video expansion ideas

You can expand this tutorial by showing:

1. What `digitalRead()` means.
2. Difference between `INPUT`, `INPUT_PULLUP`, and `INPUT_PULLDOWN`.
3. Why button pressed becomes `LOW` with pull-up wiring.
4. How to control an LED using button input.
5. Simple debounce explanation.
6. Serial Monitor debugging using FTDI.
