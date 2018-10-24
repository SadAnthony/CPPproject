//
// Created by Sedletskiy on 25-Oct-18.
//

#ifndef CPPPROJECT_VECTOR0_H
#define CPPPROJECT_VECTOR0_H


class Vector0 {
private:
    double* arr;
    int size;
public:
    Vector0(int size, double* arr);
    Vector0(const Vector0& V);
    ~Vector0();
    Vector0&operator=(const Vector0& V);
    Vector0 operator+(const Vector0& V) const;
    Vector0 operator+(const Vector0& V) const;
    Vector0 operator*(double num) const;
    Vector0 operator*(const Vector0& V) const;
    Vector0 operator/(double num) const;
    bool operator==(const Vector0 & C) const;
    bool operator!=(const Vector0 & C) const;
    friend std::ostream&operator<<(std::ostream&, const Vector0&);
    friend std::istream&operator>>(std::istream&, Vector0&);
};



#endif //CPPPROJECT_VECTOR0_H
