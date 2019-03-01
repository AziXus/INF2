#ifndef C_H
#define C_H

#include <iostream>

class C {
public:
    friend std::ostream& operator<<(std::ostream& lhs, const C& rhs);
    friend bool operator==(const C& lhs, const C& rhs);
    friend bool operator!=(const C& lhs, const C& rhs);

    C(int n = 0);
    C& operator++();
    C operator++(int);
    C& operator+=(const C& rhs);
    friend C operator+(C lhs, const C& rhs);

private:
    int n;
};

#endif //C_H