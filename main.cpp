#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double funcVelocity(double r, double e, double m);
double funcRange(double v);

int main() {
    double dt = 0.01;
    double v[1001];
    v[0] = 0.5;
    double x[1001];
    x[0] = 1.05;

    for (int i = 0; i < 1000; i++) {
        v[i+1] = v[i] + dt*funcVelocity(x[i], 1/4, 1);
        x[i+1] = x[i] + dt*funcRange(v[i]);
        cout << "v = " << v[i] << ", x = " << x[i] << endl;
    }
}

double funcVelocity(double r, double e, double m) {
    return (-4*e/m * (-12/pow(r, 13) - (-6/pow(r, 7))));
}

double funcRange(double v) {
    return v;
}