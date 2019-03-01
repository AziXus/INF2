#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Country.h"

using namespace std;

bool compareSurfaceArea(const Country& p1, const Country& p2) {
    return p1.getSurfaceArea() < p2.getSurfaceArea();
}

bool compareInhabitants(const Country& p1, const Country& p2) {
    return p1.getInhabitants() < p2.getInhabitants();
}

bool comparePopulationDensity(const Country& p1, const Country& p2) {
    return p1.getPopulationDensity() < p2.getPopulationDensity();
}

int main() {
    vector<Country> country = {
            {"France",  65480710,   547557},
            {"Italy",   59216525,   294140},
            {"Belgium", 11562784,    30280},
            {"Germany", 82438639,   348560},
            {"Russia", 143895551, 16376870}
    };

    Country maxSurface = *max_element(country.begin(), country.end(), compareSurfaceArea);
    Country maxInhabitants = *max_element(country.begin(), country.end(), compareInhabitants);
    Country maxPopulationDensity = *max_element(country.begin(), country.end(), comparePopulationDensity);

    cout << fixed << setprecision(2);
    cout << "Pays avec la plus grande surface : " << maxSurface;

    cout << maxInhabitants.getName()        << ", " << maxInhabitants.getSurfaceArea()       << ", "
         << maxInhabitants.getInhabitants() << ", " << maxInhabitants.getPopulationDensity() << endl;

    cout << maxPopulationDensity.getName()  << ", " << maxPopulationDensity.getSurfaceArea() << ", "
         << maxPopulationDensity.getInhabitants()   << ", " << maxPopulationDensity.getPopulationDensity() << endl;

    return EXIT_SUCCESS;
}