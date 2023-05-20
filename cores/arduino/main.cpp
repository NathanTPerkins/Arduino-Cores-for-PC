#include "Arduino.h"

int atexit(void (*)()) { return 0; }

void initVariant() __attribute__((weak));
void initVariant(){}

void setupUSB() __attribute__((weak));
void setupUSB(){}

int main(){
	init();

	initVariant();
	
	setup();
    
	for (;;) {
		loop();
	}
        
	return 0;
}