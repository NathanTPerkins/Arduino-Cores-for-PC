#ifndef HARDWARE_SERIAL_H_
#define HARDWARE_SERIAL_H_

#include <stdio.h>
#include <inttypes.h>

class HardwareSerial{
private:
    FILE *serialMonitor;
public:
    void begin(unsigned long);
    void begin(unsigned long, uint8_t);
    void end();
    int available();
    int peek();
    int read();
    int availableForWrite();
    void flush();
    size_t write(uint8_t);
    size_t write(unsigned long);
};

#endif