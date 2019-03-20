#include <cstdlib>
#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction<int> f1(4, 6);

    cout << (double)f1 << endl;
    cout << (float)f1 << endl;
    cout << "Simplification de f1 : " << (double)f1.simplifier() << endl;

    return EXIT_SUCCESS;
}