#include "mbed.h"

#define MAXIMUM_BUFFER_SIZE 32

static DigitalOut led1(LED1);
static DigitalOut led2(LED2);
static DigitalOut led3(LED3);

static BufferedSerial serial_port(USBTX, USBRX);

int main(void) {
    int var = 0;

    while(1) {
        if(uint32_t num = serial_port.read(buf, sizeof(buf))) {
            if(buf[0] == '1') {
                if(var == 0)
                    led1 = 1;
                else if(var == 1)
                    led2 = 1;
                else if(var == 2)
                    led3 = 1;
            }
            else {
                if(var == 0)
                    led1 = 0;
                else if(var == 1)
                    led2 = 0;
                else if(var == 2)
                    led3 = 0;
            }
            var += 1;
            if(var == 3)
                var = 0;

            serial_port.write(buf, num);
        }
    }
}
