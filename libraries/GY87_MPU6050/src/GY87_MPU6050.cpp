#include "GY87_MPU6050.h"
#include <math.h>

GY87_MPU6050::GY87_MPU6050(uint8_t address) {
  _wire = &Wire;
  _address = address;

  _raw = {0, 0, 0, 0, 0, 0, 0};

  _gxOffset = 0;
  _gyOffset = 0;
  _gzOffset = 0;
}

bool GY87_MPU6050::begin(TwoWire &wirePort) {
  _wire = &wirePort;

  if (!isConnected()) {
    return false;
  }

  // Wake up MPU6050 from sleep mode.
  if (!writeRegister(0x6B, 0x00)) {
    return false;
  }

  // Accelerometer range: +/-2g. Sensitivity = 16384 LSB/g.
  writeRegister(0x1C, 0x00);

  // Gyroscope range: +/-250 deg/s. Sensitivity = 131 LSB/(deg/s).
  writeRegister(0x1B, 0x00);

  delay(100);
  return true;
}

bool GY87_MPU6050::isConnected() {
  _wire->beginTransmission(_address);
  return (_wire->endTransmission() == 0);
}

bool GY87_MPU6050::read() {
  uint8_t buffer[14];

  if (!readRegisters(0x3B, buffer, 14)) {
    return false;
  }

  _raw.ax = (int16_t)((buffer[0] << 8) | buffer[1]);
  _raw.ay = (int16_t)((buffer[2] << 8) | buffer[3]);
  _raw.az = (int16_t)((buffer[4] << 8) | buffer[5]);
  _raw.temp = (int16_t)((buffer[6] << 8) | buffer[7]);
  _raw.gx = (int16_t)((buffer[8] << 8) | buffer[9]);
  _raw.gy = (int16_t)((buffer[10] << 8) | buffer[11]);
  _raw.gz = (int16_t)((buffer[12] << 8) | buffer[13]);

  return true;
}

void GY87_MPU6050::calibrateGyro(uint16_t samples, uint16_t sampleDelayMs) {
  long gxSum = 0;
  long gySum = 0;
  long gzSum = 0;
  uint16_t validSamples = 0;

  for (uint16_t i = 0; i < samples; i++) {
    if (read()) {
      gxSum += _raw.gx;
      gySum += _raw.gy;
      gzSum += _raw.gz;
      validSamples++;
    }
    delay(sampleDelayMs);
  }

  if (validSamples > 0) {
    _gxOffset = gxSum / (float)validSamples;
    _gyOffset = gySum / (float)validSamples;
    _gzOffset = gzSum / (float)validSamples;
  }
}

void GY87_MPU6050::setGyroOffsets(float xOffset, float yOffset, float zOffset) {
  _gxOffset = xOffset;
  _gyOffset = yOffset;
  _gzOffset = zOffset;
}

void GY87_MPU6050::getGyroOffsets(float &xOffset, float &yOffset, float &zOffset) {
  xOffset = _gxOffset;
  yOffset = _gyOffset;
  zOffset = _gzOffset;
}

int16_t GY87_MPU6050::rawAX() const { return _raw.ax; }
int16_t GY87_MPU6050::rawAY() const { return _raw.ay; }
int16_t GY87_MPU6050::rawAZ() const { return _raw.az; }
int16_t GY87_MPU6050::rawGX() const { return _raw.gx; }
int16_t GY87_MPU6050::rawGY() const { return _raw.gy; }
int16_t GY87_MPU6050::rawGZ() const { return _raw.gz; }

float GY87_MPU6050::accelX() const {
  return _raw.ax / 16384.0;
}

float GY87_MPU6050::accelY() const {
  return _raw.ay / 16384.0;
}

float GY87_MPU6050::accelZ() const {
  return _raw.az / 16384.0;
}

float GY87_MPU6050::gyroX() const {
  return (_raw.gx - _gxOffset) / 131.0;
}

float GY87_MPU6050::gyroY() const {
  return (_raw.gy - _gyOffset) / 131.0;
}

float GY87_MPU6050::gyroZ() const {
  return (_raw.gz - _gzOffset) / 131.0;
}

float GY87_MPU6050::temperatureC() const {
  return (_raw.temp / 340.0) + 36.53;
}

float GY87_MPU6050::roll() const {
  return atan2(accelY(), accelZ()) * 180.0 / PI;
}

float GY87_MPU6050::pitch() const {
  float ax = accelX();
  float ay = accelY();
  float az = accelZ();
  return atan2(-ax, sqrt((ay * ay) + (az * az))) * 180.0 / PI;
}

bool GY87_MPU6050::writeRegister(uint8_t reg, uint8_t value) {
  _wire->beginTransmission(_address);
  _wire->write(reg);
  _wire->write(value);
  return (_wire->endTransmission() == 0);
}

bool GY87_MPU6050::readRegisters(uint8_t startReg, uint8_t *buffer, uint8_t length) {
  _wire->beginTransmission(_address);
  _wire->write(startReg);

  if (_wire->endTransmission(false) != 0) {
    return false;
  }

  uint8_t bytesRead = _wire->requestFrom(_address, length);

  if (bytesRead != length) {
    return false;
  }

  for (uint8_t i = 0; i < length; i++) {
    buffer[i] = _wire->read();
  }

  return true;
}
