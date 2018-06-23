//
// Created by Sedletskiy on 23-Jun-18.
//

//Backup from
// Created by Sedletskiy on 22-Jun-18.
//

#include "Queue.h"
#include "Customer.h"

template<typename I>
Queue<I>::Queue(int qs) : qsize(qs){
    head = tail = nullptr;
    numberOfItems = 0;
}

template<typename I>
Queue<I>::~Queue() {
    Node * temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
        numberOfItems--;
    }
}

template<typename I>
bool Queue<I>::isEmpty() const {
    return (!numberOfItems);
}

template<typename I>
bool Queue<I>::isFull() const {
    return (numberOfItems == qsize);
}

template<typename I>
int Queue<I>::count() const {
    return qsize;
}

template<typename I>
bool Queue<I>::add(const I &item) {
    if (this->isFull()) {
        return false;
    }
    Node * newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;
    numberOfItems++;
    if (this->isEmpty()) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
    return true;
}

template<typename I>
bool Queue<I>::remove(I &item) {
    if (this->isEmpty()) {
        return false;
    }
    item = head->item;
    Node * temp = head->next;
    head = head->next;
    delete temp;
    numberOfItems--;
    if (this->isEmpty()) {
        tail = nullptr;
    }
    return true;
}
