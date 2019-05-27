#include "book_index.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Structure permettant de contenir la ligne ou est indexé le mot
struct Element
{
    Heading* heading;
    Element* suivant;
};

//Structure permettant d'avoir le premier element pour parcourir les différentes lignes où les mots on été stockées
struct Liste
{
    Element* premier;
};


void InsererElement(Element* hPrev, Element* hInserer){
    hInserer->suivant = hPrev->suivant;
    hPrev->suivant = hInserer;
}

Element* chercherPosition(Headings* h, const char* mot) {
    if (h->premier == NULL)
        return NULL;

    Element* actuel = h->premier;

    //Tant que le mot est plus grand
    while (actuel != NULL && strcmp(actuel->heading->mot, mot) > 0) {
        actuel = actuel->suivant;
    }

    return actuel == NULL ? NULL : actuel->suivant;
}

Heading* chercherHeading(Headings* h, const char* mot){
    Element* actuel = h->premier;
    while(actuel != NULL)
    {
        if(h->premier->heading->mot == mot)
            return actuel->heading;
        actuel = actuel->suivant;
    }
    return NULL;
}

Headings* creerIndexVide(){
    Headings* h = (Headings*)calloc(1, sizeof(Headings));
    return h;
}
Headings* remplirIndex(const char* texte){
    size_t noLigne = 1;
//    size_t i = 0;
    Headings* h = creerIndexVide();

    char* ligne = strtok((char*)texte, "\n");

    while (ligne != NULL) {
//        char* mot = strtok(ligne, " ");
        Element* gauche = chercherPosition(h, ligne);

        if (gauche == NULL) {
            Element* el1 = (Element*)malloc(sizeof(Element));
            el1->heading = headingCreate(ligne, noLigne);
            el1->suivant = h->premier;
            h->premier = el1;
        } else if (gauche->heading->mot != ligne) {
            Element* el1 = (Element*)malloc(sizeof(Element));
            el1->heading = headingCreate(ligne, noLigne);

            InsererElement(gauche, el1);
        }

        noLigne++;
        ligne = strtok(NULL, "\n");
    }


//        while ((mot = strtok(ligne, " ")) != NULL) {
//
//        }
//    }

//    while(*(texte + i) != '\0'){
//        if(*(texte + i) == ' '){
//            char* mot = (char*) malloc(i * sizeof(char));
//            strncpy(mot, texte, i);
//            Element* el1 = (Element*)malloc(sizeof(Element));
//            el1->heading = headingCreate(mot,ligne);
//            el1->suivant = h->premier;
//            h->premier = el1;
//
//        }
//        if(*(texte + i) == '\n')
//        {
//            char* mot = (char*) malloc(i * sizeof(char));
//            strncpy(mot, texte, i);
//            Element* el1 = (Element*)malloc(sizeof(Element));
//y            el1->heading = headingCreate(mot,ligne);
//            el1->suivant = h->premier;
//            h->premier = el1;
//            ligne++;
//        }
//        i++;
//    }
    return h;
}
void afficherIndex(Headings* h){
    Element* actuel = h->premier;
    while(actuel != NULL){
        headingPrint(actuel->heading);
        printf("\n");
        actuel = actuel->suivant;
    }

    printf("\n");
}
void detruireIndex(){
    
}

