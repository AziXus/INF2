#include "heading.h"
#include <stdio.h>
#include <string.h>

Heading* headingCreate(const char* mot, size_t nombreLigne){
    Heading* h = (Heading*)malloc(sizeof(Heading));
    h->mot = mot;
    h->premier = NULL;
    if(nombreLigne != 0){
        Location* ligne = (Location*)malloc(sizeof(Location));
        ligne->nombre = nombreLigne;
        ligne->suivant = h->premier;
        h->premier = ligne;
    }
    return h;
}

void headingDestroy(Heading* h){
    while(h->premier != NULL)
    {
        Location* aSupprimer = h->premier;
        h->premier = h->premier->suivant;
        free(aSupprimer);
    }
    free(h);
}

void headingPrint(Heading* h){
    printf("%s,", h->mot);
    Location* actuel = h->premier;
    while(actuel != NULL){
        printf(" %d", actuel->nombre);
        actuel = actuel->suivant;
    }
}

