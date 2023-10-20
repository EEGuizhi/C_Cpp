#include "mbed.h"

DigitalIn btn(BUTTON1);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

int main() {
	btn.mode(PullNone);
	
	led1 = 1;
	led2 = 0;
	led3 = 0;
	
	while(1) {
		if(btn) {
			if(led1) {
				led1 = 0;
				led2 = 1;
			}
			else if(led2) {
				led2 = 0;
				led3 = 1;
			}
			else {
				led3 = 0;
				led1 = 1;
			}
		}
		else {
			if(led1) {
				led1 = 0;
				led3 = 1;
			}
			else if(led2) {
				led2 = 0;
				led1 = 1;
			}
			else {
				led3 = 0;
				led2 = 1;
			}
		}
		ThisThread::sleep_for(100);
	}
	
	return 0;
}
