
#ifndef PARTIE_H
#define PARTIE_H
#include <vector>

#include "Joueur.h"
#include "Carte.h"

using Joueurs = std::vector<Joueur>;
using Cartes = std::vector<Carte>;

class Partie{
public:
   Partie(Joueurs& joueurs, unsigned nbFamille, unsigned carteParFamille, unsigned carteParJoueur);

   const Cartes& getPioche() const;

   const Joueurs& getJoueurs() const;

   void jouerTour();

private:
   Cartes genererCartes();
   void distribuerCartes();
   void tourJoueur();
   void piocher(Joueur& joueur);
   void poserFamille(Joueur& joueur, const Cartes& famille);
   void melangerCartes();
   const unsigned short NOMBRE_FAMILLES;
   const unsigned short CARTES_PAR_FAMILLES;
   const unsigned short CARTES_PAR_JOUEURS;
   Joueurs joueurs;
   Cartes pioche;
};


#endif /* PARTIE_H */

