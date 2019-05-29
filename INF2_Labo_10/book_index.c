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

void insertion(size_t noLigne, Headings* h, struct Element* gauche, char* mot){
    Element* el1 = (Element*)malloc(sizeof(Element));
    el1->heading = headingCreate(mot, noLigne);
    if (gauche == NULL) {
        el1->suivant = h->premier;
        h->premier = el1;
    } else if (strcmp(gauche->heading->mot, mot) != 0) {
        InsererElement(gauche, el1);
    }
}

Headings* remplirIndex(const char* texte){
    size_t noLigne       = 1;//Indique le numéro de ligne ue nous lisons
    size_t i             = 0;//Va permettre de parcourt le mot de la ligne caractère par caractère 
    size_t dernierEspace = 0;//Permet de parcourir le mot contenu dans une ligne
    Headings* h          = creerIndexVide();
    char* ligne          = strtok((char*)texte, "\n");//Divise le texte en tableau de plusieurs éléments le délimiteur est \n
    //Parcourt toute les lignes
    while (ligne != NULL) {
        //Parcourt tous les caractère de la ligne i
        while(*(ligne + i) != '\0'){
            //Si un espace est detecté on en sort le mot
            if(*(ligne + i) == ' '){
                char* mot = (char*) calloc(i, sizeof(char));
                //On copie les i - j caractère de l'élément ligne + j
                strncpy(mot, ligne + dernierEspace, i - dernierEspace);
                //On cherche la position dans laquelle ajouter le mot 
                Element* gauche = chercherPosition(h, mot);
                insertion(noLigne, h, gauche, mot);
                dernierEspace = i + 1;
            }
            i++;
        }
        Element* gauche = chercherPosition(h, ligne + dernierEspace);

        insertion(noLigne, h, gauche, ligne + dernierEspace);

        noLigne++;
        ligne = strtok(NULL, "\n");
        dernierEspace = 0;
        i = 0;
    }
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

