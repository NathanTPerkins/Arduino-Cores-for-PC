#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define HIGH 1
#define LOW  0

#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define LED_BUILTIN 0

typedef bool boolean;
typedef uint8_t byte;

void init();
void initVariant();

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);;
void analogWrite(uint8_t, int);

unsigned long millis();
unsigned long micros();
void delay(unsigned long);
void delayMicroseconds(unsigned long);


void setup();
void loop();

#endif
