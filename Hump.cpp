#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double function(double x);
void leftCorner(double dx);

int main() {
    double h = 0.8;
    cout << fixed << setprecision(3);
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.5;
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.3;
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.1;
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.05;
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.01;
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.005;
    cout << "For step = " << h;
    leftCorner(h);
    h = 0.003;
    cout << "For step = " << h;
    leftCorner(h);
    return 0;
}

double function(double x) {
    return ((x >= -3 && x <= 3) ? 1 : 0);
}

void leftCorner(double dx) {
    const double e = 0.5;
    const double dt = 0.5*dx/e;

    vector<double> funcCurr;
    vector<double> funcPrev;

    double x0 = -20;
    int i, j;

    for (i = 0; x0 + i*dx < 20; i++) {     //function for t = 0 and x = -20...+20
        funcCurr.push_back(function(x0 + i*dx));
    }

    funcPrev = funcCurr;

    for (j = 0; j*dt < 10; j++) {
        for (i = 0; x0 + i*dx < 20; i++) {
            funcCurr[i] = (1 - e*dt/dx) * funcPrev[i] + e*dt/dx * funcPrev[i-1];
        }
        funcPrev = funcCurr;
    }

    /*for (i = 0; x0 + i*dx < 20; i++) {
        cout << fixed << setprecision(3)
        << "at x = " << x0+i*dx << "\t f = " << funcCurr[i]
        << "\t f theor at t final = " << function(x0 + i*dx - e*j*dt) << endl;
    }*/

    double sum = 0;
    for (i = 0; x0 + i*dx < 20; i++) {
        sum += dx*abs(funcCurr[i] - function(x0 + i*dx - e*j*dt));
    }
    cout << "\tError = " << sum << endl;
}