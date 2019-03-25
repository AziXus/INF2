#include <cstdlib>
#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {

    Fraction<int> f1(4, 6);
    Fraction<int> f2(2, 3);
    Fraction<int> f3(4, 13);

    cout << f1 << endl;
    cout << (float)f1 << endl;
    cout << "Simplification de f1 : " << f1.simplifier() << endl;

    cout << f1 + f2 << endl;
    cout << f1 * f2 << endl;


















    int numerateur = 4;

    int k = 1;

    Fraction<long long> pi(numerateur, 1);

    try {
        while (true) {
            pi += Fraction<long long>((long long)pow(-1, k) * numerateur, 2*k + 1);
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow après " << k << " additions\npi : " << pi << " = " << (double)pi << endl;
    }

    Fraction<long long> pi2(3, 1);
    k = 1;
    try {
        while (true) {
            pi2 += Fraction<long long>((long long)pow(-1, k - 1) * numerateur, (2 * k)*(2 * k + 1)*(2 * k + 2));
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow après " << k << " additions\npi : " << pi2 << " = " << (double)pi2 << endl;
    }

    return EXIT_SUCCESS;
}