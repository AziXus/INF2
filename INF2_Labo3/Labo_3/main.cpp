
#include <cstdlib>
#include <iostream>
#include "Partie.h"


using namespace std;

int main() {
    Joueur j1 = Joueur("Alice");
    Joueur j2 = Joueur("Booby");
    Joueur j3 = Joueur("Carlos");
    vector<Joueur> v1 = {j1, j2, j3};

    Partie p1(v1, 7, 5, 5);

    p1.demarrer();
    

    return EXIT_SUCCESS;
}

