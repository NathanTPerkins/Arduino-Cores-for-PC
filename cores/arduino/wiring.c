#include <time.h>

unsigned long _start_time_millis = 0;
unsigned long _start_time_micros = 0;
void init(){
    _start_time_millis = millis();
    _start_time_micros = micros();
}

unsigned long millis(){
    struct timespec s;
    clock_gettime(CLOCK_REALTIME, &s);
    unsigned long m = s.tv_nsec / (1e+6);
    return m - _start_time_millis;
}

unsigned long micros(){
    struct timespec s;
    clock_gettime(CLOCK_REALTIME, &s);
    unsigned long m = s.tv_nsec / (1000);
    return m - _start_time_micros;
}

void delay(unsigned long ms){
    unsigned long start = millis();
    while(1){
        if(start - millis() >= ms){
            break;
        }
    }
}

void delayMicroseconds(unsigned long ms){
    unsigned long start = micros();
    while(1){
        if(start - micros() >= ms){
            break;
        }
    }
}