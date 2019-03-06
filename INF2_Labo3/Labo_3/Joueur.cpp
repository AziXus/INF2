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

Carte Joueur::demanderCarte()
{
    /*Carte carteADemander(cartesMain.at(0).getNumeroFamille(), (char)rand()%('Z' - 'A' + 1) + 'A');
    do{
        carteADemander(cartesMain.at(0).getNumeroFamille(), (char)rand()%('Z' - 'A' + 1) + 'A');
    }while(find(cartesMain.begin(),cartesMain.end(),carteADemander) != cartesMain.end());
    return carteADemander;
     */
    return cartesMain.back();
}

Cartes Joueur::detecterFamille(unsigned cartesParFamilles) {
   Cartes famille;
   famille.reserve(cartesParFamilles);

   for (const Carte& carte : cartesMain) {
      //Fonctionne pas : no match for ‘operator==’ (operand types are ‘Carte’ and ‘const unsigned int’)
      if (count_if(cartesMain.begin(), cartesMain.end(), carte.comparerNumero) == cartesParFamilles) {
         copy_if(cartesMain.begin(), cartesMain.end(), famille.begin(), carte);
         ajoutFamille(famille);
      }
   }

   return famille;
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

bool Joueur::carteEnMain(const Carte& carte) {
   return find(cartesMain.begin(), cartesMain.end(), carte) != cartesMain.end();
}