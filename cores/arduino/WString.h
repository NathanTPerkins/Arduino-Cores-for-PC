#ifndef WSTRING_H_
#define WSTRING_H_
#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

class String final {
private:
    char *_buffer;
    unsigned int _len;

public:
    String();
    String(const char *);
    String(const String&);
    String(const String &&);

    explicit String(char);
    explicit String(unsigned char);
    explicit String(int);
    explicit String(unsigned int);
    explicit String(long);
    explicit String(unsigned long);
    explicit String(float);
    explicit String(double);
    ~String();

    unsigned int length() const {return this->_len;} 

    String& operator=(const String&);
    String& operator=(const char *);
    String& operator=(const String&&);

    bool concat(const String&);
    bool concat(const char*);
    bool concat(char);
    bool concat(unsigned char);
    bool concat(int);
    bool concat(unsigned int);
    bool concat(long);
    bool concat(unsigned long);
    bool concat(float);
    bool concat(double);

    String& operator+=(const String& s) {concat(s); return (*this); };
    String& operator+=(const char *s) {concat(s); return (*this); };
    String& operator+=(char c) {concat(c); return (*this); };
    String& operator+=(unsigned char c) {concat(c); return (*this); };
    String& operator+=(int i) {concat(i); return (*this); };
    String& operator+=(unsigned int i) {concat(i); return (*this); };
    String& operator+=(long l) {concat(l); return (*this); };
    String& operator+=(unsigned long l) {concat(l); return (*this); };
    String& operator+=(float f) {concat(f); return (*this); };
    String& operator+=(double d) {concat(d); return (*this); };

    friend String& operator+(const String&, const String&);
    friend String& operator+(const String&, const char *);
    friend String& operator+(const String&, char c);
    friend String& operator+(const String&, unsigned char);
    friend String& operator+(const String&, int);
    friend String& operator+(const String&, unsigned int);
    friend String& operator+(const String&, long);
    friend String& operator+(const String&, unsigned long);
    friend String& operator+(const String&, float);
    friend String& operator+(const String&, double);

    int compareTo(const String&)const;
    bool equals(const String& s)const{return equals(s.c_str());}
    bool equals(const char *)const;
    bool operator == (const String& rhs)const {return equals(rhs);}
    bool operator == (const char *s)const {return equals(s);}
    bool operator != (const String& rhs)const {return !equals(rhs);}
    bool operator != (const char *s)const {return !equals(s);}

    char charAt(unsigned int)const;
    void setCharAt(unsigned int, char);
    char operator [] (unsigned int)const;
    char& operator [] (unsigned int);
    const char *c_str() const { return this->_buffer; }
    char * begin() {return this->_buffer; }
    char * end() {return this->_buffer + this->_len; }
    const char * begin() const {return this->_buffer; }
    const char * end() const {return this->_buffer; }

    int indexOf(char)const;
    int indexOf(char, unsigned int)const;
    int indexOf(const String&)const;
    int indexOf(const String&, unsigned int)const;
    int lastIndexOf(char)const;
    int lastIndexOf(char, unsigned int)const;
    int lastIndexOf(const String&)const;
    int lastIndexOf(const String&, unsigned int)const;
    String substring(unsigned int start)const{return substring(start, this->_len);};
    String substring(unsigned int, unsigned int)const;

    long toInt()const;
    float toFloat()const;
    double toDouble()const;

};

String& operator+(const String&, const String&);
String& operator+(const String&, const char *);
String& operator+(const String&, char c);
String& operator+(const String&, unsigned char);
String& operator+(const String&, int);
String& operator+(const String&, unsigned int);
String& operator+(const String&, long);
String& operator+(const String&, unsigned long);
String& operator+(const String&, float);
String& operator+(const String&, double);



#endif