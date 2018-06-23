//
// Created by Sedletskiy on 22-Jun-18.
//

#ifndef CPPPROJECT_CUSTOMER_H
#define CPPPROJECT_CUSTOMER_H


class Customer {
private:
    int arriveTime;
    int processTime;
public:
    Customer() { arriveTime = processTime = 0; };
    ~Customer() = default;
    void set(int when);
    int arrive() const { return arriveTime; };
    int process() const { return processTime; };
};


#endif //CPPPROJECT_CUSTOMER_H
