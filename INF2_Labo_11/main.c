/*
 -----------------------------------------------------------------------------------
 Laboratoire : 11
 Fichier     : main.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 12.06.2019

 But         : Lire dans un fichier passé en paramètre un texte.
               Le texte sera contenu sous forme de chaîne de caractère.
               Le texte sera ensuite donner à une fonction qui va indexer les mots contenus dans celui-ci. 
               Les mots et les numéros des lignes dans lesquel il ont été trouvés vont être affiché.
               La liste des mots doit être sous forme alphabétique.
               La liste sera ensuite écrite dans un fichier se nommant index.txt 

 Remarque(s) : Une liste de mot invalide(stopwords) peut être donné en paramètre ou non.

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book_index.h"

#define FICHER_A_INDEXER 1
#define FICHIER_INDEX 2
#define FICHER_STOPWORDS 3
#define NB_ARG_AIDE 2
#define NB_ARG_INDEX 3
#define NB_ARG_STOPWORDS 4
#define ARG_AIDE 1
#define OPTION_AIDE "-h"


int main(int argc, char* argv[]) {
    //Affichage de l'aide
    if (argc == NB_ARG_AIDE && strcmp(OPTION_AIDE, argv[ARG_AIDE]) == 0) {
        printf("Aide");
        return EXIT_SUCCESS;
    } else if (argc < NB_ARG_INDEX) {
        return EXIT_FAILURE;
    }

    FILE* fichierAIndexer = fopen(argv[FICHER_A_INDEXER], "r");
    if(!fichierAIndexer){
        printf("Le fichier à indexer n'existe pas");
        return EXIT_FAILURE;
    }
    FILE* fichierStopWords = fopen(argv[FICHER_STOPWORDS], "r");
    if(!fichierStopWords  && argc == NB_ARG_STOPWORDS){
        printf("Le fichier des stopwords n'existe pas");
        return EXIT_FAILURE;
    }
    FILE* fichierIndexExiste = fopen(argv[FICHIER_INDEX], "r");        
    char choix;
    if(fichierIndexExiste){
        printf("! Fichier deja existant voulez-vous l'ecraser ? [Y/N] ");
        fflush(stdout);
        scanf("%c", &choix);
        fflush(stdin);
        if('y' != tolower(choix)){
            return EXIT_SUCCESS;
        }
    }
    FILE* fichierIndex = fopen(argv[FICHIER_INDEX], "w"); //Confirmer ecrasement si le fichier existe

    fseek(fichierAIndexer, 0, SEEK_END);

    const size_t NB_OCTETS = (size_t)ftell(fichierAIndexer) + 1;
    char* texte = calloc(NB_OCTETS, sizeof(char));

    if (!texte){
        return EXIT_FAILURE;
    }
    rewind(fichierAIndexer);

    fread(texte, NB_OCTETS, 1, fichierAIndexer);

    Index* index = remplirIndex(texte, fichierStopWords);
    afficherIndex(index);
    saveToFileIndex(index, fichierIndex);
    detruireIndex(index);

    free(texte);

    fclose(fichierAIndexer);
    fclose(fichierIndex);

    return EXIT_SUCCESS;
}

