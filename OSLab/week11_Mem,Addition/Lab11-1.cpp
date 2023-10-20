#include "mbed.h"

#define SIZE 10
#define FLAG 1

InterruptIn btn(BUTTON1);
Mutex mutex;
ConditionVariable cond(mutex);

EventFlags event_flag;

uint8_t buf[SIZE], head = 0, tail = 0, _count = SIZE;
uint8_t pro_count = 0;
uint32_t flag_read = 0;

void trigger() {
    event_flag.set(FLAG)
}

void consumer() {
    while(true) {
        flag_read = event_flag.wait_any(FLAG);
        if(flag_read) {
            mutex.lock();
            if(_count < SIZE-1) {
                _count++;
                printf("Consumed: %d, Buffer_count: %d\n", buf[tail], SIZE - _count);
                tail++;
            }
            else {
                printf("No items available for purchase! Please wait!\n");
            }
            if(tail > SIZE-1)
                tail = 0;
            mutex.unlock();
        }

        /*剛使用時會自動 mutex.lock() 類似：
            mutex.unlock();
            ThisThread::sleep_for(notify到達);
            mutex.lock();
        */
    }
}

void producer() {
    mutex.lock();
    while(true) {
        if(_count > 0) {
            pro_count++;
            buf[head] = pro_count;
            _count--;
            printf("Produced: %d, Buffer_count: %d\n", buf[head], SIZE - _count);
            head++;
            if(head > SIZE-1)
                head = 0;
            if(count == 0)
                printf("\nBuffer is full, waiting for consumers to buy!\n\n");
        }
        cond.wait();
    }
}

int main() {
    btn.rise(&trigger);

    Thread td1, td2;
    td1.start(consumer);
    td2.start(producer);

    while(true) {
        mutex.lock();
        cond.notify_all();
        mutex.unlock();
        ThisThread::sleep_for(2s);
    }

    mutex.unlock();
    td1.join();
    td2.join();
}
