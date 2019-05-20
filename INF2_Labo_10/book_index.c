#include "book_index.h"

//Structure permettant de contenir la ligne ou est indexé le mot
typedef struct Element Element;
struct Element
{
    Heading* heading;
    Element* suivant;
};

//Structure permettant d'avoir le premier element pour parcourir les différentes lignes où les mots on été stockées
typedef struct Liste Headings;
struct Liste
{
    Element* premier;
};

Heading* chercherHeading(Headings h, const char* mot){
    Element* actuel = h->premier;
    while(h != NULL)
    {
        if(h->premier->heading->mot == mot)
            return actuel->heading;
        actuel = actuel->suivant;
    }
    return NULL;
}

void creerIndexVide(){
    
}
void remplirIndex(const char* texte){
    
}
void afficherIndex(){
    
}
void detruireIndex(){
    
}

