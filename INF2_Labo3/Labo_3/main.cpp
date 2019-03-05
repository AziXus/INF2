
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
    return 0;
    cout << p1.getJoueurs()[0] << endl;
    cout << p1.getJoueurs()[1] << endl;
    cout << p1.getJoueurs()[2] << endl;

        for (int i = 0; i < p1.getPioche().size(); ++i) {
            if (i > 0)
                cout << " ";
            cout << p1.getPioche()[i];
        }

    return EXIT_SUCCESS;
}

