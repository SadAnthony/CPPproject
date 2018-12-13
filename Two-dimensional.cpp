#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double funcVelocity(double r, double e, double m);
double funcRange(double v);

int main() {
    double h = 0.01, r;
    double vx[1001], x[1001], vy[1001], y[1001];
    vx[0] = 0.2;
    x[0] = 1.34;
    vy[0] = -0.2;
    y[0] = 1.34;

    for (int i = 0; i < 1000; i++) {
        r = sqrt(x[i] * x[i] + y[i] * y[i]);

        vx[i+1] = vx[i] + h*funcVelocity(r, 0.25, 1.0);
        x[i+1] = x[i] + h*funcRange(vx[i]);

        vy[i+1] = vy[i] + h*funcVelocity(r, 0.25, 1.0);
        y[i+1] = y[i] + h*funcRange(vy[i]);

        cout << fixed << setprecision(3)
            << "t = " << i*h
            << "\tvx = " << vx[i] << "\tx = " << x[i]
            << "\tvy = " << vy[i] << "\ty = " << y[i] << endl;
    }
}

double funcVelocity(double r, double e, double m) {
    return (-4.0*e/m * (-12.0/pow(r, 13.0) - (-6.0/pow(r, 7.0))));
}

double funcRange(double v) {
    return v;
}