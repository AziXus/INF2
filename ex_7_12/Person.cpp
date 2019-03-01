/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Person.cpp
 Auteur(s)   : Robin Müller
 Date        : 26.02.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Person.h"
#include <algorithm>

using namespace std;

Person::Person(const std::string& name, const std::string& surname, const Address& address) : name(
        name), surname(surname), address(address) {}

void Person::addHobby(const Hobby& hobby) {
    hobbies.push_back(hobby);
}

void Person::addHobbies(const Hobbies& hobbies) {
    this->hobbies.insert(this->hobbies.end(), hobbies.begin(), hobbies.end());
}

void Person::addFriend(Person* newFriend) {
    friends.push_back(newFriend);
    newFriend->friends.push_back(this);
}

void Person::addFriends(const Friends& friends) {
    for (Person* f : friends) {
        addFriend(f);
    }
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name   : " << person.name           << "\n"
       << "Surname: " << person.surname        << "\n"
       << "Address: " << person.address        << "\n"
       << "Hobbies: " << person.hobbies.size() << "\n"
       << "Friends: " << person.friends.size() << "\n";

    return os;
}
