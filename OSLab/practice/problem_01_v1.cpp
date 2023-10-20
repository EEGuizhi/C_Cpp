// External Button：插在麵包版跨接處, 把訊號線和GND接在斜對角
#include "mbed.h"

DigitalIn btn1(BUTTON1);
DigitalIn btn2(D7, PullUp);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

Semaphore s1(1);

void lightup_led1() {
    while(true) {
        if(btn1.read() == 0) {
            if(!led1.read())
                s1.acquire();
            led1 = 1;
        }
        else if(led1.read()) {
            led1 = 0;
            s1.release();
        }
    }
}

void lightup_led2() {
    while(true) {
        if(btn2.read() == 0) {
            if(!led2.read())
                s1.acquire();
            led2 = 1;
        }
        else if(led2.read()) {
            led2 = 0;
            s1.release();
        }
    }
}

int main() {
    // init
    Thread t1, t2;
    led1 = 0;
    led2 = 0;

    // thread start
    t1.start(callback(lightup_led1));
    t2.start(callback(lightup_led2));
    
    // show button/led state
    while(true) {
        ThisThread::sleep_for(500ms);
        printf(">> btn1: %d, led1: %d  ;  btn2: %d, led2: %d                                                         \r", btn1.read(), led1.read(), btn2.read(), led2.read());
    }
}
