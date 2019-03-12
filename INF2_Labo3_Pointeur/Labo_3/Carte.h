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
   /**
   * Surcharge de l'opérateur de flux pour pouvoir afficher une carte sous le format %NUMERO_FAMILLE%%MEMBRE_FAMILLE% (1A, 1B, 2A, ...)
   * @param os flux de sortie dans lequel écrire
   * @param carte carte à afficher
   * @return référence du flux sur lequel on a écrit
   */
   friend std::ostream& operator<<(std::ostream& os, const Carte& carte);
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

private:
   const unsigned short NUMERO_FAMILLE;
   const char MEMBRE_FAMILLE;
};

#endif //INF2_LABO3_CARTE_H
