/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Classe joueur permettant de gérer un joueur et ses cartes.
               Un joueur a un prénom et possède une main de cartes et les familles qu'il a formé

 Remarque(s) : Les cartes en main du joueur et les familles qu'ils possèdent sont des vecteurs de cartes.
               Le joueur stocke le score des parties qu'il a joué.
               MeilleurJoueur : Classe dérivée avec un algorithme de choix de cartes amélioré

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include "Carte.h"
#include <vector>

using Cartes = std::vector<Carte>;

/**
 * Gère les cartes (main et familles) d'un joueur et décide des cartes à demander
 */
class Joueur {
   /**
   * Surcharge de l'opérateur de flux pour pouvoir afficher un joueur
   * @param os flux de sortie dans lequel écrire
   * @param joueur joueur à afficher
   * @return référence du flux sur lequel on a écrit
   */
   friend std::ostream& operator<<(std::ostream& os, const Joueur& joueur);

public:
   /**
    * Constructeur spécifique de la classe joueur
    * @param prenom string contenant le prenom du joueur
    */
   Joueur(const std::string& prenom);

   /**
    * Destructeur par défaut de Joueur.
    * Virtuel afin de pouvoir le surcharger dans les classes heritées.
    */
   virtual ~Joueur() = default;

   /**
    * Retourne le prenom du joueur
    * @return string contenant le prenom du joueur
    */
   std::string getPrenom() const;

   /**
    * Retourne le score du joueur(nombre de famille posée)
    * @return entier non-signé indiquant le score su joueur
    */
   unsigned int getScore() const;

   /**
    * Trouve les cartes de sa main de la même famille que la carte passé en paramètre
    * @param carte la carte définissant la famille à rechercher
    * @return les cartes en main de la même famille que la carte demandé
    */
   Cartes trouverFamille(const Carte& carte);

   /**
    * Retourne le paquet de carte que le joueur à dans sa main
    * @return les cartes en main du joueur
    */
   const Cartes& getCartesMain() const;

   /**
    * Enlève une carte de la main du joueur
    * @param carte la carte à enlever de la main du joueur
    */
   void enleverCarteMain(const Carte& carte);

   /**
    * Ajoute une carte à la main du joueur
    * @param carte la carte à ajouter à la main du joueur
    */
   void ajoutCarteMain(const Carte& carte);

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
    * Cherche dans les cartes en main si une famille est complete et la dépose dans familles sur table si c'est le cas
    * @param cartesParFamilles entier non-signé nombre de carte par famille
    * @return true si une famille a été posée, false sinon
    */
   bool detecterFamille(unsigned cartesParFamilles);

   /**
    * Retourne le nombre de carte dans la main du joueur
    * @return un entier non-signé indiquant le nombre de cartes
    */
   size_t nbCartesEnMain() const;

   /**
    * Fonction permettant d'enlever les cartes et les familles du joueur
    */
   void resetCartes();

private:
   /**
    * Enlève les cartes effectuant une famille de la main du joueur et l'ajoute dans le paquet des familles du joueur
    * @param cartes cartes à ajouter
    */
   void ajoutFamille(const Cartes& cartes);

   std::string prenom;
   unsigned nbFamilles = 0;
   unsigned score = 0;
   Cartes cartesEnMain;
   Cartes famillesSurTable;
};

/**
 * Hérite de Joueur en améliorant l'algorithme de demande de cartes
 */
class MeilleurJoueur : public Joueur {
public:
   MeilleurJoueur(const std::string& prenom);

   /**
    * Surcharge de la fonction demanderCarte améliorant l'algorithme
    * @param cartesParFamille Nb de cartes par famille
    * @return la carte à demander
    */
   Carte demanderCarte(unsigned cartesParFamille);

private:
};

/**
 * Permet d'afficher un vecteur de Cartes
 * La fonction n'est pas en friend pour pouvoir l'utiliser dans tout le programme
* @param os flux de sortie dans lequel écrire
* @param cartes cartes à afficher
* @return référence du flux sur lequel on a écrit
*/
std::ostream& operator<<(std::ostream& os, const Cartes& cartes);

#endif /* JOUEUR_H */

