/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Teixeira Carvalho Stéphane
 Date        : 03.04.2019

 But         : Test des différentes fonctionnalités de la classe Fractions.
               On affichera deux approximations de Pi grâce au formules de Leibniz
               et Nilakantha.

 Remarque(s) : L'approximation s'arrêtera dès qu'un overflow esr détecté.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Fraction.h"

using namespace std;

/**
 * Calcul de l'approximation de Pi grâce à la formule de Leibniz
 * @tparam T Type de la fraction
 */
template <typename T>
void calculApproximationPiLeibniz()
{
    cout << "Approximation de PI avec la serie de Leibniz" << endl;
    const int NUMERATEUR = 4;//numerateur utilisé par la formule
    int k = 1;
    Fraction<T> pi(NUMERATEUR, 1);
    try {
        //On boucle jusqu'à ce que l'opérateur += nous renvoie un overflow
        while (true) {
            Fraction<T> fraction((T)pow(-1, k) * NUMERATEUR, 2*k + 1);

            cout << "k = " << k << " : " << pi << " + " << fraction << " = ";
            pi += fraction;
            cout << pi << endl;

            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << endl
             << "Approximation finale de pi (Leibniz) : " << pi.simplifier() << " = " << (double)pi << endl;
    }
}

/**
 * Calcul de l'aproxiamtion de Pi grâce à la formule de Nilakantha
 * @tparam T type de la fraction
 */
template <typename T>
void calculApproximationPiNilakantha()
{
    cout << "Approximation de PI avec la serie de Nilakantha" << endl;
    const int NUMERATEUR = 4;//numerateur utilisé par la formule
    int k = 1;
    Fraction<T> pi2(3, 1);
    try {
        while (true) {
            //On boucle jusqu'à ce que l'opérateur += nous renvoie un overflow
            Fraction<T> fraction((T)pow(-1, k - 1) * NUMERATEUR, (2 * k)*(2 * k + 1)*(2 * k + 2));

            cout << "k = " << k << " : " << pi2 << " + " << fraction << " = ";
            pi2 += fraction;
            cout << pi2 << endl;

            ++k;
        }
    } catch (overflow_error& e) {
        cout << "Overflow lors de l'addition " << k << endl
             << "Approximation finale de pi (Nilakantha) : " << pi2.simplifier() << " = " << (double)pi2 << endl;
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

    cout << boolalpha << fixed << setprecision(10);

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
    
    cout << "f1 += f2  " << (f1 += f2) << endl;
    cout << "f1 *= f2  " << (f1 *= f2) << endl;

    cout << "\n***** Approximation de pi avec int *****\n";
    calculApproximationPiLeibniz<int>();
    cout << endl;
    calculApproximationPiNilakantha<int>();

    cout << "\n***** Approximation de pi avec long long *****\n";
    calculApproximationPiLeibniz<long long>();
    cout << endl;
    calculApproximationPiNilakantha<long long>();

    return EXIT_SUCCESS;
}