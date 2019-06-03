/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : main.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 03.06.2019

 But         : Initialiser une chaine de caractère sous forme de texte.
               Le texte sera ensuite donner à une fonction qui va indexer les mot contenus dans celui-ci. 
               Les mots et le numéro des lignes dans lequel il a été trouvé vont être affiché.
               La liste des mots doit être sous forme alphabétique.

 Remarque(s) :  -

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_index.h"


int main(void) {
    const char texte[] = "The five boxing\nwizards jump quickly.\n\nPack my box with five\ndozen liquor jugs.";

    char* copieTexte = malloc(sizeof(texte));
    strcpy(copieTexte, texte);

    Index* index = remplirIndex(copieTexte);
    afficherIndex(index);
    detruireIndex(index);
    return EXIT_SUCCESS;
}

