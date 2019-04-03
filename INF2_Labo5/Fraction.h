/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : Fraction.cpp
 Auteur(s)   : Robin Müller, Teixeira Carvalho Stéphane
 Date        : 03.04.2019

 But         : Créer une classe générique fraction permettant d'éffectuer plusieurs manipulations sur
               des fractions.
               On pourra effectuer des multiplications, des additions ainsi que des 
               simplifications de fraction.

 Remarque(s) : La classe fraction sera de type générique.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/**
 * Classe fraction générique permettant de stocker deux nombres sous forme d'une fraction.
 * @tparam T type de la fraction.
 */
template<typename T> class Fraction;

/**
 * Surcharge de l'opérateur + pour pouvoir additoner 2 fractions
 * @tparam T défini le type de l'opérateur ainsi que celle des fractions
 * @param lhs Fraction de type T à additionner
 * @param rhs Deuxième fraction de type T à additioner 
 * @return le résultat de l'addition des 2 fractions sous forme de fraction
 */
template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 * Surcharge de l'opérateur * pour multiplier 2 fractions
 * @tparam T défini le type de l'opérateur ainsi que celle des fractions
 * @param lhs Fraction de Type T à multiplier
 * @param rhs deuxième fraction de type T à multiplier
 * @return le résultat de la multiplication des 2 fractions sous forme de fraction
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
     * @throws std::invalid_argument en cas de dénominateur égal à 0.
     * @param numerateur valeur de type T indiquant le numerateur de la fraction
     * @param denominateur valeur de type T indiquant le denominateur de la fraction
     */
    Fraction(T numerateur, T denominateur);

    /**
     * Vérifie si les numérateurs et dénominateurs des deux fractions sont égaux.
     * @param rhs Fraction à comparer
     * @return true si elles sont égales, false sinon
     */
    bool operator==(const Fraction<T>& rhs) const;

    /**
     * Additionne une fraction avec une autre
     * @throws std::overflow_error en cas de dépassement de l'addition d'un des numérateurs ou d'un des dénominateurs
     * @throws std::underflow_error en cas de dépassement négatif de l'addition d'un des numérateurs
     * @throws std::overflow_error en cas de dépassement de l'addition des numérateurs des 2 fractions
     * @throws std::underflow_error en cas de dépassement négatif de l'addition des numérateurs des 2 fractions
     * @param rhs Fraction à additionner.
     * @return Fraction actuelle additionnée en référence.
     */
    Fraction<T>& operator+=(const Fraction<T>& rhs);

    /**
     * Multiplie une Fraction par une autre
     * @throws std::overflow_error en cas de dépassement de la multiplication des numérateurs ou des dénominateurs
     * @throws std::underflow_error en cas de dépassement négatif de la multiplication des numérateurs
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
     * @throws std::overflow_error en cas de dépassement de type lors du calcul du ppcm
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
