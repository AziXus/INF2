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
#ifndef INF2_LABO3_CARTE_H
#define INF2_LABO3_CARTE_H

#include <string>

class Carte {
public:
    std::string toString() const;
private:
    unsigned short numeroFamille;
    char lettreFamille;
};


#endif //INF2_LABO3_CARTE_H
