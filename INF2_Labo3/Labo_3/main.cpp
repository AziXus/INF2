
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    Joueur j1 = Joueur("Alice");
    Joueur j2 = Joueur("Booby");
    Joueur j3 = Joueur("Carlos");
    
    Partie p1({j1,j2,j3}, 7, 5, 3);
    
    cout << j1 << endl;
    cout << j2 << endl;
    cout << j3 << endl;
    

    return EXIT_SUCCESS;
}

