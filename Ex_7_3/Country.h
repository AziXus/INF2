/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Country.cpp
 Auteur(s)   : Robin Müller
 Date        : 18.02.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef PAYS_H
#define PAYS_H

#include <string>
#include <iostream>

class Country {
public:
    Country(const std::string& nom, unsigned inhabitants, unsigned surfaceArea);
    std::ostream& operator<<(std::ostream& os);
    std::string getName() const;
    unsigned getInhabitants() const;
    unsigned getSurfaceArea() const;
    float getPopulationDensity() const;

private:
    std::string nom;
    unsigned inhabitants;
    unsigned surfaceArea;
};


#endif //PAYS_H
