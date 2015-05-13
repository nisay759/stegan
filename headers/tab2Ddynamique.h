#ifndef _TAB2D_DYNAMIQUE_H
#define _TAB2D_DYNAMIQUE_H 1

/**
 * \file tab2Ddynamique.h
 * \brief Module de gestion d'un tableau dynamique 2D nbLignes x nbColonnes
 * \author Unknown
 * \version 1.0
 * \date 26 Février 2015
*/

/* Module de gestion d'un tableau dynamique 2D nbLignes x nbColonnes 
   de pixels codes sur un octet ( 256 niveaux de gris ) */

#include "image.h"

  // Declaration des fonctions allouer et desallouer

/**
 * \fn Pixel **allouer ( int nbLignes, int nbColonnes )
 * \brief Alloue dynamiquement la mémoire pour un tableau 2D nbLignes x nbColonnes
 *
 * \param nbLignes Nombre de lignes du tableau 2D
 * \param nbColonnes Nombre de Colonnes du tableau 2D
 * \return Tableau 2D nbLignes x nb Colonnes alloué dynamiquement
*/
Pixel **allouer ( int nbLignes, int nbColonnes );

/**
 * \fn Pixel **desallouer ( Pixel **t2D )
 * \brief Libère la mémoire précédemment allouée par la fonction allouer
 *
 * \param Tableau 2D à désallouer
 * \return NULL
*/
Pixel **desallouer ( Pixel **t2D );

#endif
