/**
 * @brief Definition of some dummy utils functions.
 *
 * @author romain
 * @date 14.04.2016
 * @file utils.h
 *
 */

#pragma once

//#include <cstdlib>
#include <stdlib.h>
#include <stdbool.h>
//#include <ostream>
//#include <vector>

//On remplace le template par plusieurs fonctions avec des noms différents
/**
 * @brief Return the smallest value of \p a and \p b.
 */
double min_value(double a, double b);

/**
 * @brief Return the smallest value of \p a, \p b and \p c.
 */
double min_value_3(double a, double b, double c);

/**
 * @brief Divide \p a by \p b and returns the \p quotient and the \p remainder
 * @return `true` is division was possible, `false` otherwise
 */
//On ne peut pas passer une référence donc on passe une adresse
bool divide(int a, int b, int *quotient, int *remainder);
