/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : main.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 But         : Initialiser une chaine de caractère sous forme de texte.
               Le texte sera ensuite donner à une foction qui va indexer les mot contenus dans celui-ci. 
               Les mots et le numéro des lignes dans lequel il a été trouvé vont être affiché.
               La liste des mots doit être sous forme alphabétique.

 Remarque(s) :  -

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "book_index.h"


int main(void) {
    const char texte[] = "The five boxing\nwizards jump quickly.\n\nPack my box with five\ndozen liquor jugs.";
    Headings* h = remplirIndex(texte);
    afficherIndex(h);
    detruireIndex(h);
    return EXIT_SUCCESS;
}

