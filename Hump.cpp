#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double function(double x);
void leftCorner();

int main() {
    double h = 0.01;
    cout << "\tFor step = " << h << endl;
    leftCorner();
    return 0;
}

double function(double x) {
    return ((x >= -3 && x <= 3) ? 1 : 0);
}

void leftCorner() {
    const double e = 0.5;
    const double dx = 0.5;
    const double dt = 0.5;

    double xCurr = -20, xPrev;
    double yCurr[1000], yPrev[1000];
    yCurr[0] = function(xCurr);

    for (int i = 0; i*dt < 5; i++) {
            xPrev = xCurr;
            yPrev[i] = yCurr[i];
            yCurr[i+1] = (1 - e*dt/dx) * function(xCurr-i*dt) +
                    (e*dt/dx) * function(xCurr-(i-1) * dt);

    }

}