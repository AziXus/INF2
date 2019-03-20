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

template <typename T>
class Fraction {
public:
    Fraction() = default;
    Fraction(T numerateur, T denominateur);

    operator float();
    operator double();

    Fraction<T> simplifier();

private:
    T numerateur;
    T denominateur;

    T pgcd();
};

#include "FractionImpl.h"

#endif //FRACTION_H
