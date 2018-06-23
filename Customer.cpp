//
// Created by Sedletskiy on 22-Jun-18.
//

#include "Customer.h"
#include <cstdlib>
#include <ctime>

void Customer::set(int when) {
    srand(static_cast<unsigned int>(time(nullptr)));
    processTime = std::rand() % 3 + 1;
    arriveTime = when;
}
