/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Robin Müller, Stéphane Teixeira Carvalho
 Date        : 15.03.2019

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Joueur.h"
#include <algorithm>

using namespace std;

Joueur::Joueur(const string& prenom) : prenom(prenom) {}

string Joueur::getPrenom() const {
   return prenom;
}

Cartes Joueur::trouverFamille(const Carte& carte) {
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


void Joueur::enleverCarteMain(const Carte& carte) {
   cartesEnMain.erase(remove(cartesEnMain.begin(), cartesEnMain.end(), carte), cartesEnMain.end());
}

void Joueur::ajoutCarteMain(const Carte& carte) {
   cartesEnMain.push_back(carte);
}

void Joueur::ajoutFamille(const Cartes& cartes) {
   for (const Carte& carte : cartes) {
      enleverCarteMain(carte);
      famillesSurTable.push_back(carte);
   }
}

bool Joueur::carteEnMain(const Carte& carte) {
   return find(cartesEnMain.begin(), cartesEnMain.end(), carte) != cartesEnMain.end();
}

Carte Joueur::demanderCarte(const unsigned cartesParFamille) {
   unsigned short numero = cartesEnMain.front().getNumeroFamille();
   char lettre;
   do {
      lettre = (char)(rand() % cartesParFamille + 'A');
   } while (find(cartesEnMain.begin(), cartesEnMain.end(), Carte(numero, lettre)) != cartesEnMain.end());

   return Carte(numero, lettre);
}

bool Joueur::detecterFamille(unsigned cartesParFamilles) {
   Cartes famille;
   famille.reserve(cartesParFamilles);

   for (const Carte& carte : cartesEnMain) {
      famille = trouverFamille(carte);

      if (famille.size() == cartesParFamilles) {
         ajoutFamille(famille);
         ++nbFamilles;
         ++score;
         return true;
      }
   }

   return false;
}

size_t Joueur::nbCartesEnMain() const {
   return cartesEnMain.size();
}

ostream& operator<<(ostream& os, const Joueur& joueur) {
   os << joueur.prenom << " : " << joueur.cartesEnMain << " [" << joueur.famillesSurTable << "]";
   return os;
}

void Joueur::resetCartes() {
   cartesEnMain.clear();
   famillesSurTable.clear();
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

   for (const Carte& carte : getCartesMain()) {
      familleActuel = trouverFamille(carte);

      if (familleActuel.size() >  plusGrandeFamille.size())
         plusGrandeFamille = familleActuel;
   }

   //Generer demande de carte
   char lettre;
   unsigned short numero = plusGrandeFamille.front().getNumeroFamille();
   do {
      lettre = (char)(rand() % cartesParFamille + 'A');
   } while (find(plusGrandeFamille.begin(), plusGrandeFamille.end(), Carte(numero, lettre)) != plusGrandeFamille.end());

   return Carte(numero, lettre);
}

ostream& operator<<(ostream& os, const Cartes& cartes) {
   for (size_t i = 0; i < cartes.size(); ++i) {
      if (i > 0)
         os << " ";
      os << cartes[i];
   }
   return os;
}