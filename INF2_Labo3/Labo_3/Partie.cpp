
#include <vector>

#include "Partie.h"

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
#include <algorithm>

using namespace std;

Partie::Partie(Joueurs joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur)
:JOUEURS(joueurs), NOMBRE_FAMILLES(nbFamille), CARTES_PAR_FAMILLES(carteParFamille), CARTES_PAR_JOUEURS(carteParJoueur)
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

void Partie::melangerCartes()
{
    random_shuffle(pioche.begin(),pioche.end());
}

void Partie::distribuerCartes()
{
    for(unsigned i = 1; i <= CARTES_PAR_JOUEURS; i++)
        for(unsigned j = 1; j <= NOMBRE_JOUEURS; j++)
            JOUEURS.at(j).ajoutCarteMain(piocher(joueurs.at(i)));
}
