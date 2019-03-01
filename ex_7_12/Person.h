#ifndef EX_7_12_PERSON_H
#define EX_7_12_PERSON_H

#include <string>
#include <vector>
#include <ostream>
#include "Address.h"

class Person;

enum class Hobby {
    SPORT,
    MUSIQUE,
    CINEMA,
    LECTURE
};

using Hobbies = std::vector<Hobby>;
using Friends = std::vector<Person*>;

class Person {
public:
    Person(const std::string& name, const std::string& surname, const Address& address);

    void addHobby(const Hobby& hobby);
    void addHobbies(const Hobbies& hobbies);

    void addFriend(Person* newFriend);
    void addFriends(const Friends& friends);

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string name;
    std::string surname;
    Address address;
    Hobbies hobbies;
    Friends friends;
};


#endif //EX_7_12_PERSON_H
