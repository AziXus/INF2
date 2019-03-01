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
#include <string>
#include <vector>

using carteEnMain = std::vector<Carte>;
using famillesSurTable = std::vector<Carte>;

class Joueur{
public:
   Joueur(const std::string& prenom);
   ajoutCarteMain(Carte)
private:
   std::string prenom;
   carteEnMain carteMain;
   famillesSurTable carteFamille;
};

#endif /* JOUEUR_H */

