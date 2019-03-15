/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Carte.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Carte.h"

using namespace std;

Carte::Carte(unsigned short numeroFamille, char membreFamille) : NUMERO_FAMILLE(numeroFamille), MEMBRE_FAMILLE(membreFamille){}

unsigned short Carte::getNumeroFamille() const
{
   return NUMERO_FAMILLE;
}

Carte& Carte::operator=(const Carte& carte)
{
   (unsigned&)NUMERO_FAMILLE = carte.NUMERO_FAMILLE;
   (char&)MEMBRE_FAMILLE = carte.MEMBRE_FAMILLE;
   return *this;
}

bool Carte::operator==(const Carte& rhs) const {
   return NUMERO_FAMILLE == rhs.NUMERO_FAMILLE and
          MEMBRE_FAMILLE == rhs.MEMBRE_FAMILLE;
}

ostream& operator<<(ostream& os, const Carte& carte) {
   os << carte.NUMERO_FAMILLE << carte.MEMBRE_FAMILLE;
   return os;
}
