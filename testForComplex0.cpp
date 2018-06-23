//
// Created by Sedletskiy on 21-Jun-18.
//

#include <iostream>
#include "complex0.h" //во избежание конфликта с complex.h

using namespace std;

int main () {
    Complex0 a (3.0, 4.0); // инициализация значением (3,4і)
    Complex0 c;
    cin >> c;
    cout << "c is " << c << endl; // значение с
    cout << "complex conjugate is " << ~c << endl;
// значение сопряженного числа
    cout << "a is " << a << endl;; //значение а
    cout << "-a is " << -a << endl;; //значение -а
    cout << "a + c is " << a + c << endl; // значение а + с
    cout << "a - c is " << a - c << endl; // значение а - с
    cout << "a * c is " << a * c << endl; // значение а * с
    cout << "2 * c is " << 2 * a << endl; // значение 2 * с
    cout << "Done!" << endl;
    return 0;
}