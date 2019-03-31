/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : Fraction.cpp
 Auteur(s)   : Robin Müller
 Date        : 20.03.2019

 But         : Créer une classe fraction permettant d'éffectuer plusieurs manipulations sur
               des fractions.
               On pourra effectuer des multiplications, des addtions ainsi que des 
               simplifactions de fraction.

 Remarque(s) : La classe fraction sera de type générique.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/**
 * Classe fraction générique permettant de stocker deux nombres sous forme d'une fraction.
 * @tparam T type de numérateur et du dénominateur de la fraction.
 */
template<typename T> class Fraction;

/**
 * Surcharge de l'opérateur + pour pouvoir additoner 2 fractions
 * @tparam T défini le type de l'opérateur ainsi que celle des fractions
 * @param lhs Fraction de type T à additionner
 * @param rhs Deuxième fraction de type T à additioner 
 * @return l'addition des 2 fractions sous forme de fraction
 */
template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 * Surhcarge de l'opérateur * pour multiplier 2 fractions
 * @tparam T défini le type de l'opérateur ainsi que celle des fractions
 * @param lhs Fraction de Type T à multiplier
 * @param rhs deuxième fraction de type T à multiplier
 * @return la multiplication des 2 fractions sous forme de fraction
 */
template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 * Surcharge de l'opérateur de flux pour afficher une fraction
 * @tparam T indique le type de la fraction à afficher
 * @param os flux de sortie dans lequel écrire
 * @param fraction fraction de type T à afficher
 * @return référence du flux sur lequel on a écrit
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, Fraction<T> fraction);

template<typename T>
class Fraction {
    friend std::ostream& operator<< <T>(std::ostream& os, Fraction<T> fraction);
    friend Fraction<T> operator+ <T>(Fraction<T> lhs, const Fraction<T>& rhs);
    friend Fraction<T> operator* <T>(Fraction<T> lhs, const Fraction<T>& rhs);

public:
    /**
     * Constructeur spécifique de la classe Fraction
     * @param numerateur valeur de type T indiquant le numerateur de la fraction
     * @param denominateur valeur de type T indiquant le denominateur de la fraction
     */
    Fraction(T numerateur, T denominateur);

    /**
     *
     * @param rhs
     * @return
     */
    bool operator==(const Fraction<T>& rhs) const;

    /**
     *
     * @param rhs
     * @return
     */
    Fraction<T>& operator+=(Fraction<T> rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Fraction<T>& operator*=(const Fraction<T>& rhs);

    /**
     *
     * @return
     */
    operator float() const;

    /**
     *
     * @return
     */
    operator double() const;

    /**
     *
     * @param rhs
     * @return
     */
    bool identite(const Fraction<T>& rhs) const;

    /**
     *
     * @return
     */
    Fraction<T> simplifier();

private:
    T numerateur;
    T denominateur;

    static T pgcd(T a, T b);

    /**
     *
     * @param a
     * @param b
     * @return
     */
    static T ppcm(T a, T b);
};

#include "FractionImpl.h"

#endif //FRACTION_H
