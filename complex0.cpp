//
// Created by Sedletskiy on 20-Jun-18.
//

#include "complex0.h"
#include <cmath>
Complex0::Complex0(double a, double b) {
    realPart = a;
    imaginaryPart = b;
}
Complex0::Complex0(const Complex0 &C) {
    realPart = C.realPart;
    imaginaryPart = C.imaginaryPart;
}
Complex0 &Complex0::operator=(const Complex0 &C) {
    realPart = C.realPart;
    imaginaryPart = C.imaginaryPart;
    return *this;
}
Complex0 Complex0::operator~() const {
    return Complex0(realPart, -imaginaryPart);
}
Complex0 Complex0::operator+(const Complex0 &C) const {
    return Complex0(realPart + C.realPart, imaginaryPart + C.imaginaryPart);
}
Complex0 Complex0::operator-(const Complex0 &C) const {
    return Complex0(realPart - C.realPart, imaginaryPart - C.imaginaryPart);
}
Complex0 Complex0::operator-() const {
    return Complex0(-realPart, -imaginaryPart);
}
Complex0 Complex0::operator*(const Complex0 &C) const {
    return Complex0(realPart * C.realPart - imaginaryPart * C.imaginaryPart,
                    imaginaryPart * C.realPart + C.imaginaryPart * realPart);
}
Complex0 operator*(double num, const Complex0 &C) {
    return Complex0(C * Complex0(num));
}
Complex0 Complex0::operator/(const Complex0 &C) const {
    if (C.realPart == 0 && C.imaginaryPart == 0) {
        std::cerr << "Second number is zero." << std::endl;
        return *this;
    }
    else {
        double a = (realPart * C.realPart + imaginaryPart * C.imaginaryPart)
                   / (realPart * realPart + C.realPart * C.realPart);
        double b = (imaginaryPart * C.realPart - realPart * C.imaginaryPart)
                   / (realPart * realPart + C.realPart * C.realPart);
        return Complex0(a, b);
    }
}
Complex0 &Complex0::operator+=(const Complex0 &C) {
    *this = *this + C;
    return *this;
}
Complex0 &Complex0::operator-=(const Complex0 &C) {
    *this = *this - C;
    return *this;
}
Complex0 &Complex0::operator*=(const Complex0 &C) {
    *this = *this * C;
    return *this;
}
Complex0 &Complex0::operator/=(const Complex0 &C) {
    *this = *this / C;
    return *this;
}
bool Complex0::operator==(const Complex0 &rhs) const {
    return imaginaryPart == rhs.imaginaryPart &&
           realPart == rhs.realPart;
}
bool Complex0::operator!=(const Complex0 &rhs) const {
    return !(rhs == *this);
}
std::ostream &operator<<(std::ostream & os, const Complex0 & C) {
    return os << "(" << C.realPart << ", " << C.imaginaryPart << ")";
}
std::istream &operator>>(std::istream & is, Complex0 & C) {
    return is >> C.realPart >> C.imaginaryPart;
}
