/**
 * @brief printing
 *
 * @author romain
 * @date 14.04.2016
 * @file printing.h
 *
 * Print some text to the console, optionnally with a value just after.
 */

#ifndef PRINTING_H
#define PRINTING_H

#include <stdio.h>
#include <stdbool.h>

void print_str(const char * str);
void print_int(const char * str, const int val);
void print_float(const char * str, const double val);

#endif // PRINTING_H
