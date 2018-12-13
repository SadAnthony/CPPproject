#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double funcVelocity(double r, double e, double m);
double funcRange(double v);

int main() {
    double h = 0.01;
    double v[1001];
    v[0] = 0.2;
    double x[1001];
    x[0] = 1.34;

    for (int i = 0; i < 1000; i++) {
        v[i+1] = v[i] + h*funcVelocity(x[i], 0.25, 1.0);
        x[i+1] = x[i] + h*funcRange(v[i]);
        cout << "v = " << fixed << setprecision(3)<< v[i]
        << "\t x = " << x[i] << endl;
    }
}

double funcVelocity(double r, double e, double m) {
    return (-4.0*e/m * (-12.0/pow(r, 13.0) - (-6.0/pow(r, 7.0))));
}

double funcRange(double v) {
    return v;
}