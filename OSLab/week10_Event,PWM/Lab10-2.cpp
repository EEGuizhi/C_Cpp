#include "mbed.h"

// A-1A High & A-1B Low = Counter Clockwise
// A-1A Low & A-1B High = Clockwise
PwmOut motor_ccw(D10);
PwmOut motor_cw(D11);

int main() {
    // motor_ccw = 0;
    // motor_cw = 0;

    motor_ccw.period(4);
    motor_ccw.write(0.5);

    while(true) {
        ThisThread::sleep_for(500ms);
    }
}
