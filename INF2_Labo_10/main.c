/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : main.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 But         : Initialiser une chaine de carcatère ressemblant un texte.
               Ensuite avec le texte donner il est possible d'indexer les mot contenus avec le mot 
               et le numéro des lignes dans lequel il a été trouvé.
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

