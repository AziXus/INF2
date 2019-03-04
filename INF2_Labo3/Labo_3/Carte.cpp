/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Carte.cpp
 Auteur(s)   : Robin Müller
 Date        : 01.03.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Carte.h"

using namespace std;

Carte::Carte(char lettreFamille, unsigned numeroFamille):NUMERO_FAMILLE(lettreFamille), LETTRE_FAMILLE(numeroFamille){}

Carte& Carte::operator=(const Carte& carte)
{
    (unsigned&) NUMERO_FAMILLE = carte.NUMERO_FAMILLE;
    (char&) LETTRE_FAMILLE = carte.LETTRE_FAMILLE;
    return *this;
}

ostream& operator<<(ostream& os, const Carte& carte) {
   os << carte.NUMERO_FAMILLE << carte.LETTRE_FAMILLE;
   return os;
}
