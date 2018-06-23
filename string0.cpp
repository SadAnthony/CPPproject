//
// Created by Sedletskiy on 21-Jun-18.
//

#include "string0.h"
#include <cstring>

int String0::count = 0;

String0::String0() {
    str = nullptr;
    size = 0;
    count ++;
}
String0::String0(char c) {
    size = 1;
    str = new char [size + 1];
    str[0] = c;
    str[1] = '\0';
    count++;
}
String0::String0(const char* rhs) {
    size = std::strlen(rhs);
    str = new char [size + 1];
    for (int i = 0; i < size; i++)
        str[i] = rhs[i];
    str[size] = '\0';
    count++;
}
String0::String0(const String0& rhs) {
    size = rhs.size;
    str = new char [size + 1];
    std::strcpy(str, rhs.str);
    count++;
}
String0::~String0() {
    if (size != 0) {
        delete [] str;
    }
    count--;
}
const int String0::length() const {
    return size;
}
String0& String0::operator=(const String0& rhs) {
    delete [] str;
    size = rhs.size;
    str = new char [size + 1];
    std::strcpy(str, rhs.str);
    return *this;

}
String0 &String0::operator=(const char *rhs) {
    delete [] str;
    size = std::strlen(rhs);
    str = new char [size + 1];
    std::strcpy(str, rhs);
    return *this;
}
String0& String0::operator+=(const String0& rhs) {
    int k = size + rhs.size;
    auto * b = new char [k + 1];
    for (int i = 0; i < k; i++) {
        if (i < size)
            b[i] = str[i];
        else
            b[i] = rhs.str[i-size];
    }
    b[k] = '\0';
    delete [] str;
    str = b;
    size = k;
    return *this;
}
String0 String0::operator+(const String0 & rhs) const {
    return String0(*this) += rhs;
}
char & String0::operator[] (int i) {
    if (i < 0 || i > size) {
        std::cerr << "Error: wrong index." << std::endl;
        return str[0];
    }
    else
        return str[0];
}
const char& String0::operator[] (int i) const {
    std::cout << " [] " << std::endl;
    if (i < 0 || i > size) {
        std::cerr << "Error: wrong index." << std::endl;
        return str[0];
    }
    else
        return str[i];
}
std::ostream& operator<<(std::ostream& os, const String0& rhs) {
    if (rhs.size) {
        for (int i = 0; i <= rhs.length(); i++) {
            os << rhs.str[i];
        }
    }
    else {
        os << "Empty string.";
    }
    return os;
}
bool String0::operator==(const String0 &rhs) const {
    return static_cast<bool>(!std::strcmp(this->str, rhs.str));
}
bool String0::operator!=(const String0 &rhs) const {
    return !(*this == rhs);
}
