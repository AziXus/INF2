/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Création d'une classe Partie pour gérer le déroulement du jeux.
               La partie fait jouer les différents joueurs.

 Remarque(s) : La partie est constituée de 1 à plusieurs joueurs et 1 à plusieurs familles.
               Le nombre de carte par jouer ainsi que les cartes par famille sont également défini
               pour une partie et ne peuvent pas être changés.               

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */
#ifndef PARTIE_H
#define PARTIE_H
#include <vector>
#include "Joueur.h"
#include "Carte.h"

using Joueurs = std::vector<Joueur*>;

class Partie{
public:
   /**
    * Constructeur spécifique pour la classe Partie
    * @param joueurs vecteur contenant les joueurs 
    * @param nbFamille entier non-signé indiquant le nombre de famille pour la partie 
    * @param carteParFamille entier non-signé indiquant le nombre de carte par famille
    * @param carteParJoueur entier non-signé indiquant le nombre de carte par joueur
    */
   Partie(Joueurs& joueurs, unsigned short nbFamille, unsigned short carteParFamille, unsigned short carteParJoueur);

   /**
    * Retourne la pioche de la partie
    * @return la pioche de la partie sous forme de vecteur de carte
    */
   const Cartes& getPioche() const;

   /**
    * Retourne les joueurs de la partie
    * @return les joueurs de la partie sous forme de vecteur de joueur
    */
   const Joueurs& getJoueurs() const;

   /**
    * Permet d'afficher les jouerus
    */
   void afficherJoueurs() const;

   /**
    * Fonction permettant de démarrer une partie.
    */
   void jouer();

   /**
    * Fonction permettant de faire jouer un tour au joueurs
    */
   void jouerTour();

   /**
    * Détermine si la partie est terminée. Une partie se termine lorsque plus personne n'a de cartes en main et que la
    * pioche est vide.
    * @return true si la partie est terminée, false sinon
    */
   bool estTerminee();

   /**
    * Retourne le score du joueur desiré.
    * @param joueur joueur dont on doit calculer le score
    * @return score du joueur désiré
    */
   unsigned scoreJoueur(const Joueur& joueur);

private:
   /**
    * Génère les cartes pour la partie en fonction du nombre de familles et de carte par famille
    * @return un vecteur de cartes avec les cartes générées
    */
   Cartes genererCartes();

   /**
    * Distribue les cartes au joueurs
    */
   void distribuerCartes();

   /**
    * 
    * @param joueur
    */
   void tourJoueur(Joueur& joueur);

   /**
    * Fait piocher la dernière carte de la picohe à un joueur
    * @param joueur joueur devant piocher
    * @return true si une carte a été pioché, false sinon
    */
   bool piocher(Joueur& joueur);

   /**
    * melange la pioche de la partie
    */
   void melangerPioche();

   /**
    * Permet à la partie de choisir une cible pour un joueur
    * @param joueur joueur demandant une cible
    * @return la joueur cible
    */
   Joueur& choisirCible(const Joueur& joueur);

   const unsigned short NOMBRE_FAMILLES;
   const unsigned short CARTES_PAR_FAMILLES;
   const unsigned short CARTES_PAR_JOUEURS;
   Joueurs joueurs;
   Cartes pioche;
   unsigned nbTour = 0;
};

#endif /* PARTIE_H */

