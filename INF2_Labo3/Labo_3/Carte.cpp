/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Carte.cpp
 Auteur(s)   : Robin Müller
 Date        : 01.03.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Carte.h"

using namespace std;

std::string Carte::toString() const {
    return to_string(numeroFamille) + lettreFamille;
}
