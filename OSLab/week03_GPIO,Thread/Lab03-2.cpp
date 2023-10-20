#include "mbed.h"
#include <cstdio>
#define STOP_FLAG 1

DigitalOut led1(LED1);
InterruptIn btn(BUTTON1);

volatile bool flag;

void worker(DigitalOut *led){
    printf("[W] I am worker , I am waiting for taking a break.\n");
    ThisThread::sleep_for(1s);
    while(!ThisThread::flags_wait_any_for(STOP_FLAG, 1ms)){
        *led = 1;
        printf("[W] Turn on!\n");
        ThisThread::sleep_for(1s);
    }
    *led = 0;
    printf("[w] Turn off!\n");
}

void trig(){
    flag = true;
}

int main(){
    btn.rise(&trig);
    flag = false;
    printf("[B] I am boss, I am ready.\n");

    while(1){
        Thread thread;
        if(flag) {
            printf("[B] All workers, work now.\n");
            thread.start(callback(worker, &led1));
            
            ThisThread::sleep_for(4999ms);
            printf("[B] All workers, take a break now.\n");
            thread.flags_set(STOP_FLAG);
            
            thread.join();
            flag = false;
        }
    }
}
