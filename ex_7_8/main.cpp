#include <iostream>

using namespace std;

class Objet {
public:
    Objet() {
        n = nextN;
        ++counter;
        ++nextN;
    }

    ~Objet() {
        --counter;
    }

    unsigned no() {
        return n;
    }

    static unsigned prochainNo() {
        return nextN;
    }

    static unsigned compteur() {
        return counter;
    }

private:
    static unsigned nextN;
    static unsigned counter;
    unsigned n;
};


unsigned Objet::nextN   = 1;
unsigned Objet::counter = 0;

int main() {
    Objet obj1;
    Objet obj2;
    Objet obj3;
    Objet obj4;
    Objet obj5;

    cout << obj1.no() << endl;
    cout << obj2.no() << endl;
    cout << obj3.no() << endl;
    cout << obj4.no() << endl;
    cout << obj5.no() << endl;

    cout << "Count : " << Objet::compteur() << endl;
    cout << "Next n : " << Objet::prochainNo() << endl;

    obj2.~Objet();
    obj1.~Objet();
    obj4.~Objet();

    cout << "Count : " << Objet::compteur() << endl;
    cout << "Next n : " << Objet::prochainNo() << endl;
}