#include "WString.h"

String::String(){
    this->_buffer = new char[1];
    memset(this->_buffer, 0, 1);
    this->_len = 0;
}

String::String(const char *s){
    this->_buffer = new char[strlen(s) + 1];
    this->_len = strlen(s);
    memset(this->_buffer, 0, strlen(s) + 1);
    strcpy(this->_buffer, s);
}

String::String(const String& s){
    this->_buffer = new char[s.length() + 1];
    this->_len = s.length();
    memset(this->_buffer, 0, s.length() + 1);
    strcpy(this->_buffer, s._buffer);
}

String::String(const String&& s){
    this->_buffer = new char[s.length() + 1];
    this->_len = s.length();
    memset(this->_buffer, 0, s.length() + 1);
    strcpy(this->_buffer, s._buffer);
}

String::String(char c){
    this->_buffer = new char [4];
    memset(this->_buffer, 0, 4);
    this->_len = 1;

    this->_buffer[0] = c;
}

String::String(unsigned char c){
    this->_buffer = new char [1 + 8 * sizeof(unsigned char)];
    memset(this->_buffer, 0, 1 + 8 * sizeof(unsigned char));
    snprintf(this->_buffer,1 + 8 * sizeof(unsigned char), "%d", c);
    this->_len = strlen(this->_buffer);
}

String::String(int i){
    this->_buffer = new char [2 + 8 * sizeof(int)];
    memset(this->_buffer, 0, 2 + 8 * sizeof(int));
    snprintf(this->_buffer,2 + 8 * sizeof(int), "%d", i);
    this->_len = strlen(this->_buffer);
}

String::String(unsigned int i){
    this->_buffer = new char [2 + 8 * sizeof(unsigned int)];
    memset(this->_buffer, 0, 2 + 8 * sizeof(unsigned int));
    snprintf(this->_buffer,2 + 8 * sizeof(unsigned int), "%u", i);
    this->_len = strlen(this->_buffer);
}

String::String(long l){
    this->_buffer = new char [2 + 8 * sizeof(long)];
    memset(this->_buffer, 0, 2 + 8 * sizeof(long));
    snprintf(this->_buffer,2 + 8 * sizeof(long), "%ld", l);
    this->_len = strlen(this->_buffer);
}

String::String(unsigned long l){
    this->_buffer = new char [2 + 8 * sizeof(unsigned long)];
    memset(this->_buffer, 0, 2 + 8 * sizeof(unsigned long));
    snprintf(this->_buffer,2 + 8 * sizeof(unsigned long), "%lu", l);
    this->_len = strlen(this->_buffer);
}

String::String(float f){
    this->_buffer = new char [2 + 8 * sizeof(float)];
    snprintf(this->_buffer,2 + 8 * sizeof(float), "%f", f);
    this->_len = strlen(this->_buffer);
}

String::String(double d){
    this->_buffer = new char [2 + 8 * sizeof(double)];
    memset(this->_buffer, 0, 2 + 8 * sizeof(double));
    snprintf(this->_buffer,2 + 8 * sizeof(double), "%lf", d);
    this->_len = strlen(this->_buffer);
}

String::~String(){
    delete [] this->_buffer;
}

String& String::operator=(const String& s){
    delete[] this->_buffer;
    this->_buffer = new char[s.length() + 1];
    this->_len = s.length();

    strcpy(this->_buffer, s._buffer);

    return (*this);
}

String& String::operator=(const char *s){
    delete [] this->_buffer;
    this->_buffer = new char[strlen(s) + 1];
    this->_len = strlen(s);
    strcpy(this->_buffer, s);

    return (*this);
}

String& String::operator=(const String&& rVal){
    delete [] this->_buffer;
    this->_buffer = new char[rVal.length() + 1];
    this->_len = rVal.length();

    strcpy(this->_buffer, rVal._buffer);
    return (*this);
}

bool String::concat(const String& str){
    char * temp_buffer = new char[str.length() + strlen(this->_buffer) + 2];
    memset(temp_buffer, 0, str.length() + strlen(this->_buffer) + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, str._buffer);
    this->_len += str.length();
    return true;
}

bool String::concat(const char *str){
    char * temp_buffer = new char[strlen(str) + strlen(this->_buffer) + 2];
    memset(temp_buffer, 0, strlen(str) + strlen(this->_buffer) + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, str);
    this->_len += strlen(str);
    return true;
}

bool String::concat(char c){
    char * temp_buffer = new char[strlen(this->_buffer) + 3];
    memset(temp_buffer, 0, strlen(this->_buffer) + 3);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, &c);
    this->_len += 1;
    return true;
}

