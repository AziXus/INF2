/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Classe joueur permttant de gérer un joeur est ses cartes.
               Un joueur est composé d'un nombre de carte et des familles qu'ils possèdent 

 Remarque(s) : Les cartes en main du joueur et les familles qu'ils possèdent sont des vecteurs de cartes

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#ifndef JOUEUR_H
#define JOUEUR_H
#include "Carte.h"
#include <vector>

using Cartes = std::vector<Carte>;

class Joueur{
public:
   /**
    * Constructeur par défaut de la classe joueur
    */
   Joueur() = default;
   /**
    * Constructeur spécifique de la classe joueur
    * @param prenom string contenant le prenom du joueur
    */
   Joueur(const std::string& prenom);
   /**
    * Enlève une carte de la main du joueur
    * @param carte la carte à enlever de la mian du joueur
    */
   void enleverCarteMain(const Carte& carte);
   /**
    * Ajoute une carte à la main du joueur
    * @param carte la carte à ajouter à la main du joueur
    */
   void ajoutCarteMain(const Carte& carte);
   /**
    * Enlève les cartes effectuant une famille de la main du joueur et l'ajoute dans le paquet des familles du joueur
    * @param cartes cartes à ajouter
    */
   void ajoutFamille(const Cartes& cartes);
   /**
    * Permet de savoir si le joueur
    * @param carte
    * @return 
    */
   bool carteEnMain(const Carte& carte);
   Carte demanderCarte(const unsigned cartesParFamille);
   Cartes getFamille(const Carte& carte);
   bool detecterFamille(unsigned cartesParFamilles);
   unsigned nbCarteEnMain();
   std::string getPrenom() const;
   friend std::ostream& operator<<(std::ostream& os, const Cartes& cartes);
   friend std::ostream& operator<<(std::ostream& os, const Joueur& joueur);

private:
   std::string prenom;
   Cartes cartesMain;
   Cartes cartesFamille;
};

#endif /* JOUEUR_H */

