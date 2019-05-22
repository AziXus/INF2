#ifndef HEADING_H
#define HEADING_H

//Structure permettant de contenir la ligne ou est indexé le mot
typedef struct Ligne Location;
struct Ligne
{
    int nombre;
    Location* suivant;
};

typedef struct
{
    const char* mot;
    Location* premier;
} Heading;

Heading* headingCreate(const char* mot, unsigned long nombreLigne);

void headingDestroy(Heading* h);

void headingPrint(Heading* h);

#endif /* HEADING_H */

