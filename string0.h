//
// Created by Sedletskiy on 21-Jun-18.
//

#ifndef CPPPROJECT_STRING0_H
#define CPPPROJECT_STRING0_H

#include <iostream>

class String0 {
private:
    char *str;
    int size;
    static int count;
public:
    String0();
    explicit String0(char);             //+
    explicit String0(const char*);      //+
    String0(const String0&);            //+
    ~String0();                         //+

    const int length() const;
    const static int HowMany() { return count; };       //+

    String0& operator=(const String0 &rhs);             //+
    String0& operator=(const char* rhs);                //+
    String0& operator+=(const String0 &rhs);            //+
    String0 operator+(const String0 &rhs) const ;       //+

    char & operator[](int i);                           //+
    const char& operator[](int i) const;                //+

    friend std::ostream& operator<<(std::ostream&, const String0&);

    bool operator!=(const String0 &rhs) const;          //+
    bool operator==(const String0 &rhs) const;          //+
};

#endif //CPPPROJECT_STRING0_H
