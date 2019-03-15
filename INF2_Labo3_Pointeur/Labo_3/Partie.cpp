
/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "Partie.h"
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

Partie::Partie(Joueurs& joueurs, unsigned short nbFamille, unsigned short carteParFamille, unsigned short carteParJoueur)
:NOMBRE_FAMILLES(nbFamille), CARTES_PAR_FAMILLES(carteParFamille), CARTES_PAR_JOUEURS(carteParJoueur), joueurs(joueurs) {
   unsigned carteTotal = NOMBRE_FAMILLES * CARTES_PAR_FAMILLES;
   unsigned carteDistribuer = CARTES_PAR_JOUEURS * (unsigned)joueurs.size();
   //Si le nombre de carte a distribuer est plus grand que le nombre de cartes totales on retourne une erreur
   if (carteDistribuer > carteTotal)
      cout << "ERREUR!" << endl;
   else {
      //On nettoye les cartes des joueurs avant chaque partie
      for (Joueur* j: joueurs)
         j->resetCartes();

      //les cartes générées vont d'abord toutes dans la pioche puis elles sont mélangées et ensuite distribuer
      pioche = genererCartes();
      melangerPioche();
      distribuerCartes();
   }
}

void Partie::afficherJoueurs() const {
   for (const Joueur* joueur : joueurs) {
      cout << *joueur << endl;
   }
}

void Partie::jouer() {
   cout << "Debut de la partie de " << NOMBRE_FAMILLES << " familles\n";

   //En début de partie, on regarde si des familles sont déjà dans les mains des joueurs et on les déposent
   for (Joueur* j: joueurs)
      while (j->detecterFamille(CARTES_PAR_FAMILLES));

   while (!estTerminee()) {
      cout << "*** Tour " << ++numeroTour << " ***\n";
      //Affichage des joueurs
      afficherJoueurs();
      //Affichage de la pioche
      cout << "Pioche : " << pioche << endl;
      jouerTour();
   }

   cout << "\nLa partie est finie !" << endl;
   afficherJoueurs();
   cout << "Pioche : " << pioche << endl;
   cout << "Nombre de tours : " << numeroTour << endl;
}

bool Partie::estTerminee() {
   if (!pioche.empty())
      return false;

   //Vérifie qu'aucun des joueurs n'ai de cartes en main
   for (const Joueur* j: joueurs) {
      if (j->nbCartesEnMain() != 0)
         return false;
   }

   //La partie est terminée si la pioche est vide et plus personne n'a de cartes en main
   return true;
}

void Partie::jouerTour() {
   //Pour chaque joueur dans la partie, on joue son tour s'il a encore des cartes en main
   for (Joueur* joueur : joueurs) {
      //S'il reste encore un autre joueur en jeu et qu'on a des cartes, on echange des cartes
      if (joueur->nbCartesEnMain() != 0 and nbJoueursEnJeu() >= 2) {
         Joueur& cible = choisirCible(*joueur);
         echangerCartes(*joueur, cible);
      }

      //En fin de tour un joueur pioche une carte.
      if (!pioche.empty()) {
         //Si le joueur pioche une carte et dépose une famille mais qu'il vide sa main, il peut piocher une seconde carte
         do {
            piocher(*joueur);
         } while (joueur->detecterFamille(CARTES_PAR_FAMILLES) and joueur->nbCartesEnMain() == 0);
      }
   }
}

Cartes Partie::genererCartes() {
   Cartes paquets;
   for (unsigned numero = 1; numero <= NOMBRE_FAMILLES; numero++)
      for (char lettre = 'A'; lettre < 'A' + CARTES_PAR_FAMILLES; lettre++)
         //création des cartes et ajout de celle-ci dans un vecteur de carte
         paquets.push_back(Carte((unsigned short)numero, lettre));
   return paquets;
}

void Partie::distribuerCartes() {
   //Ditribue le nombre de carte au différent joueur depuis la pioche
   for (unsigned i = 1; i <= CARTES_PAR_JOUEURS; i++)
      for (Joueur* joueur : joueurs) {
         joueur->ajoutCarteMain(pioche.back());
         pioche.pop_back();
      }
}

void Partie::echangerCartes(Joueur& joueur, Joueur& cible) {
   bool demanderCarte = true;

   //Demander des cartes tant que le joueur et la cible en possèdent et que la cible possède la carte demandée
   while (demanderCarte and joueur.nbCartesEnMain() != 0 and cible.nbCartesEnMain() != 0) {
      Carte carte = joueur.demanderCarte(CARTES_PAR_FAMILLES);
      cout << joueur.getPrenom() << " demande a " << cible.getPrenom() << " la carte " << carte << endl;

      //Si la cible possède la carte
      if (cible.carteEnMain(carte)) {
         cible.enleverCarteMain(carte);
         joueur.ajoutCarteMain(carte);
         cout << "\tet " << cible.getPrenom() << " donne la carte a " << joueur.getPrenom() << endl;
      } else {
         cout << "\tmais " << cible.getPrenom() << " ne l'a pas\n";
         demanderCarte = !demanderCarte;
      }

      joueur.detecterFamille(CARTES_PAR_FAMILLES);
   }
}

void Partie::piocher(Joueur& joueur) {
   //Si la pioche n'est pas vide, on ajoute la dernière carte de la pioche au joueur puis on la supprime de la pioche
   if (!pioche.empty()) {
      joueur.ajoutCarteMain(pioche.back());
      cout << joueur.getPrenom() << " prend une carte dans la pioche (" << pioche.back() << ")\n";
      pioche.pop_back();
   }
}

void Partie::melangerPioche() {
   //On initialise la seed du random au temps actuel lors du premier appel
   static bool premierAppel = true;
   if (premierAppel) {
      premierAppel = false;
      srand((unsigned)time(NULL));
   }
   random_shuffle(pioche.begin(), pioche.end());
}

Joueur& Partie::choisirCible(Joueur& joueur) {
   //On choisit aléatoirement une cible(joueur) différente
   //On reste dans la boucle si la cible est le joueur lui-même ou que la cible n'a plus de cartes

   //Si on aucun joueur n'a de carte ou que l'on est le seul joueur en jeu avec des cartes, on retourne le joueur lui-même
   if ((nbJoueursEnJeu() == 0) or (nbJoueursEnJeu() == 1 and joueur.nbCartesEnMain() > 0))
      return joueur;

   size_t pos;
   do {
      pos = rand() % joueurs.size();
   } while (&joueur == joueurs.at(pos) or joueurs.at(pos)->nbCartesEnMain() == 0);

   return *joueurs.at(pos);
}


unsigned Partie::nbJoueursEnJeu() {
   //Calcul le nombre de joueurs avec des cartes en main
   return (unsigned)count_if(joueurs.begin(), joueurs.end(), [](const Joueur* j) { return j->nbCartesEnMain() > 0; });
}
