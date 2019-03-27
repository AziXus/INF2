/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Fraction.cpp
 Auteur(s)   : Robin Müller
 Date        : 20.03.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef FRACTION_H
#define FRACTION_H
#include <ostream>


template <typename T> class Fraction;

template <typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T>& rhs);

template <typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T>& rhs);

template <typename T>
std::ostream& operator<<(std::ostream& os, Fraction<T> fraction);

template <typename T>
class Fraction {
    friend std::ostream& operator<< <T>(std::ostream& os, Fraction<T> fraction);
    friend Fraction<T> operator+ <T>(Fraction<T> lhs, const Fraction<T>& rhs);
    friend Fraction<T> operator* <T>(Fraction<T> lhs, const Fraction<T>& rhs);
public:
    Fraction() = default;
    Fraction(T numerateur, T denominateur);

    bool operator==(const Fraction<T>& rhs) const;
    Fraction<T>& operator+=(Fraction<T> rhs);
    Fraction<T>& operator*=(const Fraction<T>& rhs);

    operator float() const;
    operator double() const;

    bool identite(const Fraction<T>& rhs) const;
    Fraction<T> simplifier();

private:
    T numerateur;
    T denominateur;

    T pgcd(T a, T b) const;
    T ppcm(T a, T b) const;
};

#include "FractionImpl.h"

#endif //FRACTION_H
