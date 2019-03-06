
/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#include "Partie.h"
#include <ctime>
#include <vector>
#include <algorithm>

//Remove
#include <iostream>

using namespace std;

Partie::Partie(Joueurs& joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur)
:joueurs(joueurs), NOMBRE_FAMILLES(nbFamille), CARTES_PAR_FAMILLES(carteParFamille), CARTES_PAR_JOUEURS(carteParJoueur)
{
   //Si le nombre de carte a distribuer est plus grand que le nombre de cartes totales
   if (CARTES_PAR_JOUEURS * joueurs.size() > NOMBRE_FAMILLES * CARTES_PAR_FAMILLES)
      std::cout << "ERREUR!" << endl;
   else {
      pioche = genererCartes();
      melangerCartes();
      distribuerCartes();
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

void Partie::jouerTour() {
   //Pour chaque joueur, on doit choisir un joueur (une cible), demander une carte tant qu'il en a une, et finir par piocher une carte.
   for (Joueur& joueur : joueurs) {
      tourJoueur(joueur);
   }
}

void Partie::tourJoueur(Joueur& joueur) {
   Joueur cible = choisirCible(joueur);

   bool demanderCarte = true;
   do {
      Carte carte = joueur.demanderCarte();

      cout << joueur.getPrenom() << " demande à " << cible.getPrenom() << " la carte " << carte << endl;

      //Si la cible possède la carte
      if (cible.carteEnMain(carte)) {
         cout << "\tet " << cible.getPrenom() << " donne la carte à " << joueur.getPrenom() << endl;
         cible.enleverCarteMain(carte);
         joueur.ajoutCarteMain(carte);
      } else {
         cout << "\tmais " << cible.getPrenom() << " ne l'a pas\n";
         piocher(joueur);
         demanderCarte = !demanderCarte;
      }

      joueur.detecterFamille(CARTES_PAR_FAMILLES);
   } while (demanderCarte);
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

void Partie::distribuerCartes()
{
    for(unsigned i = 1; i <= CARTES_PAR_JOUEURS; i++)
        for(unsigned j = 0; j < joueurs.size(); j++)
            piocher(joueurs.at(j));
}

const Joueurs& Partie::getJoueurs() const {
   return joueurs;
}

const Cartes& Partie::getPioche() const {
   return pioche;
}

void Partie::demarrer() {
   cout << "Début de la partie\n";
   for (int i = 1; i <= 100; ++i) {
      cout << "*** Tour " << i << " ***\n";
      jouerTour();
   }
}

Joueur& Partie::choisirCible(const Joueur& joueur) {
   //On choisit aléatoirement une cible différente de joueur
   size_t pos;
   do {
      pos = rand() % joueurs.size();
   } while (joueur.getPrenom() == joueurs.at(pos).getPrenom());

   return joueurs.at(pos);
}
