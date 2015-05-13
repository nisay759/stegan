/**
 * \file stegout.c
 * \brief Programme stegout: Extrait les informations enfouites précédemment dans l'image .pgm avec le programme stegin
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 02 Mars 2015
*/
#include "../headers/extraire.h"
#include "../headers/stegout.h"

int stegout(char* image_source, char* destDossier)
{
	Image image;
	Texte texte;
	int erreur;

	if((erreur=lireImage(image_source,&image))!=0)
		return erreur;

	extraire(image,&texte);

	if((erreur=ecrireTexte(texte,destDossier))!=0)
		return erreur;

	return 0;
}
