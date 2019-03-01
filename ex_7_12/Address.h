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
#ifndef EX_7_12_ADDRESS_H
#define EX_7_12_ADDRESS_H

#include <string>
#include <ostream>

class Address {
    friend std::ostream& operator<<(std::ostream& os, const Address& address);
public:
    Address(const std::string& city, const std::string& npa, const std::string& street,
            const std::string& streetNumber);

private:
    std::string city;
    std::string npa;
    std::string street;
    std::string streetNumber;

};


#endif //EX_7_12_ADDRESS_H