bool String::concat(unsigned char c){
    String s = String(c);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

bool String::concat(int i){
    String s = String(i);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

bool String::concat(unsigned int i){
    String s = String(i);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

bool String::concat(long l){
    String s = String(l);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

bool String::concat(unsigned long l){
    String s = String(l);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

bool String::concat(float f){
    String s = String(f);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

bool String::concat(double d){
    String s = String(d);
    char * temp_buffer = new char[strlen(this->_buffer) + s.length() + 2];
    memset(temp_buffer, 0, strlen(this->_buffer) + s.length() + 2);
    strcpy(temp_buffer, this->_buffer);
    delete [] this->_buffer;
    this->_buffer = temp_buffer;
    strcat(this->_buffer, s._buffer);
    this->_len += s.length();
    return true;
}

String& operator+(const String& lhs, const String& rhs){
    String* s = new String;
    s->_buffer = new char[lhs.length() + rhs.length() + 3];
    s->_len = lhs.length() + rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, const char* rhs){
    String* s = new String();
    s->_buffer = new char[lhs.length() + strlen(rhs) + 3];
    s->_len = lhs.length() + strlen(rhs);
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, rhs);
    return *s;
}

String& operator+(const String& lhs, char rhs){
    String* s = new String();
    s->_buffer = new char[lhs.length() + 4];
    s->_len = lhs.length() + 1;
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, &rhs);
    return *s;
}

String& operator+(const String& lhs, unsigned char rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, int rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, unsigned int rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, long rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, unsigned long rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, float rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

String& operator+(const String& lhs, double rhs){
    String s_rhs = String(rhs);
    String* s = new String();
    s->_buffer = new char[lhs.length() + s_rhs.length() + 3];
    s->_len = lhs.length() + s_rhs.length();
    strcpy(s->_buffer, lhs._buffer);
    strcat(s->_buffer, s_rhs._buffer);
    return *s;
}

int String::compareTo(const String& s)const{
    return strcmp(this->_buffer, s._buffer);
}

char String::charAt(unsigned int index)const{
    return this->_buffer[index];
}

void String::setCharAt(unsigned int index, char c){
    this->_buffer[index] = c;
}

char String::operator[](unsigned int index)const{
    return this->_buffer[index];
}

char& String::operator[](unsigned int index){
    return this->_buffer[index];
}

int String::indexOf(char c, unsigned int start)const{
    if(start >= this->_len){
        return -1;
    }
    for(int i = start; i < this->_len; ++i){
        if(this->_buffer[i] == c){
            return i;
        }
    }
    return -1;
}

int String::indexOf(char c)const{
    return indexOf(c, 0);
}

int String::indexOf(const String& s, unsigned int start)const{
    if(start >= this->_len){
        return -1;
    }
    char l1 = s[0];
    for(int i = 0; i < start; ++i){
        if(this->_buffer[i] == l1 && i + s.length() - 1 < this->_len){
            int c = strcmp(s._buffer, substring(i + s.length())._buffer);
            if(c == 0){
                return i;
            }
        }
    }

    return -1;
}

int String::indexOf(const String& s)const{
    return indexOf(s, 0);
}

int String::lastIndexOf(char c, unsigned int start)const{
    int first = indexOf(c, start);
    if(first == -1){
        return -1;
    }
    if(first == this->_len - 1){
        return first;
    }
    int last = first;
    for(int i = first; i < this->_len; ++i){
        if(this->_buffer[i] == c){
            last = i;
        }
    }
    return last;
}

int String::lastIndexOf(char c)const{
    return lastIndexOf(c, 0);
}

int String::lastIndexOf(const String& s, unsigned int start)const{
    if(start >= this->_len){
        return -1;
    }
    int first = indexOf(s, start);
    int i = first + s.length() - 1;
    if(first == -1){
        return -1;
    }
    if(i >= this->_len){
        return first;
    }
    int last = first;
    while(i < this->_len){
        if(this->_buffer[i] == s[0] && i + s.length() - 1 < this->_len){
            int c = strcmp(s._buffer, substring(i + s.length())._buffer);
            if(c == 0){
                last = i;
            }
        }
    }

    return last;
}

int String::lastIndexOf(const String& s)const{
    return lastIndexOf(s, 0);
}

bool String::equals(const char *s)const{
    if(strcmp(this->_buffer, s) == 0){
        return true;
    }
    return false;
}

long String::toInt()const{
    return strtol(this->_buffer, NULL, 10);
}

float String::toFloat()const{
    return strtof(this->_buffer, NULL);
}

double String::toDouble()const{
    return strtod(this->_buffer, NULL);
}

String String::substring(unsigned int start, unsigned int end)const{
    if(start == end){
        return String();
    }
    String s = String();
    s._buffer = new char[end - start];
    for(int i = start; i < end; ++i){
        s[i] = this->_buffer[i];
    }
    return s;
}





