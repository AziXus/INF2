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


    return EXIT_SUCCESS;
}