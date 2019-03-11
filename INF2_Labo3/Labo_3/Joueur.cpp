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
#include <algorithm>

using namespace std;

Joueur::Joueur(const string& prenom):prenom(prenom){}

string Joueur::getPrenom() const {
   return prenom;
}

Cartes Joueur::getFamille(const Carte& carte) {
   Cartes famille;

   for (const Carte& c : cartesMain) {
      if (c.getNumeroFamille() == carte.getNumeroFamille()) {
         famille.push_back(c);
      }
   }

   return famille;
}

void Joueur::enleverCarteMain(const Carte& carte) {
   cartesMain.erase(remove(cartesMain.begin(), cartesMain.end(), carte), cartesMain.end());
}

void Joueur::ajoutCarteMain(const Carte& carte) {
   cartesMain.push_back(carte);
}

void Joueur::ajoutFamille(const Cartes& cartes)
{
    for(const Carte& carte : cartes)
    {
        enleverCarteMain(carte);
        cartesFamille.push_back(carte);
    }
}

bool Joueur::carteEnMain(const Carte& carte) {
   return find(cartesMain.begin(), cartesMain.end(), carte) != cartesMain.end();
}

Carte Joueur::demanderCarte(const unsigned cartesParFamille)
{
    Carte carteADemander(cartesMain.at(0).getNumeroFamille(), (char)(rand()%(cartesParFamille + 1) + 'A'));
    do{
        carteADemander = Carte(cartesMain.at(0).getNumeroFamille(), (char)((rand()%(cartesParFamille) + 1) + 'A'));
    }while(find(cartesMain.begin(),cartesMain.end(),carteADemander) != cartesMain.end());
    return carteADemander;
}

bool Joueur::detecterFamille(unsigned cartesParFamilles) {
   Cartes famille;
   famille.reserve(cartesParFamilles);

   for (const Carte& carte : cartesMain) {
      famille = getFamille(carte);
      //Fonctionne pas : no match for ‘operator==’ (operand types are ‘Carte’ and ‘const unsigned int’)
      if (famille.size() == cartesParFamilles) {
         ajoutFamille(famille);
         return true;
      }
   }

   return false;
}

unsigned Joueur::nbCarteEnMain()
{
    return cartesMain.size();
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
   os << joueur.prenom << " : " << joueur.cartesMain << " [" << joueur.cartesFamille << "]";
   return os;
}
