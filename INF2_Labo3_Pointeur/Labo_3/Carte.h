/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Carte.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Classe Carte permettant de stocker une carte du jeu des "N" familles.
               Une carte est composée d'un numéro de famille ainsi qu'une lettre qui définit son index dans la famille.

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef CARTE_H
#define CARTE_H

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
    * Constructeur spécifique de la classe Carte avec le numéro et le membre de la famille specifiés
    * @param numeroFamille numéro de la famille de la carte
    * @param membreFamille lettre de la carte
    */
   Carte(unsigned short numeroFamille, char membreFamille);

   /**
    * Retourne le numéro de la famille de la carte
    * @return numero de la famille
    */
   unsigned short getNumeroFamille() const;

   /**
    * Surcharge de l'opérateur d'affectation pour les fonctions de la STL
    * @param carte carte à affecter
    * @return carte modifié en référence
    */
   Carte& operator=(const Carte& carte);

   /**
    * Surcharge de l'opérateur d'égalité entre deux cartes pour les fonctions de la STL
    * @param rhs seconde carte à comparer
    * @return true si les deux cartes sont égales, false sinon
    */
   bool operator==(const Carte& rhs) const;

private:
   const unsigned short NUMERO_FAMILLE;
   const char MEMBRE_FAMILLE;
};

#endif //CARTE_H
