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

#include "Country.h"

using namespace std;

Country::Country(const string& nom, unsigned inhabitants, unsigned surfaceArea) {
    this->nom = nom;
    this->inhabitants = inhabitants;
    this->surfaceArea = surfaceArea;
}

string Country::getName() const {
    return nom;
}

unsigned Country::getInhabitants() const {
    return inhabitants;
}

unsigned Country::getSurfaceArea() const {
    return surfaceArea;
}

float Country::getPopulationDensity() const {
    return (float)inhabitants / surfaceArea;

}

std::ostream &Country::operator<<(std::ostream &os) {
    os << getName()        << ", " << getSurfaceArea() << ", "
       << getInhabitants() << ", " << getPopulationDensity() << endl;

    return os;
}
