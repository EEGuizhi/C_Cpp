// thread & flag & button
#include "mbed.h"
#include <cstdio>
#define STOP_FLAG 1

DigitalOut led1(LED1);
DigitalIn btn(BUTTON1);

void worker(DigitalOut *led){
    printf("[W] I am worker , I am waiting for taking a break.\n");
    ThisThread::sleep_for(1s);
    while(true){
        int flag = ThisThread::flags_get();
        if(flag != STOP_FLAG){
            *led = 1;
            printf("[W] Turn on!\n");
            ThisThread::sleep_for(1s);
        }
        else {
            break;
        }
    }
    *led = 0;
    printf("[w] Turn off!\n");
}

int main(){
    printf("[B] I am boss, I am ready.\n");

    while(true){
        Thread thread;
        if(btn.read() == 0) {
            printf("[B] All workers, work now.\n");
            thread.start(callback(worker, &led1));
            
            ThisThread::sleep_for(4999ms);
            printf("[B] All workers, take a break now.\n");
            thread.flags_set(STOP_FLAG);
            
            thread.join();
        }
    }
}
