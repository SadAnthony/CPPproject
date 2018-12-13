#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double h = 0.005, yTheoretical;
    double x[1001], y[1001];
    x[0] = 0;
    y[0] = 0;

    for (int i = 0; y[i] <= 2.0; i++) {
        x[i+1] = x[i] + h;
        y[i+1] = y[i] + h * (2*x[i] * (x[i]*x[i] + y[i]));
        yTheoretical = exp(pow(x[i], 2)) - x[i] * x[i] - 1;
        cout << fixed << setprecision(3)
            << "x = " << x[i] << "\t y = " << y[i]
            << "\ty theoretical = " << yTheoretical
            << "\t error = " << abs(yTheoretical - y[i]) << endl;
    }
}
