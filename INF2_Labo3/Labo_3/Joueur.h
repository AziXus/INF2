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

class Joueur{
public:
   Joueur(std::string prenom);
   std::string getPrenom() const;
private:
   std::string prenom;
};

#endif /* JOUEUR_H */

