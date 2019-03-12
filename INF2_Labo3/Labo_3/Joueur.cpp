/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

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

   for (const Carte& c : cartesEnMain) {
      if (c.getNumeroFamille() == carte.getNumeroFamille()) {
         famille.push_back(c);
      }
   }

   return famille;
}

const Cartes& Joueur::getCartesMain() const {
   return cartesEnMain;
}

unsigned Joueur::getNbFamilles() const {
   return nbFamilles;
}

void Joueur::enleverCarteMain(const Carte& carte) {
   cartesEnMain.erase(remove(cartesEnMain.begin(), cartesEnMain.end(), carte), cartesEnMain.end());
}

void Joueur::ajoutCarteMain(const Carte& carte) {
   cartesEnMain.push_back(carte);
}

void Joueur::ajoutFamille(const Cartes& cartes)
{
    for(const Carte& carte : cartes)
    {
        enleverCarteMain(carte);
        famillesSurTable.push_back(carte);
    }
}

bool Joueur::carteEnMain(const Carte& carte) {
   return find(cartesEnMain.begin(), cartesEnMain.end(), carte) != cartesEnMain.end();
}

Carte Joueur::demanderCarte(const unsigned cartesParFamille)
{
    Carte carteADemander(cartesEnMain.at(0).getNumeroFamille(), (char)(rand()%cartesParFamille + 'A'));
    do{
        carteADemander = Carte(cartesEnMain.at(0).getNumeroFamille(), (char)(rand()%cartesParFamille + 'A'));
    }while(find(cartesEnMain.begin(),cartesEnMain.end(),carteADemander) != cartesEnMain.end());
    return carteADemander;
}

bool Joueur::deposerFamille(unsigned cartesParFamilles) {
   Cartes famille;
   famille.reserve(cartesParFamilles);

   for (const Carte& carte : cartesEnMain) {
      famille = getFamille(carte);

      if (famille.size() == cartesParFamilles) {
         ajoutFamille(famille);
         ++nbFamilles;
         return true;
      }
   }

   return false;
}

short unsigned Joueur::nbCarteEnMain() const
{
    return cartesEnMain.size();
}

ostream& operator<<(ostream& os, const Cartes& cartes) {
   for (size_t i = 0; i < cartes.size(); ++i) {
      if (i > 0)
         os << " ";
      os << cartes[i];
   }
   return os;
}

ostream& operator<<(ostream& os, const Joueur& joueur) {
   os << joueur.prenom << " : " << joueur.cartesEnMain << " [" << joueur.famillesSurTable << "]";
   return os;
}

bool Joueur::operator==(const Joueur& rhs) const {
   return prenom == rhs.prenom;
}
