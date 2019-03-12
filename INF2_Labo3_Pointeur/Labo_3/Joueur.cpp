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

   for (const Carte* c : cartesMain) {
      if (c->getNumeroFamille() == carte.getNumeroFamille()) {
         famille.push_back(c);
      }
   }

   return famille;
}

const Cartes& Joueur::getCartesMain() const {
   return cartesMain;
}

unsigned Joueur::getNbFamilles() const {
   return nbFamilles;
}

const Carte* Joueur::enleverCarteMain(const Carte& carte) {
   auto it = find(cartesMain.begin(), cartesMain.end(), carte);
   const Carte* c = *it;

   cartesMain.erase(it);
   return c;
}

void Joueur::ajoutCarteMain(const Carte& carte) {
   cartesMain.push_back(&carte);
}

void Joueur::ajoutFamille(const Cartes& cartes)
{
   for(const Carte* carte : cartes)
   {
      enleverCarteMain(*carte);
      cartesFamille.push_back(carte);
   }
}

bool Joueur::carteEnMain(const Carte& carte) {
   return find(cartesMain.begin(), cartesMain.end(), carte) != cartesMain.end();
}

Carte Joueur::demanderCarte(const unsigned cartesParFamille)
{
   Carte carteADemander(cartesMain.front()->getNumeroFamille(), (char)(rand()%cartesParFamille + 'A'));
   while(find(cartesMain.begin(),cartesMain.end(),carteADemander) != cartesMain.end()) {
       carteADemander = Carte(cartesMain.front()->getNumeroFamille(), (char)(rand()%cartesParFamille + 'A'));
   }
   return carteADemander;
}

bool Joueur::deposerFamille(unsigned cartesParFamilles) {
   Cartes famille;
   famille.reserve(cartesParFamilles);

   for (const Carte* carte : cartesMain) {
      famille = getFamille(*carte);

      if (famille.size() == cartesParFamilles) {
         ajoutFamille(famille);
         ++nbFamilles;
         return true;
      }
   }

   return false;
}

size_t Joueur::nbCarteEnMain() const
{
    return cartesMain.size();
}

ostream& operator<<(ostream& os, const Cartes& cartes) {
   for (size_t i = 0; i < cartes.size(); ++i) {
      if (i > 0)
         os << " ";
      os << *cartes[i];
   }
   return os;
}

ostream& operator<<(ostream& os, const Joueur& joueur) {
   os << joueur.prenom << " : " << joueur.cartesMain << " [" << joueur.cartesFamille << "]";
   return os;
}

bool Joueur::operator==(const Joueur& rhs) const {
   return prenom == rhs.prenom;
}

void Joueur::rendreCarte() {
   cartesMain.clear();
   cartesFamille.clear();
   score += nbFamilles;
   nbFamilles = 0;
}

unsigned int Joueur::getScore() const {
   return score;
}


//Fonctions de la classe MeilleurJoueur

MeilleurJoueur::MeilleurJoueur(const std::string& prenom) : Joueur(prenom) {}

Carte MeilleurJoueur::demanderCarte(const unsigned cartesParFamille) {
   //Compter la famille avec le plus de cartes
   Cartes plusGrandeFamille;
   Cartes familleActuel;

   for (const Carte* carte : getCartesMain()) {
      familleActuel = getFamille(*carte);

      if (familleActuel.size() > plusGrandeFamille.size())
         plusGrandeFamille = familleActuel;
   }

   //Generer demande de carte
   Carte carteADemander(plusGrandeFamille.front()->getNumeroFamille(), (char)(rand()%cartesParFamille + 'A'));
   do{
      carteADemander = Carte(plusGrandeFamille.front()->getNumeroFamille(), (char)(rand()%cartesParFamille + 'A'));
   }while(find(plusGrandeFamille.begin(),plusGrandeFamille.end(),carteADemander) != plusGrandeFamille.end());
   return carteADemander;
}
