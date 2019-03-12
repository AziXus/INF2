/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Classe joueur permttant de gérer un joeur est ses cartes.
               Un joueur est composé d'un nombre de carte et des familles qu'ils possèdent 

 Remarque(s) : Les cartes en main du jouer et les familles qu'ils possèdent sont des vecteurs de cartes

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#ifndef JOUEUR_H
#define JOUEUR_H
#include "Carte.h"
#include <vector>

using Cartes = std::vector<const Carte*>;

class Joueur{
   friend std::ostream& operator<<(std::ostream& os, const Cartes& cartes);
   friend std::ostream& operator<<(std::ostream& os, const Joueur& joueur);
public:
   /**
    * Constructeur par défaut de la classe joueur
    */
   Joueur() = default;

   /**
    * Destructeur par défaut de Joueur.
    * Virtuel afin de pouvoir le surcharger dans les classes heritées.
    */
   virtual ~Joueur() = default;

   /**
    * Constructeur spécifique de la classe joueur
    * @param prenom string contenant le prenom du joueur
    */
   Joueur(const std::string& prenom);
   /**
    * Retourne le prenom du joueur
    * @return string contenant le prenom du joueur
    */
   std::string getPrenom() const;

   unsigned int getScore() const;

   /**
    * Retourne les cartes que le joueur à dans sa main par rapport à la famille
    * de la carte passée.
    * @param carte la carte définissant la famille à utiliser
    * @return le cartes de la même famille que le joueur a
    */
   Cartes getFamille(const Carte& carte);

   const Cartes& getCartesMain() const;

   /**
    * Retourne le nombre de familles déposées par le joueur
    * @return nombre de familles
    */
   unsigned int getNbFamilles() const;

   /**
    * Enlève une carte de la main du joueur
    * @param carte la carte à enlever de la mian du joueur
    */
   const Carte* enleverCarteMain(const Carte& carte);

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
    * Permet de savoir si le joueur à la carte dans sa main
    * @param carte carte à chercher dans sa main
    * @return vrai si la carte est trouvée faux sinon
    */
   bool carteEnMain(const Carte& carte);

   /**
    * Fonction permettant de générer la carte à demander à un autre joueur
    * @param cartesParFamille Nb de carte par famille
    * @return la carte à demander
    */
   virtual Carte demanderCarte(unsigned cartesParFamille);
   /**
    * 
    * @param cartesParFamilles
    * @return 
    */
   bool deposerFamille(unsigned cartesParFamilles);
   /**
    * 
    * @return 
    */
   size_t nbCarteEnMain() const;

   void rendreCarte();

   bool operator==(const Joueur& rhs) const;

private:
   std::string prenom;
   unsigned nbFamilles = 0;
   unsigned score = 0;

private:
   Cartes cartesMain;
   Cartes cartesFamille;
};
/**
 * 
 * @param os
 * @param cartes
 * @return 
 */
std::ostream& operator<<(std::ostream& os, const Cartes& cartes);
/**
 * 
 * @param os
 * @param joueur
 * @return 
 */
std::ostream& operator<<(std::ostream& os, const Joueur& joueur);

class MeilleurJoueur : public Joueur {
public:
   MeilleurJoueur(const std::string& prenom);
   ~MeilleurJoueur() = default;

   Carte demanderCarte(unsigned cartesParFamille) override;
private:
};

#endif /* JOUEUR_H */

