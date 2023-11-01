#include "Math.h"
#include "Aplication.h"
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    double x, y, z;
    x = 0.48 * 15;
    y = 0.47 * 15;
    z = -1.32 * 15;

    Aplication calc;

    calc.Fn_b(x, y, z);
    calc.Fn_a(x, y, z);

    double a = calc.geta();
    cout << "The value of a : " << a << endl;
    double b = calc.getb();
    cout << "The value of b : " << b << endl;

    int x_s = -1;
    int x_e = 1;
    double dx = 0.2;

    cout << "\t\t+--------------+--------------+--------------+" << endl;
    cout << "\t\t|       x      |       a      |       b      |" << endl;
    cout << "\t\t+--------------+--------------+--------------+" << endl;

    for (double x = x_s; x < x_e; x += dx) {
        calc.Fn_b(x, y, z);
        calc.Fn_a(x, y, z);


        double a = calc.geta();
        double b = calc.getb();

        // setw() - фіксована ширина
        cout << "\t\t| " << setw(12) << x << " | " << setw(12) << a << " | " << setw(12) << b << " |" << endl;
    }

    cout << "\t\t+--------------+--------------+--------------+" << endl;

    return 0;
}


void Aplication::Fn_b(double x, double y, double z) {
    b = pow(3 * x + pow(sin(pow(abs(x + z), 1.0 / 3)), 2) / (2 * x + 1.34), 2) - y * exp(pow(x, 2) - z);
}

void Aplication::Fn_a(double x, double y, double z) {
    double a1 = pow(fabs(x), 1.5) + sqrt(pow(cos(pow(2, pow(fabs(x - getb()), 1.2))), 2));
    double a2 = 3 + pow(x, 2) + pow(sin(pow(y + z, 3)), 2);
    double a3 = (3 - x) / (y + z);
    a = a1 / a2 + a3;
}
