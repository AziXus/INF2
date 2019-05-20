#include "heading.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void headingCreate(const char* mot, int nombreLigne){
    Heading h = {mot, NULL};
    if(nombreLigne != 0){
        Location* ligne = (Location*)malloc(sizeof(Location));
        ligne->nombre = nombreLigne;
        ligne->suivant = h->premier;
        h->premier = ligne;
    }
}

void headingDestroy(Heading* h){
    if (h->premier != NULL)
    {
        Location* aSupprimer = h->premier;
        h->premier = h->premier->suivant;
        free(aSupprimer);
    }
}

void headingPrint(Heading* h){
    printf("%s,", h->mot);
    Location* actuel = h->premier;
    while(actuel != NULL){
        printf(" %d", actuel->nombre);
        actuel = actuel->suivant;
    }
}

