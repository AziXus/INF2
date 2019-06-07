/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : book_index.h
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 03.06.2019

 But         : Initialiser une structure nommée Element pour créer le principe de liste chainée pour le stockage des différents mots.
               L'élément pointé Index indique le début de la liste de tout les mot du texte à indexer.
               On doit pouvoir remplir et détruire la liste.

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
#define MIN_CAR_MOT 3
//Element allant contenir le mot indexé et l'élément suivant dans la liste
typedef struct Element Element;
//Pointeur vers le début de la liste(mots indexés)
typedef Element* Index;

/**
 * Renvoie la postion à laquelle ajouter un nouveau mot.
 * Il renvoie l'élément qui devra être à gauche du nouveau mot.
 * @param h adresse vers le debut de la liste des mots déjà indexés
 * @param mot chaîne de caractère constante étant le mot à ajouter
 * @return la position de l'élément à gauche du nouveau mot.
 */
Element* chercherPosition(Index* h, const char* mot);

/**
 * Permet de créer une liste de mot à indexer vide
 * @return la liste vide
 */
Index* creerIndexVide();

/**
 * Rempli un index de mot avec un texte passé en paramètre
 * @param texte chaîne de caractère constante étant le texte à indexer
 * @return adresse vers le début de la liste avec tous les mots indexés
 */
Index* remplirIndex(char* texte);

void saveToFileIndex(Index* h, FILE* fichier);

/**
 * Permet d'afficher la liste avec les mot indexés
 * @param h adresse vers la liste des mot indexés
 */
void afficherIndex(Index* h);

/**
 * Permet de détruire(suprrimer) une liste de mot indexer.
 * Cette fonction détruit l'espace en mémoire pris par la liste chainée.
 * @param h adresse vers la liste des mot indexés
 */
void detruireIndex(Index* h);

#endif /* BOOK_INDEX_H */

