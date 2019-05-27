#ifndef BOOK_INDEX_H
#define BOOK_INDEX_H
#include "heading.h"
typedef struct Liste Headings;
typedef struct Element Element;

Element* chercherPosition(Headings* h, const char* mot);
Headings* creerIndexVide();
Headings* remplirIndex(const char* texte);
void afficherIndex();
void detruireIndex();

#endif /* BOOK_INDEX_H */

