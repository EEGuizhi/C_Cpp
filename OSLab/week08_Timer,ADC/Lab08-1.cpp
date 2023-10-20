#include "mbed.h"
#define RTIME 5000
#define GTIME 5000
#define YTIME 2000
#define LIGHT_FLAG 1

DigitalOut ledR(LED1);
DigitalOut ledG(LED2);
DigitalOut ledY(LED3);

Thread t_red;
Thread t_green;
Thread t_yellow;
Timer tmr;

void light(DigitalOut *led){
    while(true){
        if(ThisThread::flags_wait_any_for(LIGHT_FLAG, 1)){
            *led = 1;
        }
        else{
            *led = 0;
        }
    }
}

int main() {
    // init
    ledR = 1;
    ledG = 0;
    ledY = 0;

    // loop
    tmr.start();
    t_red.start(callback(light, &ledR));
    t_green.start(callback(light, &ledG));
    t_yellow.start(callback(light, &ledY));
    while(true){
        if(tmr.read_ms() < RTIME){  // red
            t_red.flags_set(LIGHT_FLAG);
        }
        else if(tmr.read_ms() >= RTIME && tmr.read_ms() < (GTIME+RTIME)){  // green
            t_green.flags_set(LIGHT_FLAG);
        }
        else if(tmr.read_ms() >= (GTIME+RTIME) && tmr.read_ms() < (YTIME+GTIME+RTIME)){  // yellow
            t_yellow.flags_set(LIGHT_FLAG);
        }
        
        if(tmr.read_ms() >= (YTIME+GTIME+RTIME))
            tmr.reset();
    }

    return 0;
}
