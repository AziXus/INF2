#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


template<typename T>
string getArray(T tab[], size_t size) {
    stringstream s;

    s << "[";
    for (size_t i = 0 ; i < size; ++i) {
        if (i > 0)
            s << ", ";
        s << tab[i];
    }
    s << "]";
    return s.str();
}

template<typename T>
void insertAt(T tab[], size_t& size, size_t capacity, T val, size_t pos = 0) {
    if (size == capacity)
        throw runtime_error("size == capacity");

    if (size > capacity)
        throw invalid_argument("size > capacity");

    if (pos > size) {
        throw invalid_argument("pos > size");
    }


    for (size_t i = size; i > pos; --i) {
        tab[i] = tab[i - 1];
    }

    tab[pos] = val;
    ++size;
}

int main() {
    const size_t CAPACITE = 10;
    size_t taille = 3;

    int tab[CAPACITE] = {1, 2, 3};

    insertAt(tab, taille, CAPACITE, 0, 9);

    cout << getArray(tab, taille);
    return EXIT_SUCCESS;
}