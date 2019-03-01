#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    Person pA = Person("A", "A", Address("A", "A", "A", "A"));
    Person pB = Person("B", "B", Address("B", "B", "B", "B"));
    Person pC = Person("C", "C", Address("C", "C", "C", "C"));
    Person pD = Person("D", "D", Address("D", "D", "D", "D"));

    pA.addHobby(Hobby::CINEMA);
    pA.addHobbies(Hobbies{Hobby::LECTURE, Hobby::SPORT});

    pA.addFriend(&pB);
    pA.addFriends(Friends{&pC, &pD});
    pC.addFriend(&pB);
    cout << pA << endl;
    cout << pB << endl;
    cout << pC << endl;
    cout << pD << endl;

    return 0;
}