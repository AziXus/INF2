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

Carte::Carte(unsigned numeroFamille, char membreFamille) : NUMERO_FAMILLE(numeroFamille), MEMBRE_FAMILLE(membreFamille){}

unsigned Carte::getNumeroFamille() const
{
    return NUMERO_FAMILLE;
}

bool Carte::comparerNumeroFamille(const Carte& carte) const
{
    return NUMERO_FAMILLE == carte.NUMERO_FAMILLE;
}

Carte& Carte::operator=(const Carte& carte)
{
    (unsigned&)NUMERO_FAMILLE = carte.NUMERO_FAMILLE;
        (char&)MEMBRE_FAMILLE = carte.MEMBRE_FAMILLE;
    return *this;
}

bool Carte::operator==(const Carte& rhs) const {
   return NUMERO_FAMILLE == rhs.NUMERO_FAMILLE &&
          MEMBRE_FAMILLE == rhs.MEMBRE_FAMILLE;
}

ostream& operator<<(ostream& os, const Carte& carte) {
   os << carte.NUMERO_FAMILLE << carte.MEMBRE_FAMILLE;
   return os;
}
