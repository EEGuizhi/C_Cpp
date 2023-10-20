#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

Semaphore s1(1);  // allow task1 to run
Semaphore s2(0);  // s2 has no token at start
Semaphore s3(0);  // s3 has no token at start

void thread1(char const* args) {
    while (true) {
        s1.acquire();
        led1 = 1;
        printf(">> %s\n", args);
        ThisThread::sleep_for(500ms);
        led1 = 0;
        s2.release();
    }
}

void thread2(char const* args) {
    while (true) {
        s2.acquire();
        led2 = 1;
        printf(">> %s\n", args);
        ThisThread::sleep_for(500ms);
        led2 = 0;
        s3.release();
    }
}

void thread3(char const* args) {
    while (true) {
        s3.acquire();
        led3 = 1;
        printf(">> %s\n", args);
        ThisThread::sleep_for(500ms);
        led3 = 0;
        s1.release();
    }
}

int main() {
    // init
    Thread t2, t3;
    led1 = 0;
    led2 = 0;
    led3 = 0;

    // thread start
    t2.start(callback(thread2, (char *)"I'm thread 2"));
    t3.start(callback(thread3, (char *)"I'm thread 3"));
    thread1((char *)"I'm thread 1");
}
