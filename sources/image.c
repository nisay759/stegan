/**
 * \file image.c
 * \brief Définition des fonctions de gestion de la structure Image
 * \author Unknown, Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
*/



/* Definition des fonctions permettant de lire et d'ecrire
   une image au format PGM.
   Une image est un tableau 2D de nbLignes x nbColonnes 
   de pixels codes sur un octet ( 256 niveaux de gris ) */

#include "../headers/tab2Ddynamique.h"

#define LONGUEUR 100
    
  // Definition de la fonction de lecture a partir d'un fichier

int lireImage (char *nomFichier, Image* image) 
{
  FILE *fichier;
  char ligne[LONGUEUR];
  int niveauMax;
  
  if (( fichier = fopen ( nomFichier, "r" ) ) == NULL) {
    fprintf ( stderr, "Erreur d\'ouverture de l\'image\n" );
    return ERREUR_OUVERTURE_IMG;
  }
  
  // Lecture de l'en-tete
  
  fgets ( ligne, LONGUEUR, fichier );
  if ( strstr ( ligne, "P5" ) == NULL ) {
    fprintf ( stderr, "Erreur format image\n" );
    return ERREUR_FORMAT_IMG;
  }
  do {
    fgets ( ligne, LONGUEUR, fichier );
  } while ( ligne[0] == '#' || ligne[0] == '\n' );
  sscanf ( ligne, "%d%d", &(image->nbColonnes), &(image->nbLignes));
  fscanf ( fichier, "%d", &niveauMax);
  fgetc ( fichier ); // pour le dernier retour a la ligne de l'en-tete

  // Reservatiom memoire
  
  image->t2D = allouer ( image->nbLignes, image->nbColonnes );
  
  // Lecture des valeurs de pixels
  
  fread ( image->t2D[0], sizeof(Pixel),
	  (image->nbLignes)*(image->nbColonnes), fichier );
  
  // Fermeture du fichier
  
  fclose(fichier);

  return 0;
}

  // Definition de la fonction d'ecriture dans un fichier 

int ecrireImage ( Image image,char *nomImage,char* destDossier ) {

  FILE *fichier;
  char *type = "P5";
  char *createur = "#Steganographie - Projet informatique - Télécom SudParis";
  int niveauMax = 255;
  
  int i = strlen(nomImage);
  int j=0;
  char nom[40];
  char* cheminAbsolu;

  if((cheminAbsolu=(char*)malloc(140*sizeof(char)))==NULL)
	 return ERREUR_ECRITURE_IMG; 

  cheminAbsolu[0]='\0';
  cheminAbsolu=strcat(cheminAbsolu,destDossier);
  cheminAbsolu=strcat(cheminAbsolu,"/");

  while(nomImage[i]!='/') i--;
  i++;

  while(nomImage[i]!='.' && nomImage[i]!='\0')
  {
    nom[j]=nomImage[i];
    j++;
    i++;
  }
  nom[j++]='.';
  nom[j++]='s';
  nom[j++]='t';
  nom[j++]='g'; 
  nom[j]='\0';

  cheminAbsolu=strcat(cheminAbsolu,nom);

  if ( ( fichier = fopen ( cheminAbsolu, "w" ) ) == NULL ) {
    fprintf ( stderr, "Erreur Ecriture fichier image\n" );
    return ERREUR_ECRITURE_IMG;
  }
  
  // Ecriture de l'en-tete
  
  fprintf ( fichier, "%s\n%s\n", type, createur );
  fprintf ( fichier, "%d %d\n", image.nbColonnes, image.nbLignes );
  fprintf ( fichier, "%d\n", niveauMax );
  
  // Ecriture des valeurs de pixels
  
  fwrite (image.t2D[0],sizeof(Pixel),image.nbLignes*image.nbColonnes,fichier);

  // Fermeture du fichier
  free(cheminAbsolu);  
  fclose ( fichier );
  return 0;
}
