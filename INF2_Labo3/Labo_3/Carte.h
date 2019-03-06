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
#ifndef INF2_LABO3_CARTE_H
#define INF2_LABO3_CARTE_H

#include <string>
#include <ostream>

class Carte {
public:
   Carte(unsigned numeroFamille, char membreFamille);
   unsigned getNumeroFamille() const;
   bool comparerNumeroFamille(const Carte& carte) const;
   Carte& operator=(const Carte& carte);
   bool operator==(const Carte& rhs) const;
   friend std::ostream& operator<<(std::ostream& os, const Carte& carte);
private:
   const unsigned short NUMERO_FAMILLE;
   const char MEMBRE_FAMILLE;
};


#endif //INF2_LABO3_CARTE_H
