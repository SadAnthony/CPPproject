//
// Created by Sedletskiy on 20-Jun-18.
//

#ifndef CPPPROJECT_COMPLEX0_H
#define CPPPROJECT_COMPLEX0_H

#include <iostream>

class Complex0 {
private:
    double imaginaryPart;
    double realPart;
public:
    Complex0(double a = 0.0, double b = 0.0);
    Complex0(const Complex0& C);
    ~Complex0() = default;
    Complex0&operator=(const Complex0& C);
    Complex0 operator~() const;
    Complex0 operator+(const Complex0& C) const;
    Complex0 operator-(const Complex0& C) const;
    Complex0 operator-() const;
    Complex0 operator*(const Complex0& C) const;
    Complex0 operator/(const Complex0& C) const;
    Complex0&operator+=(const Complex0& C);
    Complex0&operator-=(const Complex0& C);
    Complex0&operator*=(const Complex0& C);
    Complex0&operator/=(const Complex0& C);
    bool operator==(const Complex0 & C) const;
    bool operator!=(const Complex0 & C) const;
    friend Complex0 operator*(double num, const Complex0& C);
    friend std::ostream&operator<<(std::ostream&, const Complex0&);
    friend std::istream&operator>>(std::istream&, Complex0&);
};


#endif //CPPPROJECT_COMPLEX0_H
