/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 But         : Mettre en place une simulation d'une partie du jeux des familles.
               La partie sera suivi grâce à un affchage de chaque tour.
               Le système utilise les classes Joueur, Partie et Carte.           

 Remarque(s) : Les joueurs sont contenus dans un vecteur de joueur.

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <iostream>
#include "Partie.h"


using namespace std;

int main() {
    //Déclaration des joueurs
    Joueur j1 = Joueur("Alice");
    Joueur j2 = Joueur("Booby");
    Joueur j3 = Joueur("Carlos");
    vector<Joueur> v1 = {j1, j2, j3};

    Partie p1(v1, 7, 5, 5);
    //Lancement de la partie
    p1.demarrer();
    

    return EXIT_SUCCESS;
}

