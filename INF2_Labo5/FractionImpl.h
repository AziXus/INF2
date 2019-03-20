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

template <typename T>
Fraction<T>::Fraction(T numerateur, T denominateur) : numerateur(numerateur), denominateur(denominateur) {
    //Comme on souhaite que le numérateur porte le signe, on le multiplie
    //par -1 si le dénominateur est négatif.
    if (denominateur < 0) {
        this->numerateur *= -1;
        this->denominateur *= -1;
    }
}

template<typename T>
Fraction<T>::operator float() {
    return (float)numerateur / (float)denominateur;
}

template<typename T>
Fraction<T>::operator double() {
    return (double)numerateur / (double)denominateur;
}

template<typename T>
Fraction<T> Fraction<T>::simplifier() {
    Fraction irreductible;
    //On calcul le plus grand commun diviseur
    T diviseur = pgcd();

    //On simplifie le numerateur et le denominateur si c'est possible
    if (diviseur != 1) {
        irreductible.numerateur = numerateur / diviseur;
        irreductible.denominateur = denominateur / diviseur;
    }

    return irreductible;
}

template<typename T>
T Fraction<T>::pgcd() {
    T a = numerateur,
      b = denominateur;

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

#endif //FRACTIONIMPL_H
