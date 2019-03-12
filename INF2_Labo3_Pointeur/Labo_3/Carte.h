/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Carte.h
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
   /**
    * 
    * @param numeroFamille
    * @param membreFamille
    */
   Carte(unsigned short numeroFamille, char membreFamille);
   /**
    * 
    * @return 
    */
   short unsigned getNumeroFamille() const;
   /**
    * 
    * @param carte
    * @return 
    */
   Carte& operator=(const Carte& carte);
   /**
    * 
    * @param rhs
    * @return 
    */
   bool operator==(const Carte& rhs) const;

   //Surcharge de l'opérateur == entre un pointeur et une carte
   friend bool operator==(const Carte* lhs, const Carte& rhs);
   friend std::ostream& operator<<(std::ostream& os, const Carte& carte);
private:
   const unsigned short NUMERO_FAMILLE;
   const char MEMBRE_FAMILLE;
};

std::ostream& operator<<(std::ostream& os, const Carte& carte);

#endif //INF2_LABO3_CARTE_H
