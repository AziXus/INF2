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
//#include <ostream>
//#include <vector>
#include <stdbool.h>
#include <stdlib.h>

//On remplace les template par des #defines génériques, static pour n'avoir une seule déclaration
/**
 * @brief Return the smallest value of \p a and \p b.
 */
#define MIN_VALUE(T)\
static T T##_min_value(T a, T b) {\
    return (a < b) ? a : b;\
}

/**
 * @brief Return the smallest value of \p a, \p b and \p c.
 */
#define MIN_VALUE_3(T)\
static T T##_min_value_3(T a, T b, T c) {\
return (a < b) ? T##_min_value(a, c) : T##_min_value(b, c);\
}

MIN_VALUE(int);
MIN_VALUE(double);
MIN_VALUE_3(double);

/**
 * @brief Divide \p a by \p b and returns the \p quotient and the \p remainder
 * @return `true` is division was possible, `false` otherwise
 */
//On ne peut pas passer une référence donc on passe une adresse
bool divide(int a, int b, int* quotient, int* remainder);
