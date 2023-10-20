#include "mbed.h"

DigitalOut led(LED3);
Mutex stdio_mutex;

void notify(const char *name, int state) {
    stdio_mutex.lock();
    printf("%s: %d\n", name, state);
    stdio_mutex.unlock();
}

void test_thread(void const *args) {
    int num = 0;
    while(num < 10) {
        num += 1;
        notify((const char *)args, num);
        led = !led;

        ThisThread::sleep_for(1000ms);
        if(num == 5) {
            printf("Take a break!\n");
            ThisThread::sleep_for(3s);
        }
    }
}

int main() {
    while(true) {
        Thread t2;
        Thread t3;

        t2.start(callback(test_thread, (void *)"Thread 2"));
        t3.start(callback(test_thread, (void *)"Thread 3"));
        test_thread((void *)"Thread 1");

        t2.join();
        t3.join();
    }
}
