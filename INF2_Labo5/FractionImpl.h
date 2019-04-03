/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : FractionImpl.cpp
 Auteur(s)   : Robin Müller
 Date        : 20.03.2019

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef FRACTIONIMPL_H
#define FRACTIONIMPL_H

#include <cmath>
#include <limits>
#include <stdexcept>

template <typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T>& rhs) {
    lhs += rhs;
    return lhs;
}

template <typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T>& rhs) {
    lhs *= rhs;
    return lhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Fraction<T> fraction)
{
    os << fraction.numerateur << "/" << fraction.denominateur;
    return os;
}

template <typename T>
Fraction<T>::Fraction(T numerateur, T denominateur) : numerateur(numerateur), denominateur(denominateur) {
    if (denominateur == 0) {
        throw std::invalid_argument("Le denominateur ne peut pas valoir 0");
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
    double epsilon = 0.000000000001;//permet de définir jusqu'à quelle décimal une fraction est égale
    return std::abs((double)*this - (double)rhs) < epsilon;
}

template<typename T>
Fraction<T>& Fraction<T>::operator+=(const Fraction<T>& rhs) {
    //Trouve le plus petit multiple commun
    T multiple = ppcm(denominateur, rhs.denominateur);

    //Overflow du numérateur de lhs lors de la multiplication suivante numerateur * (ppcm / denominateur)
    if (numerateur / denominateur > std::numeric_limits<T>::max() / multiple)
        throw std::overflow_error("Debordement detecte lors de l'addition de la fraction");
    if (numerateur / denominateur < std::numeric_limits<T>::lowest() / multiple)
        throw std::underflow_error("Debordement négatif detecte lors de l'addition de la fraction");

    //Overflow du numerateur de rhs lors de la multiplication suivante numerateur * (ppcm / denominateur)
    if (rhs.numerateur / rhs.denominateur > std::numeric_limits<T>::max() / multiple)
        throw std::overflow_error("Debordement detecte lors de l'addition de la fraction");
    if (rhs.numerateur / rhs.denominateur < std::numeric_limits<T>::lowest() / multiple)
        throw std::underflow_error("Debordement négatif detecte lors de l'addition de la fraction");

    //Si on a pas d'overflow, on calcul les deux dénominateurs sans modifier les fractions grâce à des variables temporaires
    T numerateurLhs = numerateur * (multiple / denominateur);
    T numerateurRhs = rhs.numerateur * (multiple / rhs.denominateur);

    //Overflow lors de l'addition des numérateurs
    if (numerateurRhs > 0 and numerateurLhs > std::numeric_limits<T>::max() - numerateurRhs)
        throw std::overflow_error("Debordement detecte lors de l'addition de la fraction, numerateurs trop grands");
    if (numerateurRhs < 0 and numerateurLhs < std::numeric_limits<T>::lowest() - numerateurRhs)
        throw std::underflow_error("Debordement négatif detecte lors de l'addition de la fraction, numerateurs trop petits");

    //Si on a pas d'overflow, on additionne les numérateurs
    numerateur = numerateurLhs + numerateurRhs;
    denominateur = multiple;

    return *this = this->simplifier();
}

template<typename T>
Fraction<T>& Fraction<T>::operator*=(const Fraction<T>& rhs) {
    //Overflows numérateur
    if (numerateur > std::numeric_limits<T>::max() / rhs.numerateur)
        throw std::overflow_error("Debordement detecte lors la multiplication du numerateur de la fraction, numerateurs trop grands");
    if (numerateur < std::numeric_limits<T>::lowest() / rhs.numerateur)
        throw std::underflow_error("Debordement négatif detecte lors la multiplication du numerateur de la fraction, numerateurs trop petit");

    //Overflow dénominateur
    if (denominateur > std::numeric_limits<T>::max() / rhs.denominateur)
        throw std::overflow_error("Debordement detecte lors la multiplication du denominateur de la fraction, denominateurs trop grands");
    //Le denom est toujours positif, on a donc pas besoin de controler l'underflow
    
    numerateur   *= rhs.numerateur;
    denominateur *= rhs.denominateur;

    return *this = this->simplifier();
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
    T diviseur = std::abs(pgcd(numerateur, denominateur));

    //On simplifie le numerateur et le denominateur si c'est possible
    if (diviseur != 1) {
        irreductible.numerateur = numerateur / diviseur;
        irreductible.denominateur = denominateur / diviseur;
    }

    return irreductible;
}

template<typename T>
T Fraction<T>::pgcd(T a, T b) {
    if (a == 0)
        return b;
    return pgcd(b % a, a);
}

template<typename T>
T Fraction<T>::ppcm(T a, T b) {
    T diviseur = pgcd(a, b);
    //Detecte s'il y a un dépassement dans le calcul du ppcm
    if (a / diviseur > std::numeric_limits<T>::max() / b)
        throw std::overflow_error("Depassement detecte lors du calcul du ppcm");
    return std::abs((a / diviseur) * b);
}

#endif //FRACTIONIMPL_H
