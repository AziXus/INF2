/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : book_index.h
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 01.05.2019

 But         : Initialiser une structures Headings pour créer le principe de liste chainée dans le stockage des différents mots.
               La structure Headings contiendra tout les mot du texte à indexer.
               On doit pouvoir remplir et détruire une struct Headings.

 Remarque(s) : Les mots à indexer (headings) sont définis ainsi : une suite de caractères alphanumériques sans
               espace entre eux.
               Il est composé d'au moins 3 caractères. Les lettres sont converties en minuscules.
               Les ponctuations accolées aux mots (point ou virgule) sont supprimées.

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#ifndef BOOK_INDEX_H
#define BOOK_INDEX_H
#include "heading.h"
//Liste allant contenir tout les éléments de type Heading(mot)
typedef struct Liste Headings;
//Element allant contenir le mot indexé et l'élément suivant dans la liste
typedef struct Element Element;

/**
 * Renvoie la postion à laquelle ajouter un nouveau mot.
 * Il renvoie l'élément qui devra être à gauche du nouveau mot.
 * @param h liste des mots déjà indexer
 * @param mot chaîne de caractère constante étant le mot à ajouter
 * @return la position de l'élément à gauche du nouveau mot.
 */
Element* chercherPosition(Headings* h, const char* mot);

/**
 * Permet de créer une liste de mot à indexer vide
 * @return la liste vide
 */
Headings* creerIndexVide();

/**
 * Rempli un index de mot avec un texte passé en paramètre
 * @param texte chaîne de caractère constante étant le texte à indexer
 * @return le liste avec tous les mots indexés
 */
Headings* remplirIndex(const char* texte);

/**
 * Permet d'afficher la liste avec les mot indexés
 * @param h adresse vers la liste des mot indexés
 */
void afficherIndex(Headings* h);

/**
 * Permet de détruire(suprrimer) une liste de mot indexer.
 * Cette fonction détruit l'espace en mémoire pris par la liste chainée.
 * @param h adresse vers la liste des mot indexés
 */
void detruireIndex(Headings* h);

#endif /* BOOK_INDEX_H */

