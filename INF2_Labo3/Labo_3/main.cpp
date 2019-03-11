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
#include "Partie.h"


using namespace std;

int main() {
    const unsigned NB_PARTIES         = 100,
                   NB_FAMILLES        =   9,
                   CARTES_PAR_FAMILLE =   4,
                   CARTES_PAR_JOUEURS =   5;

    //Déclaration des joueurs
    Joueur alice("Alice");
    unsigned scoreAlice = 0;

    Joueur bobby("Bobby");
    unsigned scoreBobby = 0;

    Joueur carlos("Carlos");
    unsigned scoreCarlos = 0;

    Joueur danny("Danny");
    unsigned scoreDanny = 0;

    vector<Joueur> joueurs = {alice, bobby, carlos, danny};

    for (unsigned i = 1; i <= NB_PARTIES; ++i) {
        //On change l'ordre des joueurs
        //Améliorer la création des joueurs

        cout << "********** PARTIE " << i << " **********\n";
        Partie p1(joueurs, NB_FAMILLES, CARTES_PAR_FAMILLE, CARTES_PAR_JOUEURS);

        //Lancement de la partie
        p1.jouer();

        scoreAlice  += p1.scoreJoueur(alice);
        scoreBobby  += p1.scoreJoueur(bobby);
        scoreCarlos += p1.scoreJoueur(carlos);
        scoreDanny  += p1.scoreJoueur(danny);

        cout << "\n********** FIN PARTIE " << i << " **********\n";
    }

    cout << "Le score total d'Alice est   " << round((double)scoreAlice  / NB_FAMILLES) << "%" << endl;
    cout << "Le score total de Bobby est  " << round((double)scoreBobby  / NB_FAMILLES) << "%" << endl;
    cout << "Le score total de Carlos est " << round((double)scoreCarlos / NB_FAMILLES) << "%" << endl;
    cout << "Le score total de Danny est  " << round((double)scoreDanny  / NB_FAMILLES) << "%" << endl;

    return EXIT_SUCCESS;
}

