/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : FractionImpl.cpp
 Auteur(s)   : Robin Müller
 Date        : 20.03.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef FRACTIONIMPL_H
#define FRACTIONIMPL_H

#include <cmath>

template <typename T>
Fraction<T>::Fraction(T numerateur, T denominateur) : numerateur(numerateur), denominateur(denominateur) {
    if (denominateur == 0) {
        throw;
    }
    
    //Comme on souhaite que le numérateur porte le signe, on le multiplie
    //par -1 si le dénominateur est négatif.
    if (denominateur < 0) {
        this->numerateur *= -1;
        this->denominateur *= -1;
    }
}

template<typename T>
bool Fraction<T>::operator==(const Fraction<T>& rhs) const {
//    Fraction<T> copieRhs = rhs;
//    Fraction<T> copieThis = *this;
//
//    copieRhs.simplifier();
//    copieThis.simplifier();
//
//    return copieThis.numerateur   == copieRhs.numerateur and
//           copieThis.denominateur == copieRhs.denominateur;

    double epsilon = 0.00000001;

    return fabs((double)*this - (double)rhs) < epsilon;
}

template<typename T>
Fraction<T>& Fraction<T>::operator+=(Fraction<T> rhs) {
 /*for addition
#include <limits.h>
int a = <something>;
int x = <something>;
if ((x > 0) && (a > INT_MAX - x)) // `a + x` would overflow;
if ((x < 0) && (a < INT_MIN - x)) // `a + x` would underflow;
*/
    //Si a * b > MAX, alors a > MAX / b

    //rhs en copie pour modifications

    //Si le même denominateur, addition du numerateur
    if (denominateur == rhs.denominateur)
        numerateur += rhs.numerateur;
    else {
        //Trouver le plus petit multiple commun
        T multiple = ppcm(denominateur, rhs.denominateur);

        //Multiplier le dénominateur et le numérateur
        rhs *= Fraction(multiple / rhs.denominateur, multiple / rhs.denominateur);
        *this *= Fraction(multiple / denominateur, multiple / denominateur);

        //Additioner
        *this += rhs;
    }

    return *this;
}

template<typename T>
Fraction<T>& Fraction<T>::operator*=(const Fraction<T>& rhs) {
/*// for multiplication
#include <limits.h>
int a = <something>;
int x = <something>;
if (a > INT_MAX / x) // `a * x` would overflow;
if ((a < INT_MIN / x)) // `a * x` would underflow;
// there may be need to check for -1 for two's complement machines
if ((a == -1) && (x == INT_MIN)) // `a * x` can overflow
if ((x == -1) && (a == INT_MIN)) // `a * x` (or `a / x`) can overflow*/
    //Si a + b > MAX, alors a > MAX - b
    numerateur *= rhs.numerateur;
    denominateur *= rhs.denominateur;

    return *this;
}

template<typename T>
Fraction<T>::operator float() const {
    return (float)numerateur / (float)denominateur;
}

template<typename T>
Fraction<T>::operator double() const {
    return (double)numerateur / (double)denominateur;
}

template<typename T>
bool Fraction<T>::identite(const Fraction<T>& rhs) const {
    return numerateur   == rhs.numerateur and
           denominateur == rhs.denominateur;
}

template<typename T>
Fraction<T> Fraction<T>::simplifier() {
    Fraction<T> irreductible = *this;
    //On calcul le plus grand commun diviseur
    T diviseur = pgcd(numerateur, denominateur);

    //On simplifie le numerateur et le denominateur si c'est possible
    if (diviseur != 1) {
        irreductible.numerateur = numerateur / diviseur;
        irreductible.denominateur = denominateur / diviseur;
    }

    return irreductible;
}

template<typename T>
T Fraction<T>::pgcd(T a, T b) const {
    //L'algorithme fonctionne uniquement avec des nombres positifs
    a = abs(a),
    b = abs(b);

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

template<typename T>
T Fraction<T>::ppcm(T a, T b) const {
    return abs(a * b) / pgcd(a, b);
}


#endif //FRACTIONIMPL_H
