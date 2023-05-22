#ifndef HARDWARE_SERIAL_H_
#define HARDWARE_SERIAL_H_

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdarg.h>
#include "WString.h"

#define SERIAL_5N1 0x00
#define SERIAL_6N1 0x02
#define SERIAL_7N1 0x04
#define SERIAL_8N1 0x06
#define SERIAL_5N2 0x08
#define SERIAL_6N2 0x0A
#define SERIAL_7N2 0x0C
#define SERIAL_8N2 0x0E
#define SERIAL_5E1 0x20
#define SERIAL_6E1 0x22
#define SERIAL_7E1 0x24
#define SERIAL_8E1 0x26
#define SERIAL_5E2 0x28
#define SERIAL_6E2 0x2A
#define SERIAL_7E2 0x2C
#define SERIAL_8E2 0x2E
#define SERIAL_5O1 0x30
#define SERIAL_6O1 0x32
#define SERIAL_7O1 0x34
#define SERIAL_8O1 0x36
#define SERIAL_5O2 0x38
#define SERIAL_6O2 0x3A
#define SERIAL_7O2 0x3C
#define SERIAL_8O2 0x3E

#define HardwareSerialFILE stdout

class HardwareSerial{
private:
    FILE *serialMonitor;
public:
    HardwareSerial();
    HardwareSerial(uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*);
    void begin(unsigned long baud){begin(baud, SERIAL_8N1);};
    void begin(unsigned long, uint8_t);
    void end();
    int available();
    int peek();
    int read();
    int availableForWrite();
    void flush();
    size_t write(uint8_t);
    size_t write(unsigned long c) {return write((uint8_t)c);};
    size_t write(long c) {return write((uint8_t)c);};
    size_t write(unsigned int c) {return write((uint8_t)c);};
    size_t write(int c) {return write((uint8_t)c);};
    
    //Print::write functions
    size_t write(const uint8_t*, size_t);
    size_t write(const char *);

    size_t print(const String&);
    size_t print(const char *);
    size_t print(char);
    size_t print(unsigned char);
    size_t print(int);
    size_t print(unsigned int);
    size_t print(long);
    size_t print(unsigned long);
    size_t print(double);

    size_t println(const String&);
    size_t println(const char *);
    size_t println(char);
    size_t println(unsigned char);
    size_t println(int);
    size_t println(unsigned int);
    size_t println(long);
    size_t println(unsigned long);
    size_t println(double);
    size_t println();

    size_t printf(const char *, ...);

    operator bool() {return true;}
};

extern HardwareSerial Serial;

#endif