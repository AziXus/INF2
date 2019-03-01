/*
 -----------------------------------------------------------------------------------
 Labo       : 01
 File       : Point.h
 Author(s)  : Robin Müller
 Date       : 26.02.19

 Purpose    : This class provides various function to manipulates points in space,
              as well as addition between two points.

 Comment(s) : PI is manually defined as a constant as it is not available on
              all compilers.

 Compiler   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef POINT_H
#define POINT_H

//Defined in Point.h to make the variable available to other files.
#define M_PI 3.14159265358979323846

class Point {
public:
    /**
     * Constructor without argument of class Point that set the x and y coordinate to zero.
     */
    Point();

    /**
     * Constructor of class Point with x and y coordinates.
     * @param x abscissa in float
     * @param y ordinate in float
     */
    Point(float x, float y);

    /**
     * Translate the point by adding x and y to the point.
     * @param x translation on x axis
     * @param y translation on y axis
     */
    void deplacer(float x, float y);

    /**
     * Rotate the point by the specified angle in radian.
     * @param angle in radians
     */
    void rotation(float angle);

    /**
     * Return the abscissa (x) of the point.
     * @return float abscissa
     */
    float abscisse() const;

    /**
     * Return the ordinate (y) of the point.
     * @return float ordinate
     */
    float ordonnee() const;

    /**
     * Return the rho (length) of the point in polar coordinates.
     * @return float length of the point from the origin
     */
    float rho() const;

    /**
     * Return the angle theta in radian of the point in polar coordinates.
     * @return float angle theta in radian
     */
    float theta() const;

    /**
     * Overload of the operator+ to add two points.
     * @param p point to add
     * @return newly calculated point
     */
    Point operator+(const Point& p) const;

private:
    float x;
    float y;
};

#endif //POINT_H