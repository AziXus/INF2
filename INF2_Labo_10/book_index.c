#include "book_index.h"
#include <stdlib.h>
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
    Headings* h = (Headings*)malloc(sizeof(Headings));
    return h;
}
Headings* remplirIndex(const char* texte){
    size_t ligne = 1;
    size_t i = 0;
    Headings* h = creerIndexVide();
    while(*(texte + i) != '\0'){
        if(*(texte + i) == ' '){
            char* mot = (char*) malloc(i * sizeof(char));
            strncpy(mot, texte, i);
            Element* el1 = (Element*)malloc(sizeof(Element));
            el1->heading = headingCreate(mot,ligne);
            el1->suivant = h->premier;
            h->premier = el1;
            
        }
        if(*(texte + i) == '\n')
        {
            char* mot = (char*) malloc(i * sizeof(char));
            strncpy(mot, texte, i);
            Element* el1 = (Element*)malloc(sizeof(Element));
            el1->heading = headingCreate(mot,ligne);
            el1->suivant = h->premier;
            h->premier = el1;
            ligne++;
        }
        i++;
    }
    return h;
}
void afficherIndex(Headings* h){
    Element* actuel = h->premier;
    while(actuel != NULL){
        headingPrint(actuel->heading);
        actuel = actuel->suivant;
    }
}
void detruireIndex(){
    
}

