#include "heading.h"
#include <stdlib.h>
#include <string.h>

void headingCreate(const char* mot, int ligne){
    Heading heading = {mot, NULL};
    if(ligne != 0){
        Location* ligne = malloc(sizeof(*Location));
        ligne->nombre = ligne;
        ligne->suivant = heading->premier;
        heading->premier = ligne;
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

