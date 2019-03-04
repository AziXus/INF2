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
    Carte(char lettreFamille, unsigned numeroFamille);
    std::string toString() const;
private:
    const unsigned short NUMERO_FAMILLE;
    const char LETTRE_FAMILLE;
};


#endif //INF2_LABO3_CARTE_H
