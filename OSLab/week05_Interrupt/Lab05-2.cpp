#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut d16(PC_6);
InterruptIn alarm(BUTTON1);
Thread thread;

volatile bool trig = false;
volatile int Count = 0;

void control() {
    while(true) {
        if(trig) {
            bool flag = true;
            printf("\nButton pressed!\n");
            printf("count：%d\n", Count);
            for(int i=2; i<Count; i++) {
                if(Count % i == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                printf("counts is prime, motor stop running\n");
                d16 = 0;
            }
            else {
                printf("counts is not prime, motor still running\n");
                d16 = 1;
            }
            trig = false;
        }
    }
}

void trigger() {
    trig = true;
    Count += 1;
}

int main() {
    thread.start(callback(control));
    alarm.rise(&trigger);
    
    // LED控制
    int tmp;
    while(true) {
        tmp = Count % 8;
        if(tmp %2 == 1)
            led3 = 1;
        else
            led3 = 0;

        if(tmp /2 %2 == 1)
            led2 = 1;
        else
            led2 = 0;

        if(tmp /4 %2 == 1)
            led1 = 1;
        else
            led1 = 0;
    }
}
