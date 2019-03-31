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

#include <iostream>

/**
 * Classe fraction générique permettant de stocker deux nombres sous forme d'une fraction.
 * @tparam T type de numérateur et du dénominateur de la fraction.
 */
template<typename T> class Fraction;

/**
 *
 * @tparam T
 * @param lhs
 * @param rhs
 * @return
 */
template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 *
 * @tparam T
 * @param lhs
 * @param rhs
 * @return
 */
template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 *
 * @tparam T
 * @param os
 * @param fraction
 * @return
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
     *
     * @param numerateur
     * @param denominateur
     */
    Fraction(T numerateur, T denominateur);

    /**
     * Vérifie si la valeur des deux fractions est égal.
     * @param rhs Fraction à comparer
     * @return true si elles sont égales, false sinon
     */
    bool operator==(const Fraction<T>& rhs) const;

    /**
     * Additionne une fraction avec une autre
     * @param rhs Fraction à additionner.
     * @return Fraction actuelle additionnée en référence.
     */
    Fraction<T>& operator+=(Fraction<T> rhs);

    /**
     * Multiple une Fraction par une autre
     * @throws std::overflow_error en cas de dépassement de la multiplication du numérateur ou dénominateur
     * @throws std::underflow_error en cas de dépassement négatif de la multiplication du numérateur
     * @param rhs Fraction à multiplier
     * @return Fraction actuelle multipliée en reférence
     */
    Fraction<T>& operator*=(const Fraction<T>& rhs);

    /**
     * Converti la Fraction en un nombre décimal (float)
     * @return Fraction en float
     */
    operator float() const;

    /**
     * Converti la Fraction en un nombre décimal (double)
     * @return Fraction en double
     */
    operator double() const;

    /**
     * Test l'égalité des numérateurs et dénominateurs avec une seconde fraction du même type.
     * @param rhs Fraction du même type à comparer
     * @return true si elles sont identiques, false sinon
     */
    bool identite(const Fraction<T>& rhs) const;

    /**
     * Calcul la fraction irréductible et la retourne sans modifier la fraction actuelle.
     * @return Fraction irréductible
     */
    Fraction<T> simplifier();

    /**
     * Fonction statique calculant le plus grand commun diviseur de deux élèments.
     * @param a premier élément de type T
     * @param b second élément de type T
     * @return retourne le plus petit commun diviseur
     */
    static T pgcd(T a, T b);

    /**
     * Fonction statique calculant le plus petit commun multiples de deux élèments.
     * @throws std::overflow_error en cas de dépassement du ppcm
     * @param a premier élément de type T
     * @param b second élément de type T
     * @return retourne le plus petit commun multiple positif
     */
    static T ppcm(T a, T b);

private:
    T numerateur;
    T denominateur;
};

#include "FractionImpl.h"

#endif //FRACTION_H
