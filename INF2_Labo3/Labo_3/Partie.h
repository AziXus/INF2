
#ifndef PARTIE_H
#define PARTIE_H
#include <vector>
#include "Joueur.h"

using Joueurs = std::vector<Joueur>;
using Cartes = std::vector<Carte>;

class Partie{
public:
   Partie(Joueurs joueurs, unsigned nb_Famille);
   Cartes paquetCarte()
private:
   
};


#endif /* PARTIE_H */

