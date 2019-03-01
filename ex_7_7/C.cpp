#include "C.h"

using namespace std;

C::C(int n) : n(n) {

}

ostream& operator<<(ostream& lhs, const C& rhs) {
    lhs << "n = " << rhs.n;
    return lhs;
}

bool operator==(const C& lhs, const C& rhs) {
    return lhs.n == rhs.n;
}

bool operator!=(const C& lhs, const C& rhs) {
    return !(lhs == rhs);
}

C& C::operator++() {
    ++n;
    return *this;
}

C C::operator++(int) {
    C tmp = *this;
    ++(*this);
    return tmp;
}

C& C::operator+=(const C& rhs) {
    n += rhs.n;
    return *this;
}

C operator+(C lhs, const C& rhs) {
    lhs += rhs;
    return lhs;
}
