//
// Created by Sedletskiy on 22-Jun-18.
//

#include <iostream>
#include "string0.h" //во избежание конфликта с string.h и string

using namespace std;

int main () {
    char str1 [] = "Hello, world!";
    char str2 [] = "Fuck the world!";
    String0 myst1;
    String0 myst2(str2);
    String0 myst3('m');

    cout << myst1 << "   ";
    cout << myst2 << "   ";
    cout << myst3 << "   ";
    cout << String0::HowMany() << endl;
    myst1 = str1;
    cout << myst1 << "   ";
    String0 myst4(myst2);
    cout << myst4 << "   ";
    cout << String0::HowMany() << endl;
    myst4 += myst3;
    cout << myst4 << "   ";
    cout << String0::HowMany() << endl;
    myst4 = myst1 + myst2;
    cout << myst4 << "   ";
    cout << String0::HowMany() << endl;

    cout << myst1 << "    " << myst2 << "    " << myst3 << endl;
    myst1 = myst2 = myst3;
    cout << myst1 << "    " << myst2 << "    " << myst3 << endl;
    return 0;
}