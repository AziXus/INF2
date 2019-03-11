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

#include <vector>
#include <iostream>

class Func {
public:
    virtual void call() {
        std::cout<< "Func -> call()" << std::endl;
    }
};

class Foo : public Func {
public:
    void call() {
        std::cout<< "Foo -> call()" << std::endl;
    }
};

class Bar : public Func {
public:
    void call() {
        std::cout<< "Bar -> call()" << std::endl;
    }
};

int main() {
    std::vector<Func*> functors;

    Func func = Func();
    Foo foo = Foo();
    Bar bar = Bar();

    functors.push_back( &func );
    functors.push_back( &foo );
    functors.push_back( &bar );

    std::vector<Func*>::iterator iter;
    for (iter = functors.begin(); iter != functors.end(); ++iter)
        (*iter)->call();

    return 0;
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