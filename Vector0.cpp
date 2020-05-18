//
// Created by Sedletskiy on 5/18/2020.
//

#include "Vector0.h"
#include "iostream"

int Vector0::count = 0;

Vector0::Vector0() {
    size = 0;
    arr = nullptr;
    count++;
}

Vector0::Vector0(int size1, const double *arr1) {

    // Проверки на адекватность параметров
    // TODO: Ещё можно пихнуть проверку, что размер arr1 == size1.
    if (size1 <= 0) {
        std::cerr << "Некорректный размер массива\n";
        return;
    }
    if (arr1 == nullptr) {
        std::cerr << "На вход пришёл пустой указатель\n";
        return;
    }

    this->size = size1;
    this->arr = new double[this->size];
    //std::cout << "Я выделиль!\n"; // Выпилить перед сдачей

    for (int i = 0; i < this->size; i++)
        this->arr[i] = arr1[i];
    count++;
}

Vector0::Vector0(const Vector0 &V) {
    this->size = V.size; // Доступ к приватному полю вектора V, ахтунг
    this->arr = new double[this->size];
    //std::cout << "Я выделиль!\n"; // Выпилить перед сдачей

    for (int i = 0; i < this->size; i++)
        this->arr[i] = V.arr[i]; // Доступ к приватным полям вектора V, ахтунг

    count++;
}

Vector0::~Vector0() {
    if (size != 0) {
        delete[] arr;
    }
    // std::cout << "Я очистиль!\n"; // Выпилить перед сдачей
    count--;
}

Vector0 &Vector0::operator=(const Vector0 &V) {    // Завязал на операторы == и []
    // Обработка self-assignment
    if (*this == V)
        return *this;

    // Сношу старый вектор, если он не пустой
    if (size != 0)
        delete[] this->arr;
    //std::cout << "Я очистиль!\n"; // Выпилить перед сдачей

    //Выделяю память под новый вектор
    size = V.size; // Доступ к приватному полю вектора V, ахтунг
    this->arr = new double[size];
    //std::cout << "Я выделиль!\n"; // Выпилить перед сдачей

    for (int i = 0; i < size; i++)
        this->arr[i] = V[i];

    return *this;
}

int Vector0::dimension() const {  // Вспомогательная функция, мб надо выпиилить
    return this->size;
}

double &Vector0::operator[](int i) {
    if (i < 0 || i > size - 1) {
        std::cerr << "Error: wrong index " << std::endl;
        return arr[0];
    }//TODO: нужна обработка для size=1.
    else
        return arr[i];
}

const double &Vector0::operator[](int i) const {
    if (i < 0 || i > size - 1) {
        std::cerr << "Error: wrong index " << std::endl;
        return arr[0];
    }//TODO: нужна обработка для size=1.
    else
        return arr[i];
}

bool Vector0::operator==(const Vector0 &C) const {
    if (this->size != C.size)
        return false;
    for (int i = 0; i < size; i++) {
        if (this->arr[i] != C.arr[i])
            return false;
    }
    return true;
}

bool Vector0::operator!=(const Vector0 &C) const {
    return !(*this == C);
}

std::ostream &operator<<(std::ostream &os1, const Vector0 &V1) {
    if (V1.size != 0) {
        os1 << "( ";
        for (int i = 0; i < V1.dimension(); i++) {
            os1 << V1[i] << " ";
        }
        os1 << ") ";
    } else {
        os1 << "Vector is empty. ";
    }
    return os1;
}

std::istream &operator>>(std::istream &is1, Vector0 &V) {
    if (V.size != 0) {
        delete[] V.arr;
        //std::cout << "Я очистиль!\n"; // Выпилить перед сдачей
    }

    std::cout << "Размерность вектора: ";
    is1 >> V.size;
    V.arr = new double[V.size];
    //std::cout << "Я выделиль!\n"; // Выпилить перед сдачей

    std::cout << "Вектор: ";
    for (int i = 0; i < V.size; i++)
        is1 >> V.arr[i];
    return is1;
}

Vector0 Vector0::operator+=(const Vector0 &V) {
    if (this->size == 0 or V.size == 0) {
        std::cerr << "Один из векторов пустой\n";
        return *this;
    }
    else if (this->size != V.size) {
        std::cerr << "Векторы имеют разную размерность\n";
        return *this;
    }
    for (int i = 0; i < this->size; i++) {
        this->arr[i] += V.arr[i];
    }
    return *this;
}

Vector0 Vector0::operator+(const Vector0 &V) const {
    return Vector0(*this)+=V;
}

Vector0 Vector0::operator*=(double num) {
    if (this->size == 0) {
        std::cerr << "Вектор пустой\n";
    }
    else for (int i = 0; i < this->size; i++) {
        this->arr[i] *= num;
    }
    return *this;
}

Vector0 Vector0::operator-=(const Vector0 &V) {
    if (this->size == 0 or V.size == 0) {
        std::cerr << "Один из векторов пустой\n";
        return *this;
    }
    else if (this->size != V.size) {
        std::cerr << "Векторы имеют разную размерность\n";
        return *this;
    }
    for (int i = 0; i < this->size; i++) {
        this->arr[i] -= V.arr[i];
    }
    return *this;
}

Vector0 Vector0::operator-(const Vector0 &V) const {
    return Vector0(*this)-=V;
}

Vector0 Vector0::operator*(double num) const {
    return Vector0(*this)*=num;
}

Vector0 Vector0::operator/=(double num) {
    if (this->size == 0) {
        std::cerr << "Вектор пустой\n";
    }
    else if (num == 0) {
        std::cout << "Деление на ноль\n";
    }
    else for (int i = 0; i < this->size; i++) {
            this->arr[i] /= num;
        }
    return *this;
}

Vector0 Vector0::operator/(double num) const {
    return Vector0(*this)/=num;
}

