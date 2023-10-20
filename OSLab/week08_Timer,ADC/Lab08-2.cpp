// Notice: 
//     mbed-os -> platform -> mbed_lib.json
//     -> find "minimal-printf-enable-floating-point" -> change "flase" to "true"
#include "mbed.h"

AnalogIn ain(A0);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(D12);  // external LED

Thread t1;
Thread t2;
Thread t3;
volatile float voltage;

void light1(DigitalOut *led) {
    while(true) {
        *led = 0;
        while(voltage > 1)
            *led = 1;
    }
}

void light2(DigitalOut *led) {
    while(true) {
        *led = 0;
        while(voltage > 2)
            *led = 1;
    }
}

void light3(DigitalOut *led) {
    while(true) {
        *led = 0;
        while(voltage > 3)
            *led = 1;
    }
}

int main() {
    t1.start(callback(light1, &led1));
    t2.start(callback(light2, &led2));
    t3.start(callback(light3, &led3));
    
    while(true){
        voltage = ain.read() * 3.3f;
        printf("%f V\n", voltage);
    }

    return 0;
}
