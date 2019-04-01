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

/**
 * @brief Return the smallest value of \p a and \p b.
 */
//template <typename T>
static int min_value(int a, int b)
{
    return (a < b) ? a : b;
}

/**
 * @brief Return the smallest value of \p a and \p b.
 */
static float min_value_2f(float a, float b)
{
    return (a < b) ? a : b;
}

/**
 * @brief Return the smallest value of \p a, \p b and \p c.
 */
//template <typename T>
static float min_value_3f(float a, float b, float c)
{
    return (a < b) ? min_value_2f(a, c) : min_value_2f(b, c);
}

/**
 * @brief Divide \p a by \p b and returns the \p quotient and the \p remainder
 * @return `true` is division was possible, `false` otherwise
 */
//bool divide(int a, int b, int &quotient, int &remainder);
bool divide(int a, int b, int *quotient, int *remainder);
