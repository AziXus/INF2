
#include <cstdlib>
#include <iostream>
#include "Partie.h"


using namespace std;

int main() {
    Joueur j1 = Joueur("Alice");
    Joueur j2 = Joueur("Booby");
    Joueur j3 = Joueur("Carlos");
    vector<Joueur> v = {j1,j2,j3};
    
    Partie p1(v, 7, 5, 3);
    
    cout << p1.joueurs << endl;
    cout << v.at(1) << endl;
    cout << v.at(2) << endl;
    

    return EXIT_SUCCESS;
}

