/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : heading.h
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 But         : Initialiser deux structures pour créer le principe de liste chainée.
               La structure Location contiendra les numéro du ligne ou le mot à été trouvé.
               La structure Heading permettra de contenir tout les mot trouvés.

 Remarque(s) : La structure Heading a été créee dans le fichiers heading.h pour permettre à book_index.c d'utiliser 
               les variables de cette structure.

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef HEADING_H
#define HEADING_H
#include <stdlib.h>

//Structure permettant de contenir la ligne ou est indexé le mot
typedef struct Ligne Location;

//Structure contenant le mot ainsi que l'adresse du premier numéro de ligne
typedef struct
{
    const char* mot;
    Location* premier;
} Heading;

/**
 * Insère une ligne dans le heading(mot indexer) passé par paramètre
 * @param heading adresse de l'objet heading auquel ajouter une ligne
 * @param noLigne size_t étant la ligne à ajouter
 */
void insererLigne(Heading* heading, size_t noLigne);

/**
 * Permet de créer un objet de type Heading(mot à indexer)
 * @param mot adresse vers le début d'une chaîne étant le mot à ajouter
 * @param nombreLigne size_t étant le numéro de la ligne ou est stocké le mot
 * @return l'adresse de l'objet Heading initialisé
 */
Heading* headingCreate(const char* mot, size_t nombreLigne);

/**
 * Permet de libérer l'espace en mémoire pris par un Heading.
 * Supprime un heading.
 * @param h adresse du Heading à supprimer
 */
void headingDestroy(Heading* h);

/**
 * Permet d'afficher les valeurs d'un Heading
 * @param h adresse du Heading à supprimer
 */
void headingPrint(Heading* h);

#endif /* HEADING_H */

