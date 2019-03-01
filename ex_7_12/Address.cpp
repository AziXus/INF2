/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Address.cpp
 Auteur(s)   : Robin Müller
 Date        : 26.02.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Address.h"

Address::Address(const std::string& city, const std::string& npa, const std::string& street,
                 const std::string& streetNumber) : city(city), npa(npa), street(street),
                                                    streetNumber(streetNumber) {
}

std::ostream& operator<<(std::ostream& os, const Address& address) {
    os << address.street << " " << address.streetNumber << ", " << address.npa << " " << address.city;

    return os;
}
