
/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#include "Partie.h"
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

Partie::Partie(Joueurs& joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur)
:joueurs(joueurs), NOMBRE_FAMILLES(nbFamille), CARTES_PAR_FAMILLES(carteParFamille), CARTES_PAR_JOUEURS(carteParJoueur)
{
    unsigned carteTotal = NOMBRE_FAMILLES * CARTES_PAR_FAMILLES;
    unsigned carteDistribuer = CARTES_PAR_JOUEURS * joueurs.size();
   //Si le nombre de carte a distribuer est plus grand que le nombre de cartes totales on retourne une erreur
   if (carteDistribuer > carteTotal)
      cout << "ERREUR!" << endl;
   else {
      pioche = genererCartes();
      melangerCartes();
      distribuerCartes();
   }
}

const Cartes& Partie::getPioche() const {
   return pioche;
}

void Partie::afficherPioche() const
{
    for (int i = 0; i < getPioche().size(); ++i) {
        if (i > 0)
        cout << " ";
        cout << getPioche()[i];
    }
}

const Joueurs& Partie::getJoueurs() const {
   return joueurs;
}

void Partie::afficherJoueur() const
{
    for (int i = 0; i < getJoueurs().size(); ++i) {
        cout << getJoueurs()[i] << endl;
    }
}

void Partie::demarrer() {
   cout << "Debut de la partie\n";
   for (int i = 1; i <= 100; ++i) {
      cout << "*** Tour " << i << " ***\n";
      //Affichage des joueurs
      afficherJoueur();
      //Affichage de la pioche
      afficherPioche();
      cout << endl;
      jouerTour();
   }
}

void Partie::jouerTour() {
   //Pour chaque joueur, on doit choisir un joueur (une cible), demander une carte tant qu'il en a une, et finir par piocher une carte.
   for (Joueur& joueur : joueurs) {
      if(joueur.nbCarteEnMain() != 0)
        tourJoueur(joueur);
   }
}

Cartes Partie::genererCartes()
{
    Cartes paquets;
    for(size_t numero = 1; numero <= NOMBRE_FAMILLES; numero++)
      for(char lettre = 'A'; lettre < 'A' + CARTES_PAR_FAMILLES; lettre++)
            paquets.push_back(Carte(numero, lettre));
    return paquets;
}

void Partie::distribuerCartes()
{
    for(unsigned i = 1; i <= CARTES_PAR_JOUEURS; i++)
        for(unsigned j = 0; j < joueurs.size(); j++)
            piocher(joueurs.at(j));
}

void Partie::tourJoueur(Joueur& joueur) {
   Joueur& cible = choisirCible(joueur);

   bool demanderCarte = true;
   do {
      Carte carte = joueur.demanderCarte(CARTES_PAR_FAMILLES);

      cout << joueur.getPrenom() << " demande a " << cible.getPrenom() << " la carte " << carte << endl;

      //Si la cible possède la carte
      if (cible.carteEnMain(carte)) {
         cout << "\tet " << cible.getPrenom() << " donne la carte a " << joueur.getPrenom() << endl;
         cible.enleverCarteMain(carte);
         joueur.ajoutCarteMain(carte);
      } else {
         cout << "\tmais " << cible.getPrenom() << " ne l'a pas\n";
         piocher(joueur);
         demanderCarte = !demanderCarte;
      }
      joueur.detecterFamille(CARTES_PAR_FAMILLES);
      //if(carteMain.size() == 0) 
   } while (demanderCarte && joueur.nbCarteEnMain() != 0);
}

void Partie::piocher(Joueur& joueur) {
   if (pioche.size() > 0) {
      joueur.ajoutCarteMain(pioche.back());
      pioche.pop_back();
   }
}

void Partie::poserFamille(Joueur& joueur, const Cartes& famille) {
   joueur.ajoutFamille(famille);
}

void Partie::melangerCartes()
{
    static bool premierAppel = true;
    if(premierAppel)
    {
        premierAppel = false;
        srand(time(NULL));
    }
    random_shuffle(pioche.begin(),pioche.end());
}

Joueur& Partie::choisirCible(const Joueur& joueur) {
   //On choisit aléatoirement une cible différente de joueur
   size_t pos;
   do {
      pos = rand() % joueurs.size();
   } while (joueur.getPrenom() == joueurs.at(pos).getPrenom() && joueurs.at(pos).nbCarteEnMain() == 0);

   return joueurs.at(pos);
}
