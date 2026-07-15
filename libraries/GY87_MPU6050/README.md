# GY87_MPU6050 Library

Simple Arduino-style library for reading the MPU6050 part of the GY-87 10DOF IMU module using STM32 and Arduino IDE.

This library is intentionally simple for tutorial use. It focuses on:

- MPU6050 I2C connection
- raw accelerometer and gyroscope reading
- gyro calibration
- accelerometer conversion to `g`
- gyro conversion to `deg/s`
- basic roll and pitch from accelerometer data

## Hardware

Tested target:

- STM32 Blue Pill / STM32F103 using Arduino IDE
- GY-87 10DOF IMU module

## Wiring

| GY-87 | STM32 Blue Pill |
|---|---|
| VCC_IN | 5V |
| GND | GND |
| SDA | PB7 |
| SCL | PB6 |

Use `VCC_IN` when powering the GY-87 from 5V because it goes through the module regulator. The STM32 still uses 3.3V logic on the I2C pins.

## Arduino IDE usage

Copy the `libraries/GY87_MPU6050` folder into your Arduino libraries folder, or keep it inside this repository for documentation and tutorial reference.

Typical Arduino libraries folder on Windows:

```text
Documents/Arduino/libraries/GY87_MPU6050
```

Then restart Arduino IDE.

## Example

Open:

```text
libraries/GY87_MPU6050/examples/BasicRead/BasicRead.ino
```

The example does this:

1. starts I2C on PB7/PB6
2. detects the MPU6050 at `0x68`
3. calibrates gyro offsets while the module is still
4. prints acceleration in `g`
5. prints gyro speed in `deg/s`
6. prints basic roll and pitch angles

## Notes

Default MPU6050 settings:

- accelerometer range: `+/-2g`
- accelerometer scale: `16384 LSB/g`
- gyro range: `+/-250 deg/s`
- gyro scale: `131 LSB/(deg/s)`

Keep the sensor still during gyro calibration.

## Current limitation

This library currently supports the MPU6050 part only.

GY-87 also commonly includes:

- BMP180 pressure sensor
- HMC5883L or QMC5883L compass

Those can be added later as separate classes or extensions.
