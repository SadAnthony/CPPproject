#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void potential(double h);
double funcVelocity(double r, double e, double m);
double funcRange(double v);

int main() {
    double h = 0.01;
    cout << "\tFor step = " << h << endl;
    potential(h);
    h = 0.02;
    cout << "\tFor step = " << h << endl;
    potential(h);
    h = 0.05;
    cout << "\tFor step = " << h << endl;
    potential(h);
    h = 0.1;
    cout << "\tFor step = " << h << endl;
    potential(h);
    h = 0.2;
    cout << "\tFor step = " << h << endl;
    potential(h);
    return 0;
}

void potential(double h) {
    const double m = 1.0;
    const double e = 0.25;

    double yExperiment = 0, xExperiment = 0;
    double xPrev, x, y, yPrev, vxPrev, vyPrev, vx, vy;
    vx = 0.0;
    x = 3.0;
    vy = sqrt(-1/m*x*funcVelocity(x, e, m));
    y = 0.0;

    const double t1 = 3.14/2*x/vy;
    const double xTheory = 0.0;
    const double yTheory = x;


    double r;
    for (int i = 0; h * i < t1; i++) {
        xPrev = x;
        yPrev = y;
        vxPrev = vx;
        vyPrev = vy;
        r = sqrt(x * x + y * y);

        vx = vxPrev + h*funcVelocity(r, e, m) * (xPrev / r);
        x = xPrev + h*funcRange(vxPrev);

        vy = vyPrev + h*funcVelocity(r, e, m) * (yPrev / r);
        y = yPrev + h*funcRange(vyPrev);

        /*cout << fixed << setprecision(3)
            << "t = " << i*h
            << "\tvx = " << vx[i] << "\tx = " << x[i]
            << "\tvy = " << vy[i] << "\ty = " << y[i] << endl;
        */
    }

    xExperiment = x;
    yExperiment = y;

    //cout << "x experimental = " << xExperiment << "\ty experimental = " << yExperiment << endl;
    cout << fixed << setprecision(4) << "x error = " << abs(xExperiment - xTheory)
    << "\ty error = " << abs(yExperiment - yTheory) << endl;

    //return 0;
}

double funcVelocity(double r, double e, double m) {
    return (-4.0*e/m * (-12.0/pow(r, 13.0) - (-6.0/pow(r, 7.0))));
}

double funcRange(double v) {
    return v;
}