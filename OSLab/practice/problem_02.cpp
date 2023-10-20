#include "mbed.h"
#include "LCDi2c.h"

// 輸出的時候 BUTTON1 和 ENTER 要一起按！
#define MAXIMUM_BUFFER_SIZE 32

static BufferedSerial serial_port(USBTX, USBRX);
LCDi2c lcd(A4, A5);  // SDA: A4, SCL: A5, Vcc: 5V
DigitalIn btn(BUTTON1);

int main() {
    serial_port.set_baud(9600);
    serial_port.set_format(8, BufferedSerial::None, 1);  // bits, parity, stop bit
    
    char buf[MAXIMUM_BUFFER_SIZE] = {0};
    int var[2], op;  // op: operation
    bool order = 0, state = 0;  // order: the 'order'th variable, state: if input number is lowest variable's digit

    while(true) {
        if(uint32_t char_width = serial_port.read(buf, sizeof(buf))) {
            if(buf[0] <= (int)'9' && buf[0] >= (int)'0') {  // input variables
                if(state == 0) {
                    var[order] = (int)buf[0] - (int)'0';
                    state = 1;
                }
                else {
                    var[order] *= 10;
                    var[order] += (int)buf[0] - (int)'0';
                }
            }
            else if(buf[0]=='+' || buf[0]=='-' || buf[0]=='*' || buf[0]=='/') {  // before input 2th variable
                switch(buf[0]) {
                    case '+':
                        op = 0;
                        break;
                    case '-':
                        op = 1;
                        break;
                    case '*':
                        op = 2;
                        break;
                    case '/':
                        op = 3;
                        break;
                }
                state = 0;
                order = 1;
            }
            serial_port.write(buf, char_width);
        }

        // output
        if(btn.read() == 0 && order == 1) {
            lcd.cls();
            lcd.locate(0, 0);
            lcd.printf("%d ", var[0]);
            
            // operation
            switch(op) {
                case 0:
                    lcd.printf("+ %d = %d", var[1], var[0]+var[1]);
                    break;
                case 1:
                    lcd.printf("- %d = %d", var[1], var[0]-var[1]);
                    break;
                case 2:
                    lcd.printf("x %d = %d", var[1], var[0]*var[1]);
                    break;
                case 3:
                    lcd.printf("/ %d = %d", var[1], var[0]/var[1]);
                    break;
            }

            // reset to default
            order = 0;
            state = 0;
            ThisThread::sleep_for(3s);
        }
    }
    return 0;
}
