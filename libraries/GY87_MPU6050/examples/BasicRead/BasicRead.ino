#include <Wire.h>
#include <GY87_MPU6050.h>

GY87_MPU6050 imu;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // STM32 Blue Pill / STM32F103 I2C1 pins
  Wire.setSDA(PB7);
  Wire.setSCL(PB6);
  Wire.begin();

  Serial.println("GY-87 MPU6050 Basic Read");

  if (!imu.begin(Wire)) {
    Serial.println("MPU6050 not detected. Check wiring and I2C address.");
    while (1);
  }

  Serial.println("MPU6050 detected.");
  Serial.println("Keep the sensor still. Calibrating gyro...");

  imu.calibrateGyro(1000, 3);

  float gxOffset, gyOffset, gzOffset;
  imu.getGyroOffsets(gxOffset, gyOffset, gzOffset);

  Serial.println("Calibration done.");
  Serial.print("GX Offset: "); Serial.println(gxOffset);
  Serial.print("GY Offset: "); Serial.println(gyOffset);
  Serial.print("GZ Offset: "); Serial.println(gzOffset);
  Serial.println();
}

void loop() {
  if (imu.read()) {
    Serial.print("AX: "); Serial.print(imu.accelX(), 3);
    Serial.print("g AY: "); Serial.print(imu.accelY(), 3);
    Serial.print("g AZ: "); Serial.print(imu.accelZ(), 3);

    Serial.print(" | GX: "); Serial.print(imu.gyroX(), 2);
    Serial.print(" dps GY: "); Serial.print(imu.gyroY(), 2);
    Serial.print(" dps GZ: "); Serial.print(imu.gyroZ(), 2);

    Serial.print(" | Roll: "); Serial.print(imu.roll(), 2);
    Serial.print(" deg Pitch: "); Serial.print(imu.pitch(), 2);
    Serial.println(" deg");
  } else {
    Serial.println("Read failed");
  }

  delay(300);
}
