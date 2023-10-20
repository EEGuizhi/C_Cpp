#include "mbed.h"
#include "mpu6050Reg.h"
#include "LCDi2c.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
I2C i2c(I2C_SDA, I2C_SCL);  // SDA: A4, SCL: A5, Vcc: 5V
LCDi2c lcd(A4, A5);

enum Ascale {
    AFS_2G = 0, AFS_4G, AFS_8G, AFS_16G
};
enum Gscale {
    GFS_250DPS = 0, GFS_500DPS, GFS_1000DPS, GFS_2000DPS
};

void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
void readByte(uint8_t address, uint8_t subAddress);
void readBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest);

void initMPU6050();
void readAccelData(int16_t * destination);
void readGyroData(int16_t * destination);

void initMPU6050() {
    int Gscale = GFS_250DPS;
    int Ascale = AFS_2G;
    writeByte(MPU6050_ADDRESS, PWR_MGMT_1, 0x01);
    writeByte(MPU6050_ADDRESS, CONFIG, 0x03);
    writeByte(MPU6050_ADDRESS, SMPLRT_DIV, 0x04);

    uint8_t data = readByte(MPU6050_ADDRESS, GYRO_CONFIG);
    writeByte(MPU6050_ADDRESS, GYRO_CONFIG, data | Gscale << 3);
    data = readByte(MPU6050_ADDRESS, ACCEL_CONFIG);
    writeByte(MPU6050_ADDRESS, ACCEL_CONFIG, data | Ascale << 3);
}

void writeByte(uint8_t address, uint8_t subAddress, uint8_t data) {
    char data_write[2];
    data_write[0] = subAddress;
    data_write[1] = data;
    i2c.write(address, data_write, 2, 0);

}

char readByte(uint8_t address, uint8_t subAddress) {
    char data[1];
    char data_write[1];
    data_write[0] = subAddress;
    i2c.write(address,data_write, 1, 1);
    i2c.read(address, data, 1, 0);
    return data[0];
}

void readBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest) {
    char data[14];
    char data_write[1];
    data_write[0] = subAddress;
    i2c.write(address, data_write, 1, 1);
    i2c.read(address, data, count, 0);
    for(int i=0; i < count; i++) {
        dest[i] = data[i];
    }
}


void readAccelData(int16_t * target) {
    uint8_t rawData[6];
    readBytes(MPU6050_ADDRESS, ACCEL_XOUT_H, 6, &rawData[0]);

    target[0] = (rawData[0] << 8) + rawData[1];
    target[1] = (rawData[2] << 8) + rawData[3];
    target[2] = (rawData[4] << 8) + rawData[5];
}

void readGyroData(int16_t * target) {
    uint8_t rawData[6];
    readBytes(MPU6050_ADDRESS, GYRO_XOUT_H, 6, &rawData[0]);
    
    target[0] = (rawData[0] << 8) + rawData[1];
    target[1] = (rawData[2] << 8) + rawData[3];
    target[2] = (rawData[4] << 8) + rawData[5];
}


int main() {
    const float Accel_sensitivity = 16384.0;
    const float Gyro_sensitivity = 131.0;
    int16_t Accel_rew_data[3] = {0, 0, 0};
    int16_t Gyro_rew_data[3] = {0, 0, 0};
    float Ax, Ay, Az, Gx, Gy, Gz;
    Ax = Ay = Gx = Gy = Gz;
    initMPU6050();
    while(true) {
        readAccelData(Accel_rew_data);
        readGyroData(Gyro_rew_data);
        Ax = Accel_rew_data[0] / Accel_sensitivity;
        Ay = Accel_rew_data[1] / Accel_sensitivity;
        Az = Accel_rew_data[2] / Accel_sensitivity;
        Gx = Gyro_rew_data[0] / Gyro_rew_data;
        Gy = Gyro_rew_data[1] / Gyro_rew_data;
        Gz = Gyro_rew_data[2] / Gyro_rew_data;
        printf("-- Ax : %.2f g ,Ay : %.2f g ,Az : %.2f g --\n  ", Ax, Ay, Az);
        printf("-- Gx : %.2f  ,Gy : %.2f  ,Gz : %.2f  --\n  ", Gx, Gy, Gz);

        lcd.cls();
        lcd.locate(0, 0);
        lcd.printf("Ax=%.2f Ay=%.2f", Ax, Ay);
        lcd.locate(0, 1);
        if(Ax < 0.5 && Ay < 0.5) {
            lcd.printf("4109061012");
            led1 = 0;
            led2 = 0;
        }
        else {
            if(Ax >= 0.5 && Ay >= 0.5) {
                lcd.printf("Ax Ay over limit!");
                led1 = 1;
                led2 = 1;
            }
            else if(Ax >= 0.5) {
                lcd.printf("Ax over limit!");
                led1 = 1;
                led2 = 0;
            }
            else {
                lcd.printf("Ay over limit!");
                led1 = 0;
                led2 = 1;
            }
        }
    }
}
