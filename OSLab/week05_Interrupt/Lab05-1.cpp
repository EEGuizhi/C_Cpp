#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led3(LED3);
InterruptIn alarm(BUTTON1);  // 創建一個中斷事件
Thread thread;  // 創建一個名為thread的Thread

volatile bool flag = false;

void blink(DigitalOut *led) {
    while(true) {
        *led = !*led;
        ThisThread::sleep_for(500);
    }
}

void trigger() {
    // alarm.disable_irq();  // 停止接收中斷事件
    flag = true;
}

int main() {
    thread.start(callback(blink, &led3));  // 開始一個thread
    alarm.rise(&trigger);  // 正緣觸發alarm時 執行trigger()
    while(true) {
        if(flag) {
            led1 = !led1;
            flag = false;
        }
        // alarm.enable_irq();  // 開始接受中斷事件
        // ThisThread::sleep_for(500);
    }
}
