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

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "Partie.h"


using namespace std;

using Joueurs = vector<Joueur*>;

Joueurs genererJoueurs(unsigned nbJoueurs) {
   Joueurs joueurs(nbJoueurs);

   //Le premier joueur est le meilleur joueur
   joueurs[0] = new MeilleurJoueur("Joueur0");

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
   const unsigned NB_PARTIES         = 100,
           NB_JOUEURS         =   4,
           NB_FAMILLES        =   9,
           CARTES_PAR_FAMILLE =   4,
           CARTES_PAR_JOUEURS =   5;

   Joueurs joueurs = genererJoueurs(NB_JOUEURS);

   for (unsigned i = 1; i <= NB_PARTIES; ++i) {
      //On change l'ordre des joueurs
      //Améliorer la création des joueurs

      cout << "********** PARTIE " << i << " **********\n";
      Partie p(joueurs, NB_FAMILLES, CARTES_PAR_FAMILLE, CARTES_PAR_JOUEURS);

      //Lancement de la partie
      p.jouer();

      cout << "\n********** FIN PARTIE " << i << " **********\n";
   }

   for (const Joueur* j: joueurs) {
      cout << "Le score total de " << j->getPrenom() << " est " << round((double)j->getScore() / NB_FAMILLES / NB_PARTIES * 100.) << "%" << endl;
   }

   supprimerJoueurs(joueurs);

   return EXIT_FAILURE;
}

