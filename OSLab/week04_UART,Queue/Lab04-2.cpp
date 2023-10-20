/*  mbed Microcontroller Library
    Copyright (c) 2019 ARM Limited
    SPDX-License-Identifier: Apache-2.0 */

#include "mbed.h"

typedef struct {
    uint32_t value[10];
    uint32_t idx;
} message_t;

static DigitalIn btn(Button1);
static BufferedSerial serial_port(USBTX, USBRX);

MemoryPool<message_t, 16> mpool;
Queue<message_t, 16> queue;
Thread thread;

serial_port.set_baud(9600);
serial_port.set_format(8, BufferedSerial::None, 1);  // bits, parity, stop bit


void send_thread() {
    char buf[MAXIMUM_BUFFER_SIZE] = {0};

    message_t *message = mpool.alloc();
    message->idx = 0;

    while(true) {
        if(uint32_t num = serial_port.read(buf, sizeof(buf))) {
            if(buf[0] == '0')
                message->value[message->idx] = 0;
            else if(buf[0] == '1')
                message->value[message->idx] = 1;
            else if(buf[0] == '2')
                message->value[message->idx] = 2;
            else if(buf[0] == '3')
                message->value[message->idx] = 3;
            else if(buf[0] == '4')
                message->value[message->idx] = 4;
            else if(buf[0] == '5')
                message->value[message->idx] = 5;
            else if(buf[0] == '6')
                message->value[message->idx] = 6;
            else if(buf[0] == '7')
                message->value[message->idx] = 7;
            else if(buf[0] == '8')
                message->value[message->idx] = 8;
            else if(buf[0] == '9')
                message->value[message->idx] = 9;

            if(message->idx > 31)
                message->idx = 0;
            else
                message->idx += 1;

            serial_port.write(buf, num);
        }

        if(btn)
            queue.put(message);  // 和.push()一樣，但是會回傳是否添加成功
    }
}

int main() {
    thread.start(callback(send_thread));
    
    int i = 0;
    while(true) {
        osEvent evt = queue.get();
        if(evt.status == osEventMessage) {
            message_t *message = (message_t *)evt.value.p;
            printf("summand: %u\n", message->value[message->idx]);
            printf("addend: %u\n", message->value[message->idx+1]);
            printf("sum: %u\n", message->value[message->idx] + message->value[message->idx+1]);
            
            if(i >= 32)
                i = 0;
            else
                i += 2;
            
            mpool.free(message);
        }
    }
}
