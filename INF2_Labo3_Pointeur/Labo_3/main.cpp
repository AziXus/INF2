/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Mettre en place une simulation d'une partie du jeux des familles.
               La partie sera suivi grâce à un affchage de chaque tour.
               Le système utilise les classes Joueur, Partie et Carte.

 Remarque(s) : Les joueurs sont contenus dans un vecteur de jouer.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Partie.h"

using namespace std;

using Joueurs = vector<Joueur*>;

Joueurs genererJoueurs(unsigned nbJoueurs) {
   Joueurs joueurs(nbJoueurs);

   //Le premier joueur est le meilleur joueur
   joueurs[0] = new MeilleurJoueur("MeilleurJoueur");

   for (size_t i = 1; i < nbJoueurs; ++i) {
      joueurs[i] = new Joueur("Joueur" + to_string(i));
   }

   return joueurs;
}

void supprimerJoueurs(Joueurs& joueurs) {
   for (Joueur* j: joueurs) {
      delete j;
   }
}


int main() {
   const unsigned NOMBRE_PARTIES     =   100,
                  NOMBRE_JOUEURS     =     4,
                  NOMBRE_FAMILLES    =     9,
                  CARTES_PAR_FAMILLE =     4,
                  CARTES_PAR_JOUEURS =     5;

   Joueurs joueurs = genererJoueurs(NOMBRE_JOUEURS);

   //Ordre des joueurs fixes (croissant)
/*   for (unsigned i = 1; i <= NOMBRE_PARTIES; ++i) {
      cout << "********** PARTIE " << i << " **********\n";
      Partie p(joueurs, NOMBRE_FAMILLES, CARTES_PAR_FAMILLE, CARTES_PAR_JOUEURS);

      //Lancement de la partie
      p.jouer();

      cout << "\n********** FIN PARTIE " << i << " **********\n";
   }*/

   //Le perdant joue en premier
/*   for (unsigned i = 1; i <= NOMBRE_PARTIES; ++i) {
      //On calcul le joueur ayant le nombre de familles le plus petit
      auto perdant = min_element(joueurs.begin(), joueurs.end(), [](const Joueur* j1, const Joueur* j2) {return j1->getNbFamilles() < j2->getNbFamilles();});
      rotate(joueurs.begin(), perdant, joueurs.end());

      cout << "********** PARTIE " << i << " **********\n";
      Partie p(joueurs, NOMBRE_FAMILLES, CARTES_PAR_FAMILLE, CARTES_PAR_JOUEURS);

      //Lancement de la partie
      p.jouer();

      cout << "\n********** FIN PARTIE " << i << " **********\n";
   }*/

   //On fait tourner l'ordre des joueurs à chaque tour
   for (unsigned i = 1; i <= NOMBRE_PARTIES; ++i) {
      //On calcul le joueur ayant le nombre de familles le plus petit
      rotate(joueurs.begin(), joueurs.begin() + 1, joueurs.end());

      cout << "********** PARTIE " << i << " **********\n";
      Partie p(joueurs, NOMBRE_FAMILLES, CARTES_PAR_FAMILLE, CARTES_PAR_JOUEURS);

      //Lancement de la partie
      p.jouer();

      cout << "\n********** FIN PARTIE " << i << " **********\n";
   }

   cout << "\nPourcentage de familles posees apres " << NOMBRE_PARTIES << " parties jouees :\n";
   for (const Joueur* j: joueurs) {
      cout << "Le score total de " << j->getPrenom() << " est ~" << round((double)j->getScore() / (NOMBRE_FAMILLES * NOMBRE_PARTIES) * 100.) << "%" << endl;
   }

   supprimerJoueurs(joueurs);

   return EXIT_SUCCESS;
}

