/*
 -----------------------------------------------------------------------------------
 Laboratoire : 11
 Fichier     : book_index.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 12.06.2019

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "book_index.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define DELIMITEUR_LIGNE '\n'
#define DELIMITEUR_MOT ' '

//Tableau contenant des caractères pouvant être en début ou fin de mot et qu'il faut enlever
const char CARACTERE_SPECIAL[] = {'.', ',', ':', '?', ';', '!', '"', '-', '[', ']', '(', ')', '<', '\''};
const size_t TAILLE_CARACTERE_SPECIAL = sizeof(CARACTERE_SPECIAL)/sizeof(char);

/**
 * Permet d'insérer en élément à la suite d'un élément donnée
 * @param hPrev adresse de l'élément étant le mot qui sera juste avant le futur mot à ajouter
 * @param hInserer adresse de l'élément étant le futur mot à ajouter
 */
void insererElement(Element* hPrev, Element* hInserer);

/**
 * Permet d'insérer un mot dans la liste
 * @param noLigne size_t étant le valeur du noLigne du mot à insérer
 * @param h adresse d'un Index étant la liste des mots indexer
 * @param mot premier caractère du mot à insérer
 */
void insertion(Index* h, const char* mot, size_t noLigne);

/**
 * Permet de convertir en minuscule une chaîne de caractère
 * @param c adresse vers le début de la chaîne de caractère
 */
void strtolower(char* c);

/**
 * Permet de savoir si le caractère passé par paramètre est un caractère non alphanumérique
 * @param c caractère passé en paramètre
 * @return vrai si le caractère est dans le tableau, faux sinon
 */
bool estCaractereSpecial(char c);

/**
 * Determine si le mot est valide. Un mot valide ne contient pas d'autres caractères que ceux alphanumerique(A-Z et 0-9)
 * @param mot chaîne de caractère étant le mot à vérifier
 * @param stopwords Fichier contenant des mots invalide(paramètre non-nécessaire peut être nul)
 * @return vrai si le mot est valide, false sinon
 */
bool motValide(char* mot, FILE* stopwords);

//Structure permettant de contenir la mot et l'élément suivant dans la liste
struct Element
{
    Heading* heading;
    Element* suivant;
};

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

Index* creerIndexVide(){
    Index* h = (Index*)calloc(1, sizeof(Index));
    if(!h){
        printf("Allocation en mémoire echouee");
        return NULL;
    }
    return h;
}

Index* remplirIndex(char* texte, FILE* stopwords){
    size_t noLigne       = 1;//Indique le numéro de ligne que nous lisons
    size_t i             = 0;//Va permettre de parcourir les mot de la ligne caractère par caractère
    size_t debutMot      = 0;//Permet de donner le début du mot dans la ligne
    Index* h             = creerIndexVide();
    bool   finLigne      = false;

    while(*(texte + i) != '\0') {
        //Si un espace, une nouvelle ligne ou la fin de la chaine est detecté on en sort le mot
        //*(texte + i + 1) == '\0' permet de nous arrêter un caractère avant que la condition de la boucle soit vraie pour en ressortir le mot
        if (*(texte + i) == DELIMITEUR_MOT || *(texte + i) == DELIMITEUR_LIGNE || *(texte + i + 1) == '\0') {
            size_t finMot = i;
            //Comme on va modifier le dernier caractère on garde une variable qui indique que le mot était en fin de ligne
            if(*(texte + finMot) == DELIMITEUR_LIGNE){
                finLigne = true;
            }
            //Tant que le premier caractère du mot est un caractère spécial on reduit la taille du mot
            while(estCaractereSpecial(*(texte + debutMot))){
                debutMot++;
            }
            //Tant que le dernier caractère du mot est un caractère spécial on reduit la taille du mot
            while(estCaractereSpecial(*(texte + finMot - 1)))
                --finMot;

            //On garde uniquement les mots de plus de 3 caractères
            if (finMot - debutMot >= MIN_CAR_MOT) {
                //On remplace le dernier caractère par un \0 afin de terminer le mot
                *(texte + finMot) = '\0';
                //On converti le mot en miniscule
                strtolower(texte + debutMot);

                if (motValide(texte + debutMot, stopwords)) {
                    //on insert le mot dans la liste
                    insertion(h, texte + debutMot, noLigne);
                }
            }
            //on stocke le début du prochain mot
            debutMot = i + 1;
        }
        //Si on est en fin de ligne on incrémente la ligne
        if(finLigne){
            ++noLigne;
            finLigne = false;
        }

        ++i;
    }

    return h;
}

void saveToFileIndex(Index* h, FILE* fichier){
    Element* actuel = *h;
    while(actuel != NULL){
        saveToFileHeading(actuel->heading, fichier);
        fprintf(fichier, "\n");
        actuel = actuel->suivant;
    }
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

void insererElement(Element* hPrev, Element* hInserer) {
    hInserer->suivant = hPrev->suivant;
    hPrev->suivant = hInserer;
}

void insertion(Index* h, const char* mot, size_t noLigne){
    //On cherche la position dans laquelle ajouter le mot
    Element* elementGauche = chercherPosition(h, mot);
    Element* el1 = (Element*)malloc(sizeof(Element));
    if(el1){
        el1->heading = headingCreate(mot, noLigne);

        //Si l'élément de gauche est NULL cela signifie qu'on ajoute au début
        if (elementGauche == NULL) {
            el1->suivant = *h;
            *h = el1;
        } else if (strcmp(elementGauche->heading->mot, mot) != 0) {
            insererElement(elementGauche, el1);
        } else if (strcmp(elementGauche->heading->mot, mot) == 0) {
            insererLigne(elementGauche->heading, noLigne);
        }
    }else{
        printf("Allocation en mémoire echouee");
    }
}


void strtolower(char* c) {
    while (*c != '\0') {
        *c = (char)tolower(*c);
        ++c;
    }
}

bool estCaractereSpecial(char c){
    for(size_t i = 0; i < TAILLE_CARACTERE_SPECIAL; i++)
        if(c == CARACTERE_SPECIAL[i])
            return true;
    return false;        
}

bool motValide(char* mot, FILE* stopwords) {
    //Si le mot contient un carcatère non alphanumérique, il est invalide
    for (size_t i = 0; i < strlen(mot); ++i) {
        if (!isalnum(mot[i]))
            return false;
    }

    if (stopwords != NULL) {
        const size_t TAILLE_MAX = 256;
        char buf[TAILLE_MAX];

        rewind(stopwords);

        while (fgets(buf, (int)sizeof(buf), stopwords)) {
            if (buf[strlen(buf) - 1] == '\n')
                buf[strlen(buf) - 1] = '\0';

            if (strcmp(mot, buf) == 0)
                return false;
        }
    }
    return true;
}
