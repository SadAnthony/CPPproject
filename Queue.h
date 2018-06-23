//
// Created by Sedletskiy on 22-Jun-18.
//

#ifndef CPPPROJECT_QUEUE_H
#define CPPPROJECT_QUEUE_H

#include "Customer.h"

typedef Customer I;
class Queue {
private:
    enum { Q_SIZE = 10 };
    struct Node { I item; Node * next; };
    int numberOfItems;
    const int qsize;
    Node * head;
    Node * tail;
public:
    explicit Queue(int num = Q_SIZE);
    Queue(const Queue & queue) = delete;
    Queue&operator=(const Queue & queue) = delete;
    ~Queue();

    bool isEmpty() const;
    bool isFull() const;
    int count() const;

    bool add(const I &item);
    bool remove(I& item);
};


#endif //CPPPROJECT_QUEUE_H
