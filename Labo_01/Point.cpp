/*
 -----------------------------------------------------------------------------------
 Labo       : 01
 File       : Point.cpp
 Author(s)  : Robin Müller
 Date       : 26.02.19

 Compiler   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Point.h"
#include <cmath>

Point::Point() : x(0.f), y(0.f) {
}

Point::Point(float x, float y) : x(x), y(y) {
}

void Point::deplacer(float x, float y) {
    this->x += x;
    this->y += y;
}

void Point::rotation(float angle) {
    //Calculate theta and rho initially as those values will change once x or y is set
    float newTheta = theta() + angle;
    float r = rho();

    x = r * cosf(newTheta);
    y = r * sinf(newTheta);
}

float Point::abscisse() const {
    return x;
}

float Point::ordonnee() const {
    return y;
}

Point Point::operator+(const Point& p) const {
    return Point(p.x + x, p.y + y);
}

float Point::rho() const {
    return hypotf(x, y);
}

float Point::theta() const {
    //Get an angle between -PI and PI
    float angle = atan2f(y, x);

    //If angle is negative, add two PI to get an angle between 0 and 2 PI
    if (angle < 0)
        angle += (float)(2 * M_PI);

    return angle;
}