#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Fraction.h"

using namespace std;

template <typename T>
void calculApproximationPi(int numerateur)
{
    int k = 1;
    Fraction<T> pi(numerateur, 1);
    //try catch dans 
    try {       
        while (true) {
            pi += Fraction<T>((T)pow(-1, k) * numerateur, 2*k + 1);
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << " \npi : " << pi.simplifier() << " = " << (double)pi << endl;  
    }
}

template <typename T>
void calculApproximationPi2(int numerateur)
{
    int k = 1;
    Fraction<T> pi2(3, 1);
    try {
        while (true) {
            pi2 += Fraction<T>((T)pow(-1, k - 1) * numerateur, (2 * k)*(2 * k + 1)*(2 * k + 2));
            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << " \npi : " << pi2.simplifier() << " = " << (double)pi2 << endl;
    }
}

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
    
    calculApproximationPi<int>(numerateur);
    calculApproximationPi2<int>(numerateur);

    cout << "\n***** Approximation de pi avec long long *****\n";
    calculApproximationPi<long long>(numerateur);
    calculApproximationPi2<long long>(numerateur);


    return EXIT_SUCCESS;
}