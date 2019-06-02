/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : book_index.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "book_index.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Permet d'insérer en élément à la suite d'un élément donnée
 * @param hPrev adresse de l'élément étant le mot qui sera juste avant le futur mot à ajouter
 * @param hInserer adresse de l'élément étant le futur mot à ajouter
 */
void insererElement(Element* hPrev, Element* hInserer);

/**
 * Permet d'insérer un mot dans la liste
 * @param noLigne size_t étant le valeur du noLigne du mot à insérer
 * @param h adresse d'un Headings étant la liste des mots indexer
 * @param mot premier caractère du mot à insérer
 */
void insertion(size_t noLigne, Index* h, const char* mot);

void strtolower(char* c);

//Structure permettant de contenir la ligne ou est indexé le mot
struct Element
{
    Heading* heading;
    Element* suivant;
};

void insererElement(Element* hPrev, Element* hInserer) {
    //si les mot dont les mêmes on ne l'insère pas
    if(hPrev->heading->mot != hInserer->heading->mot){
        hInserer->suivant = hPrev->suivant;
        hPrev->suivant = hInserer;
    }
}

Element* chercherPosition(Index* h, const char* mot) {
    if (*h == NULL)
        return NULL;

    Element* actuel = *h;
    Element* prev = NULL;

    //On boucle tant que le char est plus grand et on s'arrête quand il est plus petit ou égal
    while (actuel != NULL && strcmp(actuel->heading->mot, mot) <= 0) {
        prev = actuel;
        actuel = actuel->suivant;
    }

    return prev;
}

Heading* chercherHeading(Index* h, const char* mot){
    Element* actuel = *h;
    while(actuel != NULL)
    {
        if((*h)->heading->mot == mot)
            return actuel->heading;
        actuel = actuel->suivant;
    }
    return NULL;
}

Index* creerIndexVide(){
    Index* h = (Index*)calloc(1, sizeof(Index));
    return h;
}

void insertion(size_t noLigne, Index* h, const char* mot){
    //On cherche la position dans laquelle ajouter le mot
    Element* elementGauche = chercherPosition(h, mot);
    Element* el1 = (Element*)malloc(sizeof(Element));
    el1->heading = headingCreate(mot, noLigne);

    //Si l'élément de gauche est NULL cela signifie qu'on ajout au début
    if (elementGauche == NULL) {
        el1->suivant = *h;
        *h = el1;
    } else if (strcmp(elementGauche->heading->mot, mot) != 0) {
        insererElement(elementGauche, el1);
    } else if (strcmp(elementGauche->heading->mot, mot) == 0) {
        //Ajouter une ligne
        insererLigne(elementGauche->heading, noLigne);
    }
}

Index* remplirIndex(char* texte){
    size_t noLigne       = 1;//Indique le numéro de ligne ue nous lisons
    size_t i             = 0;//Va permettre de parcourt le mot de la ligne caractère par caractère
    size_t debutMot      = 0;//Permet de parcourir le mot contenu dans une ligne
    Index* h             = creerIndexVide();

    while(*(texte + i) != '\0') {
        //Si un espace, une nouvelle ligne ou la fin de la chaine est detecté on en sort le mot
        if (*(texte + i) == ' ' || *(texte + i) == '\n' || *(texte + i + 1) == '\0') {
            size_t finMot = i;
            //Si le dernier caractère du mot est un point ou une virgule, on réduit la taille du mot de 1
            if (*(texte + finMot - 1) == '.' || *(texte + finMot - 1) == ',')
                --finMot;

            //On garde uniquement les mots de plus de 3 caractères
            if (finMot - debutMot >= 3) {
                //On remplace le dernier caractère par un \0 afin de terminer le mot
                *(texte + finMot) = '\0';
                //On converti le mot en miniscule
                strtolower(texte + debutMot);

                insertion(noLigne, h, texte + debutMot);
            }

            debutMot = i + 1;
        }

        if (*(texte + i) == '\n')
            ++noLigne;

        ++i;
    }

    return h;
}
void afficherIndex(Index* h){
    Element* actuel = *h;
    while(actuel != NULL){
        headingPrint(actuel->heading);
        printf("\n");
        actuel = actuel->suivant;
    }

    printf("\n");
}

void detruireIndex(Index* h){
    while(*h != NULL)
    {
        Element* aSupprimer = *h;
        headingDestroy(aSupprimer->heading);
        *h = (*h)->suivant;
        free(aSupprimer);
    }

    free(h);
}

void strtolower(char* c) {
    while (*c != '\0') {
        *c = (char)tolower(*c);
        ++c;
    }
}
