/**
 * \file stegin.c
 * \brief Programme stegin: Enfouit un fichier .txt dans une image .pgm
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
*/

#include "../headers/stegin.h"


int stegin(char* image_source,char* texte_source,char* destEnfouir)
{
	Image image;
	Texte texte;
	int erreur;
	if((erreur=lireImage(image_source,&image))!=0)
		return erreur;

	if((erreur=lireText(texte_source,&texte))!=0)
	{
		return erreur;
	}

	if((erreur=enfouir(&image,texte))!=0)
	{
		return erreur;
	}

	if((erreur=ecrireImage(image,image_source,destEnfouir))!=0)
	{
		return erreur;
	}

	return 0;
}
