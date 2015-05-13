#ifndef _IMAGE_H
#define _IMAGE_H 1
/**
 * \file image.h
 * \brief Définition des types Pixel et Image
 * \author Unknown, Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/macros.h"

/* Definition des types Pixel et Image
   Une image est un tableau 2D de nbLignes x nbColonnes 
   de pixels codes sur un octet ( 256 niveaux de gris ) */

/** Définition d'un char en tant que Pixel (8 bits) */
typedef unsigned char Pixel;

/**
 * \struct Image
 * \brief Structure contenant le nombre de lignes et de colonnes ainsi qu'un tableau à 2 dimensions pour accueillir l'image
*/
typedef struct { 
	int nbLignes; /*!< Nombre de lignes */
	int nbColonnes; /*!< Nombre de colonnes */
	Pixel **t2D; /*!< Tableau 2D contenant l'image */
 } Image;

    
/* Declaration des fonctions de lecture-ecriture */

/**
 * \fn int lireImage(char * nomFichier)
 * \brief Récupère les données concernant une image .pgm
 *
 * \param nomFichier Nom du fichier image .pgm
 * \param image ointeur sur une structure Image qui recevrea les pixels de l'image .pgm
 * \return Code d'erreur
*/
int lireImage ( char *nomFichier, Image *image );

/**
 * \fn int ecrireImage(Image image, char * nomFichier)
 * \brief Stock une structure Image dans un fichier .pgm
 *
 * \param image Structure Image contenant les pixels de l'image .pgm à enregistrer
 * \param nomImage Chaine de caractère contenant le nom du fichier image passé en paramètre en ligne de commande
 * \param destDossier Chaine de caractère contenant le dossier destiné à recevoir l'image à enregister
 * \return Code d'erreur
*/
int ecrireImage ( Image image, char* nomImage, char* destDossier );

#endif
