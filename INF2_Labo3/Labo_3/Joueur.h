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

#ifndef JOUEUR_H
#define JOUEUR_H
#include "Carte.h"
#include <string>
#include <vector>
#include <ostream>

using Cartes = std::vector<Carte>;

class Joueur{
public:
   Joueur(const std::string& prenom);
   void ajoutCarteMain(Carte& carte);
   void ajoutFamille(const Cartes& cartes);
   Carte demanderCarte();
   Cartes detecterFamille();

   friend std::ostream& operator<<(std::ostream& os, const Joueur& joueur);

private:
   std::string prenom;
   Cartes carteMain;
   Cartes carteFamille;
};

#endif /* JOUEUR_H */

