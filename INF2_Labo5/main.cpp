#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction<int> f1(4, 6);
    Fraction<int> f2(2, 3);
    Fraction<int> f3(4, 13);
    try {
        cout << "Initialisation d'une fraction avec un denominateur nul\n";
        Fraction<int> f4(2, 0);
    } catch (invalid_argument& e) {
        cout << "Erreur: " << e.what() << endl;
    }

    cout << boolalpha << fixed << setprecision(5);

    cout << "f1 = " << f1 << " = " << float(f1) << endl;
    cout << "f2 = " << f2 << " = " << double(f2) << endl;
    cout << "f3 = " << f3 << " = " << float(f3) << endl;

    cout << "f1.identite(f2) : " << f1.identite(f2) << endl;
    cout << "f1 == f2 : " << (f1 == f2) << endl;

    cout << "Simplification de f1 : " << f1.simplifier() << endl;
    cout << "Simplification de f2 : " << f2.simplifier() << endl;
    cout << "Simplification de f3 : " << f3.simplifier() << endl;

    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;

    cout << "\n***** Approximation de pi avec int *****\n";

    int numerateur = 4;
    int k = 1;
    Fraction<int> pi(numerateur, 1);

    try {
        while (true) {
            pi += Fraction<int>((int)pow(-1, k) * numerateur, 2*k + 1);
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << " \npi : " << pi.simplifier() << " = " << (double)pi << endl;
    }

    Fraction<int> pi2(3, 1);
    k = 1;
    try {
        while (true) {
            pi2 += Fraction<int>((int)pow(-1, k - 1) * numerateur, (2 * k)*(2 * k + 1)*(2 * k + 2));
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << " \npi : " << pi2.simplifier() << " = " << (double)pi2 << endl;
    }


    cout << "\n***** Approximation de pi avec long long *****\n";
    Fraction<long long> pi3(numerateur, 1);
    k = 1;
    try {
        while (true) {
            pi3 += Fraction<long long>((long long)pow(-1, k) * numerateur, 2*k + 1);
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << " \npi : " << pi3 << " = " << (double)pi3 << endl;
    }

    Fraction<long long> pi4(3, 1);
    k = 1;
    try {
        while (true) {
            pi4 += Fraction<long long>((long long)pow(-1, k - 1) * numerateur, (2 * k)*(2 * k + 1)*(2 * k + 2));
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << " \npi : " << pi4.simplifier() << " = " << (double)pi4 << endl;
    }

    return EXIT_SUCCESS;
}