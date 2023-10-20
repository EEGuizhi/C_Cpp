#include "mbed.h"
#include <ADXL345.h>

// 參考：https://os.mbed.com/cookbook/ADXL345-Accelerometer

ADXL345 accelerometer(D11, D12, D13, D10);  // D11: MOSI(SDI/SDA), D12: MISO(SDO), D13: SCL(在此用SCK), D10: CS, Vcc: 3V3, GND: GND

int main() {

    int readings[10][3] = {0};

    accelerometer.setPowerControl(0x00);  //Go into standby mode to configure the device.
    accelerometer.setDataFormatControl(0x0B);  //Full resolution, +/-16g, 4mg/LSB.
    accelerometer.setDataRate(ADXL345_3200HZ);  //3.2kHz data rate.
    accelerometer.setPowerControl(0x08);  //Measurement mode.

    while(true) {
        for(int i=0; i < 10; i++) {
            accelerometer.getOutput(readings[i]);
            printf("Collected : %d0 %%\n", i+1);
            ThisThread::sleep_for(1s);
        }
        
        for(int i=1; i <= 10; i++) {
            //13-bit, sign extended values.
            printf("Data %d : %i, %i, %i\n", i, readings[i-1][0], readings[i-1][1], readings[i-1][2]);
        }
    }
}
