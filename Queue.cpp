//
// Created by Sedletskiy on 22-Jun-18.
//

#include "Queue.h"
#include "Customer.h"

Queue::Queue(int qs) : qsize(qs){
    head = tail = nullptr;
    numberOfItems = 0;
}

Queue::~Queue() {
    Node * temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
        /*temp = head->next;
        delete head;
        head = temp;*/
    }
}

bool Queue::isEmpty() const {
    return (!numberOfItems);
}

bool Queue::isFull() const {
    return (numberOfItems == qsize);
}

int Queue::count() const {
    return qsize;
}
bool Queue::add(const I &item) {
    if (isFull()) {
        return false;
    }
    auto * newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;
    numberOfItems++;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
    return true;
}

bool Queue::remove(I &item) {
    if (isEmpty()) {
        return false;
    }
    item = head->item;
    numberOfItems--;
    Node * temp = head;
    head = head->next;
    delete temp;
    if (isEmpty()) {
        tail = nullptr;
    }
    return true;
}
