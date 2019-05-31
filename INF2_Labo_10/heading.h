/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : Heading.h
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 But         : Initialiser deux structures pour créer le principe de liste chainée.
               La structure Location contiendra les numéro du ligne ou le mot à été trouvé.
               La structure Heading permettra de contenir tout les mot trouvés.

 Remarque(s) :  -

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 

#ifndef HEADING_H
#define HEADING_H
#include <stdlib.h>

//Structure permettant de contenir la ligne ou est indexé le mot
typedef struct Ligne Location;
struct Ligne
{
    size_t nombre;
    Location* suivant;
};
//Structure contenant le mot ainsi que l'adresse du premier numéro de ligne
typedef struct
{
    const char* mot;
    Location* premier;
} Heading;

/**
 * Permet de créer un objet de type Heading
 * @param mot adresse vers le début d'une chaîne étant le mot à ajouter
 * @param nombreLigne size_t étant le numéro de la ligne ou est stocké le mot
 * @return l'adresse de l'objet Heading initialisé
 */
Heading* headingCreate(const char* mot, size_t nombreLigne);

/**
 * Permet de libérer l'espace en mémoire(supprimer) pris par un Heading
 * @param h adresse du Heading à supprimer
 */
void headingDestroy(Heading* h);

/**
 * Permet d'afficher les valeurs d'un Heading
 * @param h adresse du Heading à supprimer
 */
void headingPrint(Heading* h);

#endif /* HEADING_H */

