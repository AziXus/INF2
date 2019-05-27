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
    Element* prev = NULL;

    //Tant que le mot est plus grand
    //a - b - c
    //
    //On boucle tant que le char est plus grand et on s'arrête quand il est plus petit ou égal
    while (actuel != NULL && strcmp(actuel->heading->mot, mot) < 0) {
        prev = actuel;
        actuel = actuel->suivant;
    }

    return prev;// == NULL ? NULL : actuel->suivant;
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

void insertion(size_t noLigne, size_t j, Headings* h, char* ligne, struct Element* gauche, char* mot){
    if (gauche == NULL) {
        Element* el1 = (Element*)malloc(sizeof(Element));
        el1->heading = headingCreate(mot, noLigne);
        el1->suivant = h->premier;
        h->premier = el1;
    } else if (strcmp(gauche->heading->mot, ligne + j) != 0) {
        Element* el1 = (Element*)malloc(sizeof(Element));
        el1->heading = headingCreate(mot, noLigne);
        InsererElement(gauche, el1);
    }
}

Headings* remplirIndex(const char* texte){
    size_t noLigne = 1;
    size_t i = 0;
    size_t j = 0;
    Headings* h = creerIndexVide();

    char* ligne = strtok((char*)texte, "\n");

    while (ligne != NULL) {
        while(*(ligne + i) != '\0'){
            if(*(ligne + i) == ' '){
                char* mot = (char*) calloc(i, sizeof(char));
                strncpy(mot, ligne + j, i);
                Element* gauche = chercherPosition(h, mot);
                insertion(noLigne, j, h, ligne, gauche, mot);
                j = i + 1;
            }
            i++;
        }
        Element* gauche = chercherPosition(h, ligne + j);

        insertion(noLigne, j, h, ligne, gauche, ligne + j);

        noLigne++;
        ligne = strtok(NULL, "\n");
        j = 0;
        i = 0;
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

