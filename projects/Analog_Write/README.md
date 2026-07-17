# STM32 Blue Pill Analog Write (PWM)

Basic `analogWrite()` tutorial for STM32 Blue Pill using Arduino IDE.

This example generates PWM on **PA6** to smoothly increase and decrease the brightness of an external LED.

## Goal

The LED gradually becomes brighter from OFF to full brightness.

After reaching full brightness, the LED gradually becomes dimmer until it turns OFF again.

## Components

- STM32 Blue Pill / STM32F103 board
- LED
- 220 Ω to 330 Ω resistor
- Breadboard
- Jumper wires
- ST-LINK or FTDI uploader
- Arduino IDE with STM32 board support

## Pin connection

| Component | STM32 Blue Pill connection |
|---|---|
| PA6 PWM output | Resistor input |
| Resistor output | LED anode (+) |
| LED cathode (-) | GND |

Simple connection:

```text
STM32 PA6 ---- 220 Ω to 330 Ω resistor ---- LED anode (+)
STM32 GND -------------------------------- LED cathode (-)
```

## Circuit diagram

Open the SVG file:

[`circuit_diagram.svg`](circuit_diagram.svg)

## What analogWrite does

On PA6, `analogWrite()` uses the STM32 hardware timer to generate a PWM signal.

PWM rapidly switches the pin between LOW and HIGH. Changing the duty cycle changes the average power delivered to the LED, which changes its apparent brightness.

This tutorial uses the default 8-bit value range:

| analogWrite value | Approximate duty cycle | LED output |
|---:|---:|---|
| 0 | 0% | OFF |
| 64 | 25% | Dim |
| 127 | 50% | Medium |
| 191 | 75% | Bright |
| 255 | 100% | Full brightness |

Example:

```cpp
analogWrite(PWM_LED_PIN, 127);
```

This produces approximately 50% duty cycle on the PWM output.

## Arduino IDE settings

Recommended settings for Blue Pill:

```text
Board: Generic STM32F1 series
Board part number: BluePill F103C8 or your actual chip
Upload method: STM32CubeProgrammer SWD, ST-LINK, or Serial depending on your setup
```

## Code behavior

```text
0 → 255   = LED gradually becomes brighter
255 → 0   = LED gradually becomes dimmer
```

The program changes the PWM value every 10 milliseconds to create a smooth fading effect.

## Important notes

- PA6 is a PWM-capable pin connected to TIM3 Channel 1 on STM32F103.
- `analogWrite()` on PA6 produces PWM, not a true variable DC voltage.
- The STM32 Arduino Core uses a default PWM frequency of 1000 Hz.
- Always use a current-limiting resistor with the LED.
- STM32 GPIO uses 3.3V logic.
- Do not connect a DC motor, high-power LED, relay, or other large load directly to PA6. Use a transistor, MOSFET, or driver circuit.
- Use a timer-capable pin for PWM. A pin without timer or DAC capability may behave only like a digital HIGH or LOW output.

## Video expansion ideas

You can expand this tutorial by showing:

1. What `analogWrite()` means.
2. Why `analogWrite()` is PWM and not a true analog voltage.
3. Meaning of duty cycle.
4. LED brightness at values 0, 64, 127, 191, and 255.
5. How the `for` loop creates the fade effect.
6. How to change PWM frequency using `analogWriteFrequency()`.
7. How to use PWM for DC motor speed control through a MOSFET or motor driver.