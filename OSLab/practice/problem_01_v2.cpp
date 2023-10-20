#include "mbed.h"

#define GetReq_FLAG 1
#define ReleaseReq_FLAG 2

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
InterruptIn btn_1(BUTTON1);
InterruptIn btn_2(D7, PullUp);

Semaphore s1(1);
Thread thread;

void get_request() {
    thread.flags_set(GetReq_FLAG);
}

void release_request() {
    t1.flags_set(ReleaseReq_FLAG);
}

void task() {
    while(true){
        uint32_t flags = ThisThread::flags_get();
        if(flags & GetReq_FLAG){
            led1 = 1;
            led2 = 0;
        }
        if(flags & ReleaseReq_FLAG) {
            led1 = 0;
            led2 = 1;
        }
        
        ThisThread::flags_clear();
        ThisThread::sleep_for(100ms);
        // printf(">> flags: %x               \r", flags);
    }
}
 
int main() {
    btn_1.fall(&get_request);
    // btn_2.fall(&get_requset);
    
    // btn_1.rise(&release_request);
    btn_2.rise(&release_request);

    t1.start(callback(task));
    while(true) {
        ThisThread::sleep_for(1s);
    }
    thread.join();
}
