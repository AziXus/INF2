/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : Heading.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#include "heading.h"
#include <stdio.h>
#include <string.h>

Heading* headingCreate(const char* mot, size_t nombreLigne){
    //Allocation en mémoire du heading à créer
    Heading* h = (Heading*)malloc(sizeof(Heading));
    h->mot = mot;
    h->premier = NULL;
    //Si la ligne ne vaut pas 0 alors elle est valide et on peut ajouter une ligne au mot
    if(nombreLigne != 0){
        //Allocation en mémoire de la taille que va prendre Loction
        Location* ligne = (Location*)malloc(sizeof(Location));
        ligne->nombre = nombreLigne;
        ligne->suivant = h->premier;
        h->premier = ligne;
    }
    return h;
}

void headingDestroy(Heading* h){
    //Boucle permettant de supprimer toutes les struct Location d'un Heading
    while(h->premier != NULL)
    {
        Location* aSupprimer = h->premier;
        h->premier = h->premier->suivant;
        free(aSupprimer);
    }
    free((void*)h->mot);//Comme les mots sont allouées dynamiquement on doit les free également
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

