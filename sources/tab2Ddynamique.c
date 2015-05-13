/**
 * \file tab2Ddynamique.c
 * \brief Définition des fonctions allouer et desallouer
 * \author Unknown
 * \version 1.0
 * \date 26 Février 2015
*/


/* Module de gestion d'un tableau dynamique 2D nbLignes x nbColonnes 
   de pixels codes sur un octet ( 256 niveaux de gris */

#include "../headers/tab2Ddynamique.h"

  // Allocation memoire pour les deux tableaux

Pixel **allouer ( int nbLignes, int nbColonnes ) {

  int i;
  Pixel **t2D; 

  if ( ( t2D = malloc ( nbLignes*sizeof(Pixel *) ) ) == NULL ) {
    fprintf ( stderr, "Erreur allocation memoire t2D\n" );
    exit ( EXIT_FAILURE );
  }         
  if ( ( t2D[0] = malloc ( nbLignes*nbColonnes*sizeof(Pixel) ) ) == NULL ) {
    fprintf ( stderr, "Erreur allocation memoire t2D[0]\n" );
    exit ( EXIT_FAILURE );
  }
  
  // Initialisation du tableau de pointeurs sur int
  
  for ( i=1; i<nbLignes; i++ )
    t2D[i] = t2D[0]+i*nbColonnes;;
  
  return t2D;
}

  // Desallocation

Pixel **desallouer ( Pixel **t2D ) {

  free ( t2D[0] );
  free ( t2D );
  return NULL;
}
