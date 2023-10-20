#include "mbed.h"

DigitalOut led(LED3);

Semaphore semaphore1(1);
Semaphore semaphore2(1);
Semaphore semaphore3(1);
Thread t1;
Thread t2;
Thread t3;

volatile int Count = 1;

void thread1() {
    while(Count < 10) {
        semaphore2.acquire();
        semaphore1.acquire();
        printf("Round %d:\nA\n", Count);
        led = !led;
        semaphore1.release();

        ThisThread::sleep_for(500ms);
        semaphore2.release();
        ThisThread::sleep_for(100ms);
    }
}

void thread2() {
    while(Count <= 10) {
        semaphore3.acquire();
        semaphore2.acquire();
        printf("B\n");
        led = !led;
        semaphore2.release();

        ThisThread::sleep_for(500ms);
        semaphore3.release();
        ThisThread::sleep_for(100ms);
    }
}

void thread3() {
    while(Count <= 10) {
        semaphore1.acquire();
        semaphore3.acquire();
        printf("C\n");
        led = !led;
        semaphore3.release();

        Count += 1;
        ThisThread::sleep_for(500ms);
        semaphore1.release();
        ThisThread::sleep_for(100ms);
    }
}

int main() {
    t1.start(thread1);
    ThisThread::sleep_for(100ms);
    t2.start(thread2);
    t3.start(thread3);

    t1.join();
    t2.join();
    t3.join();
}
