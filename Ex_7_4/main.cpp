#include <iostream>

class Robot {
public:
    Robot(int pos = 0);
    void deplacer(int n = 1);
    void faireDemiTour();
    int getPos() const;

private:
    int position;
    bool deplacerDroite;
};

Robot::Robot(int pos) {
    position = pos;
    deplacerDroite = true;
}

void Robot::deplacer(int n) {
    if (deplacerDroite)
        position += n;
    else
        position -= n;
}

void Robot::faireDemiTour() {
    deplacerDroite = !deplacerDroite;
}

int Robot::getPos() const {
    return position;
}

int main() {
    Robot r1;

    r1.deplacer();
    std::cout << r1.getPos() << std::endl;

    r1.deplacer(2);
    std::cout << r1.getPos() << std::endl;

    r1.faireDemiTour();
    r1.deplacer(3);
    std::cout << r1.getPos() << std::endl;

    return EXIT_SUCCESS;
}