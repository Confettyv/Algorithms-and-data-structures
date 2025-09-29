#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return cos(2/x) - 2*sin(1/x) + 1/x;
}

int main() {
    double a = 1;
    double b = 2;
    double eps = 0.0001;
    double x0, x1, x2;

    if(f(a) * f(b) >= 0) {
        cout << "No roots or multiple roots" << endl;
        return 1;
    }

    x0 = a;
    x1 = b;

    int cut = 0;
    double f0 = f(x0);
    double f1 = f(x1);

    cout << "Метод хорд" << endl;
    cout << cut << " cut 0 " << x0 << ", f(x) = " << f0 << endl;
    cout << cut << " cut 1 " << x1 << ", f(x) = " << f1 << endl;

    do {
        cut++;

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double f2 = f(x2);

        cout << "cut " << cut + 1 << " " << x2 << ", f(x) = " << f2 << endl;

        if(fabs(f2) < eps || fabs(x2 - x1) < eps) {
            break;
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
    } while (cut < 100);

    cout << "result: " << x2 << endl;
    cout << "f(x) = " << f(x2) << endl;
    cout << "cut: " << cut + 1 << endl;
    
    return 0;
}