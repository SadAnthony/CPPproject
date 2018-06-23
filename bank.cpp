//
// Created by Sedletskiy on 23-Jun-18.
//

#include <iostream>
#include "Queue.h"
#include "Customer.h"
#include <ctime>
#include <cstdlib>
const int MIN_PER_HOUR = 60;
using namespace std;

bool newCustomer(double x);

int main () {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "Enter maximum size of queue: ";
    int queueMaxSize;
    cin >> queueMaxSize;
    cout << "Enter number of emulation hours: ";
    long cycleLimit;
    cin >> cycleLimit;
    cycleLimit *= MIN_PER_HOUR;
    Queue queue(queueMaxSize);
    cout << "Enter average number of customers per hour: ";
    double customerPerHour;
    cin >> customerPerHour;
    double minPerCustomers = MIN_PER_HOUR / customerPerHour;
    Customer temp;
    int rejected = 0;       //number of rejected customers
    int customers = 0;      //total number of customers
    int served = 0;         //total number of served customers
    long sumLine = 0;        //total length of queue
                            //we need it to calculate average length of queue
    int waitTime = 0;       //time before release cash machine
    long lineWait = 0;       //total time in queue

    for (int currentTime = 0; currentTime < cycleLimit; currentTime++) {
        if (newCustomer(minPerCustomers)) {     //if new customer appeared
            if (queue.isFull()) {
                rejected++;
            }
            else {
                customers++;
                temp.set(currentTime);                 //when this guy appeared
                queue.add(temp);
            }
        }
        if (waitTime <= 0 && !queue.isEmpty()){ //if front customer is served
            queue.remove(temp);
            waitTime = temp.process();  //serving the customer
            lineWait += currentTime - temp.arrive(); //how long the customer was in queue
            served++;
        }
        if (waitTime > 0) {
            waitTime--;
        }
        sumLine += queue.count();
    }

    //printing results
    if (customers > 0) {
        cout << "total customers accepted: " << customers << endl;
        cout << "customers served: " << customers << endl;
        cout << "customers rejected: " << rejected << endl;
        cout << "  average queue size: "
                << static_cast<double>(sumLine) / cycleLimit << endl;
        cout << "  average wait time: "
                << static_cast<double>(lineWait) / served << endl;
    }
    else {
        cout << "No customers!\n";
    }
    cout << "Done!\n";
    return 0;
}

bool newCustomer(double x) {
    return (rand() * x / RAND_MAX < 1);
}