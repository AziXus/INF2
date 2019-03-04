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
#include "Joueur.h"

using namespace std;

Joueur::Joueur(const string& prenom):prenom(prenom){}
string Joueur::getPrenom() const
{
    return prenom;
}
void Joueur::ajoutCarteMain(const Carte& carte)
{
    carteMain.push_back(carte);
}

void Joueur::ajoutFamille(const Cartes& carte)
{
   
}

ostream& operator<<(ostream& os, const Cartes& cartes) {
   for (int i = 0; i < cartes.size(); ++i) {
      if (i > 0)
         os << " ";
      os << cartes[i];
   }

   return os;
}

ostream& operator<<(ostream& os, const Joueur& joueur) {
   os << joueur.prenom << " : " << joueur.carteMain << " [" << joueur.carteFamille << "]";
   return os;
}
