#ifndef GY87_MPU6050_H
#define GY87_MPU6050_H

#include <Arduino.h>
#include <Wire.h>

class GY87_MPU6050 {
public:
  struct RawData {
    int16_t ax;
    int16_t ay;
    int16_t az;
    int16_t temp;
    int16_t gx;
    int16_t gy;
    int16_t gz;
  };

  GY87_MPU6050(uint8_t address = 0x68);

  bool begin(TwoWire &wirePort = Wire);
  bool isConnected();
  bool read();

  void calibrateGyro(uint16_t samples = 1000, uint16_t sampleDelayMs = 3);
  void setGyroOffsets(float xOffset, float yOffset, float zOffset);
  void getGyroOffsets(float &xOffset, float &yOffset, float &zOffset);

  int16_t rawAX() const;
  int16_t rawAY() const;
  int16_t rawAZ() const;
  int16_t rawGX() const;
  int16_t rawGY() const;
  int16_t rawGZ() const;

  float accelX() const;
  float accelY() const;
  float accelZ() const;

  float gyroX() const;
  float gyroY() const;
  float gyroZ() const;

  float temperatureC() const;
  float roll() const;
  float pitch() const;

private:
  TwoWire *_wire;
  uint8_t _address;
  RawData _raw;

  float _gxOffset;
  float _gyOffset;
  float _gzOffset;

  bool writeRegister(uint8_t reg, uint8_t value);
  bool readRegisters(uint8_t startReg, uint8_t *buffer, uint8_t length);
};

#endif
