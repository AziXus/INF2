#ifndef HEADING_H
#define HEADING_H

//Structure permettant de contenir la ligne ou est indexé le mot
typedef struct Element Location;
struct Element
{
    int nombre;
    Element* suivant;
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

