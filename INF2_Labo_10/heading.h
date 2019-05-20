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
    char* mot;
    Location* premier;
} Heading;

void headingCreate(Heading* h);

void headingDestroy(Heading* h);

void headingPrint(Heading* h);

#endif /* HEADING_H */

