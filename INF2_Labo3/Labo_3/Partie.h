
#ifndef PARTIE_H
#define PARTIE_H
#include <vector>

#include "Joueur.h"
#include "Carte.h"

using Joueurs = std::vector<Joueur>;
using Cartes = std::vector<Carte>;

class Partie{
public:
   Partie(Joueurs joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur);
   
private:
   Cartes genererCartes();
   void distribuerCartes();
   void melangerCartes();
   const unsigned short NOMBRE_FAMILLES;
   const unsigned short CARTES_PAR_FAMILLES;
   const unsigned short NOMBRE_JOUEURS;
   const unsigned short CARTES_PAR_JOUEURS;
   const Joueurs JOUEURS;
   Cartes pioche;
};


#endif /* PARTIE_H */

