
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

#include <vector>
#include <algorithm>

using namespace std;

Partie::Partie(Joueurs joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur)
:joueurs(joueurs), NOMBRE_FAMILLES(nbFamille), CARTES_PAR_FAMILLES(carteParFamille), CARTES_PAR_JOUEURS(carteParJoueur)
{
    pioche = genererCartes();
    melangerCartes();
    distribuerCartes();
}

Cartes Partie::genererCartes()
{
    Cartes paquets;
    for(char lettre = 'A'; lettre <= NOMBRE_FAMILLES; lettre++)
        for(size_t numero = 1; numero <= CARTES_PAR_FAMILLES; numero++)
            paquets.push_back(Carte(lettre, numero));
    return paquets;
}

void Partie::jouerTour() {
   //Pour chaque joueur, on doit choisir un joueur (une cible), demander une carte tant qu'il en a une, et finir par piocher une carte.
   for (Joueur& joueur : joueurs) {

   }
}

void Partie::tourJoueur() {

}

void Partie::piocher(Joueur& joueur) {
   joueur.ajoutCarteMain(pioche.back());
   pioche.pop_back();
}

void Partie::poserFamille(Joueur& joueur, const Cartes& famille) {
   joueur.ajoutFamille(famille);
}

void Partie::melangerCartes()
{
    random_shuffle(pioche.begin(),pioche.end());
}

void Partie::distribuerCartes()
{
    for(unsigned i = 1; i <= CARTES_PAR_JOUEURS; i++)
        for(unsigned j = 0; j < joueurs.size(); j++)
            piocher(joueurs.at(j));
}
