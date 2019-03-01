/*
 -----------------------------------------------------------------------------------
 Labo       : 01
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 26.02.19

 Purpose    : Test the class Point and its different functions.

 Comment(s) : Overload of the << operator to print a Point.

 Compiler   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Point.h"

using namespace std;

/**
 * Overload of the operator<< for the Point class that display the polar and cartesian coordinates
 * @param os ostream to modify
 * @param p Point to print
 * @return modified ostream
 */
ostream& operator<<(ostream& os, const Point& p);

int main() {
    Point p1,
          p3,
          p4(1.f, 0.f);
    const Point P2(4.7f, 3.3f);

    cout << "Coordinates of p1:\n" << p1 << "\n\n";

    p1.deplacer(5.3f, 6.7f);
    cout << "Coordinates of p1 after a translation by 5.3 on x and 6.7 on y:\n" << p1 << "\n\n";

    cout << "Coordinates of P2:\n" << P2 << "\n\n";

    p3 = p1 + P2;
    cout << "Coordinates of p3 (p1 + P2):\n" << p3 << "\n\n";

    cout << "Coordinates of p4:\n" << p4 << "\n\n";

    cout << "Rotating p4 with a 45 degree angle 8 times:\n";
    for (int i = 1; i <= 8; ++i) {
        p4.rotation((float)M_PI / 4);
        cout << i << ": " << p4 << endl;
    }

    return EXIT_SUCCESS;
}

ostream& operator<<(ostream& os, const Point& p) {
    const int coordinateWidth = 6,
              precision       = 3;

    //Using showpos to show (+) sign
    //Add cartesian and polar coordinates to ostream
    os << fixed << setprecision(precision) << showpos
       << "(" << setw(coordinateWidth) << p.abscisse() << ", " << setw(coordinateWidth) << p.ordonnee() << ") cartesian, "
       << "(" << setw(coordinateWidth) << p.rho()      << ", " << setw(coordinateWidth) << p.theta()    << "rad) polar"
       << noshowpos;

    return os;
}