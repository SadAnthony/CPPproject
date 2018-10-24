#include <iostream>
#include "Vector0.h"

using namespace std;

int main () {
    return 0;
}

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}