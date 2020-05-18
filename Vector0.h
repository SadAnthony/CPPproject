//
// Created by Sedletskiy on 5/18/2020.
//

#ifndef CPPPROJECT_VECTOR0_H
#define CPPPROJECT_VECTOR0_H

#include "iostream"

class Vector0 {
private:
    double* arr;
    int size;
    static int count;
public:
    Vector0(); //+
    explicit Vector0(int size1, const double* arr1);                //+
    Vector0(const Vector0& V);                                      //+
    ~Vector0();                                                     //+
    const static int HowMany() { return count; };                   //+
    Vector0&operator=(const Vector0& V);                            //+
    [[nodiscard]] int dimension() const;                            //+
    Vector0 operator+=(const Vector0& V);                           //+
    Vector0 operator+(const Vector0& V) const;                      //+
    Vector0 operator-=(const Vector0& V);                           //+
    Vector0 operator-(const Vector0& V) const;                      //+
    Vector0 operator*=(double num);                                 //+
    Vector0 operator*(double num) const;                            //+
    Vector0 operator*(const Vector0& V) const;
    Vector0 operator/=(double num);
    Vector0 operator/(double num) const;
    bool operator==(const Vector0 & C) const;                       //+
    bool operator!=(const Vector0 & C) const;                       //+
    double & operator[](int i);                                     //+ (проверил косвенно через оператор присваиванния)
    const double& operator[](int i) const;                          //+ (проверил косвенно через оператор присваиванния)
    friend std::ostream&operator<<(std::ostream&, const Vector0&);  //+
    friend std::istream&operator>>(std::istream&, Vector0&);        //+
};


#endif //CPPPROJECT_VECTOR0_H
