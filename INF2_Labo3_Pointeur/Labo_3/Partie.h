/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Création d'une classe Partie pour gérer le déroulement du jeu des "N" familles.
               La partie fait jouer les différents joueurs.

 Remarque(s) : La partie est constituée de 1 à plusieurs joueurs et 1 à plusieurs familles.
               Le nombre de carte par joueur ainsi que les cartes par famille sont également défini
               à la création d'une partie et ne peuvent pas être changés.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include "Joueur.h"
#include "Carte.h"

using Joueurs = std::vector<Joueur*>;

/**
 * Gère le déroulement d'une partie du jeu des "N" familles et simule les tours de plusieurs joueurs.
 */
class Partie {
public:
   /**
    * Constructeur spécifique pour la classe Partie
    * @param joueurs vecteur contenant les joueurs 
    * @param nbFamille entier non-signé indiquant le nombre de famille pour la partie 
    * @param carteParFamille entier non-signé indiquant le nombre de carte par famille
    * @param carteParJoueur entier non-signé indiquant le nombre de carte à distribuer par joueur
    */
   Partie(Joueurs& joueurs, unsigned short nbFamille, unsigned short carteParFamille, unsigned short carteParJoueur);

   /**
    * Permet d'afficher les joueurs
    */
   void afficherJoueurs() const;

   /**
    * Fonction permettant de démarrer une partie et d'afficher son déroulement
    */
   void jouer();

   /**
    * Détermine si la partie est terminée. Une partie se termine lorsque plus personne n'a de cartes en main et que la
    * pioche est vide.
    * @return true si la partie est terminée, false sinon
    */
   bool estTerminee();

private:
   /**
    * Fonction permettant de jouer un tour
    */
   void jouerTour();

   /**
    * Génère les cartes pour la partie en fonction du nombre de familles et de cartes par famille
    * @return un vecteur de cartes avec les cartes générées
    */
   Cartes genererCartes();

   /**
    * Distribue les cartes aux joueurs de la partie
    */
   void distribuerCartes();

   /**
    * Choisi des cartes et les echangent avec un autre joueur tant qu'il possède la carte demandée
    * @param joueur joueur demandant des cartes
    * @param cible joueur qui doit donner des cartes
    */
   void echangerCartes(Joueur& joueur, Joueur& cible);

   /**
    * Fait piocher la dernière carte de la pioche à un joueur
    * @param joueur joueur devant piocher
    */
   void piocher(Joueur& joueur);

   /**
    * Mélange la pioche de la partie
    */
   void melangerPioche();

   /**
    * Permet à la partie de choisir la cible d'un joueur.
    * Si aucune cible n'est disponible, le joueur en paramètre est retourné
    * @param joueur joueur demandant une cible
    * @return le joueur ciblé
    */
   Joueur& choisirCible(Joueur& joueur);

   /**
    * Calcul le nombre de joueur en jeu qui ont encore des cartes en main
    * @return le nombre de joueur en jeu
    */
   unsigned nbJoueursEnJeu();

   const unsigned short NOMBRE_FAMILLES;
   const unsigned short CARTES_PAR_FAMILLES;
   const unsigned short CARTES_PAR_JOUEURS;
   Joueurs joueurs;
   Cartes pioche;
   unsigned numeroTour = 0;
};

#endif /* PARTIE_H */

