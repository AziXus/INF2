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
#include <limits>
#include <stdexcept>

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
Fraction<T>& Fraction<T>::operator+=(Fraction<T> rhs) {
    //rhs en copie pour modifications
    //*this = this->simplifier();
    //rhs = rhs.simplifier();

    //Si le même denominateur, addition du numerateur
//    if (denominateur == rhs.denominateur) {
//        if (numerateur > std::numeric_limits<T>::max() - std::abs(rhs.numerateur))
//            throw std::overflow_error("Depassement detecte lors l'addition de la fraction");
//
//        numerateur += rhs.numerateur;
//
//        //*this = this->simplifier();
//    } else {
    //Trouve le plus petit multiple commun
    T multiple = ppcm(denominateur, rhs.denominateur);

    //Multiplier le dénominateur et le numérateur
    //On multiplie par une autre fraction afin de détecter un possible overflow
    //denominateur = multiple;

    rhs   *= Fraction(multiple / rhs.denominateur, multiple / rhs.denominateur);
    *this *= Fraction(multiple / denominateur, multiple / denominateur);

    //Maintenant que les fractions ont le même dénominateur, on peut additioner les numérateurs
    if (numerateur > std::numeric_limits<T>::max() - std::abs(rhs.numerateur))
        throw std::overflow_error("Depassement detecte lors l'addition de la fraction");

    numerateur += rhs.numerateur;

    return *this = this->simplifier();
}

template<typename T>
Fraction<T>& Fraction<T>::operator*=(const Fraction<T>& rhs) {
    //Si a * b > MAX, alors a > MAX / b
    if (numerateur > std::numeric_limits<T>::max() / rhs.numerateur)
        throw std::overflow_error("Depassement detecte lors la multiplication du numerateur de la fraction");
    if (numerateur < std::numeric_limits<T>::lowest() / rhs.numerateur)
        throw std::underflow_error("Depassement detecte lors la multiplication du numerateur de la fraction");

    if (denominateur > std::numeric_limits<T>::max() / rhs.denominateur)
        throw std::overflow_error("Depassement detecte lors la multiplication du denominateur de la fraction");
    //Le denom est toujours positif, on a donc pas besoin de controler l'underflow

    numerateur   *= rhs.numerateur;
    denominateur *= rhs.denominateur;

    return *this;
}

template<typename T>
Fraction<T>::operator float() const {
//    if (numerateur > (T)std::numeric_limits<float>::max())
//        throw;
//    if (denominateur > (T)std::numeric_limits<float>::max())
//        throw;
    return (float)numerateur / (float)denominateur;
}

template<typename T>
Fraction<T>::operator double() const {

//    if (numerateur > std::numeric_limits<double>::max())
//        throw;
//    if (denominateur > std::numeric_limits<double>::max())
//        throw;

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
    //TODO: retourner abs depuis pgcd ?
    T diviseur = std::abs(pgcd(numerateur, denominateur));

    //On simplifie le numerateur et le denominateur si c'est possible
    if (diviseur != 1) {
        irreductible.numerateur = numerateur / diviseur;
        irreductible.denominateur = denominateur / diviseur;
    }

    return irreductible;
}

template<typename T>
T Fraction<T>::ppcm(T a, T b) {
    T diviseur = pgcd(a, b);
    if (a / diviseur > std::numeric_limits<T>::max() / b)
        throw std::overflow_error("Depassement detecte lors du calcul du ppcm");
    return std::abs((a / diviseur) * b);
}

template<typename T>
T Fraction<T>::pgcd(T a, T b) {
    if (a == 0)
        return b;
    return pgcd(b % a, a);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Fraction<T> fraction)
{
    os << fraction.numerateur << "/" << fraction.denominateur;
    return os;
}

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


#endif //FRACTIONIMPL_H
