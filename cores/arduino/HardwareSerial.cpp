#include "HardwareSerial.h"

HardwareSerial::HardwareSerial(){
    this->serialMonitor = HardwareSerialFILE;
}

HardwareSerial::HardwareSerial(uint8_t* u1, uint8_t* u2, uint8_t* u3, uint8_t* u4, uint8_t* u5, uint8_t* u6){
    this->serialMonitor = HardwareSerialFILE;
}

void HardwareSerial::begin(unsigned long baud, uint8_t config){

}

void HardwareSerial::end(){

}

int HardwareSerial::available(){
    return 1;
}

int HardwareSerial::peek(){
    return 1;
}

int HardwareSerial::read(){
    return 1;
}

int HardwareSerial::availableForWrite(){
    return 1;
}

void HardwareSerial::flush(){
    return;
}

size_t HardwareSerial::write(uint8_t c){
    fprintf(this->serialMonitor, "%c", c);
    return 1;
}

size_t HardwareSerial::write(const uint8_t*buffer, size_t size){
    if(buffer == NULL){
        return 0;
    }
    fprintf(this->serialMonitor, "%s", (const char *)buffer);
    return size;
}

size_t HardwareSerial::write(const char *str){
    return write((const uint8_t*)str, strlen(str));
}

size_t HardwareSerial::print(const String &s){
    return print(s.c_str());
}

size_t HardwareSerial::print(const char *s){
    fprintf(this->serialMonitor, "%s", s);
    return strlen(s);
}

size_t HardwareSerial::print(char c){
    return print(String(c));
}

size_t HardwareSerial::print(unsigned char c){
    return print(String(c));
}

size_t HardwareSerial::print(int i){
    return print(String(i));
}

size_t HardwareSerial::print(unsigned int i){
    return print(String(i));
}

size_t HardwareSerial::print(long l){
    return print(String(l));
}

size_t HardwareSerial::print(unsigned long l){
    return print(String(l));
}

size_t HardwareSerial::print(double d){
    return print(String(d));
}

size_t HardwareSerial::println(const String &s){
    return println(s.c_str());
}

size_t HardwareSerial::println(const char *s){
    fprintf(this->serialMonitor, "%s\n", s);
    return strlen(s);
}

size_t HardwareSerial::println(char c){
    return println(String(c));
}

size_t HardwareSerial::println(unsigned char c){
    return println(String(c));
}

size_t HardwareSerial::println(int i){
    return println(String(i));
}

size_t HardwareSerial::println(unsigned int i){
    return println(String(i));
}

size_t HardwareSerial::println(long l){
    return println(String(l));
}

size_t HardwareSerial::println(unsigned long l){
    return println(String(l));
}

size_t HardwareSerial::println(double d){
    return println(String(d));
}

size_t HardwareSerial::println(){
    fprintf(this->serialMonitor, "\n");
    return 0;
}

size_t HardwareSerial::printf(const char *format, ...){
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    return 1;
}

HardwareSerial Serial;




