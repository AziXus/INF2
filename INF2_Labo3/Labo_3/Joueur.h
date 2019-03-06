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
   Joueur();
   Joueur(const std::string& prenom);
   void enleverCarteMain(const Carte& carte);
   void ajoutCarteMain(const Carte& carte);
   void ajoutFamille(const Cartes& cartes);
   bool carteEnMain(const Carte& carte);
   Carte demanderCarte();
   Cartes getFamille(const Carte& carte);
   bool detecterFamille(unsigned cartesParFamilles);
   std::string getPrenom() const;
   friend std::ostream& operator<<(std::ostream& os, const Cartes& cartes);
   friend std::ostream& operator<<(std::ostream& os, const Joueur& joueur);

private:
   std::string prenom;
   Cartes cartesMain;
   Cartes cartesFamille;
};

#endif /* JOUEUR_H */

