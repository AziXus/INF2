/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : Heading.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 03.06.2019

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#include "heading.h"
#include <stdio.h>
#include <string.h>

struct Ligne
{
    size_t nombre;
    Location* suivant;
};

Heading* headingCreate(const char* mot, size_t nombreLigne){
    //Allocation en mémoire du heading à créer
    Heading* h = (Heading*)malloc(sizeof(Heading));
    h->mot = mot;
    h->premier = NULL;
    //Si la ligne ne vaut pas 0 alors elle est valide et on peut ajouter une ligne au mot
    if(nombreLigne != 0){
        //Allocation en mémoire de la taille pour une variable Location(numéro de ligne)
        Location* ligne = (Location*)malloc(sizeof(Location));
        ligne->nombre = nombreLigne;
        ligne->suivant = h->premier;
        h->premier = ligne;
    }
    return h;
}

void insererLigne(Heading* heading, size_t noLigne) {
    Location* ligne = (Location*)malloc(sizeof(Location));
    ligne->nombre = noLigne;
    ligne->suivant = NULL;

    while (heading->premier->suivant != NULL) {
        heading->premier = heading->premier->suivant;
    }

    heading->premier->suivant = ligne;
}

void headingDestroy(Heading* h){
    //Boucle permettant de supprimer touts les objets Location d'un Heading
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
        printf(" %zu", actuel->nombre);
        actuel = actuel->suivant;
        if (actuel != NULL)
            printf(", ");
    }
}

