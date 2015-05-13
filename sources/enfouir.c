/**
 * \file enfouir.c
 * \brief Définition de la fonciton permettant d'enfouir une structure Texte dans une structure Image
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
*/


#include "../headers/enfouir.h"


int enfouir(Image *image, Texte texte)
{
	int totalTxt=(6+strlen(texte.tab)+strlen(texte.path))*8;
	int totalPixels=(image->nbLignes)*(image->nbColonnes);

	
	Pixel* p = &((image->t2D)[0][0]);

//Teste si c'est possible d'enfouir le fichier .txt dans l'image .pgm
        if(totalTxt > totalPixels)
        {
                fprintf(stderr,"Erreur: Image trop petite. Réessayez avec une image plus grande.\n");
                return ERREUR_TAILLE_TXT;
        }

	int i,j;
	char c;

	while(totalTxt*(texte.intervalle+1) < (totalPixels-16)) (texte.intervalle)++;

//Enfouit l'intervalle qui devrait séparer deux pixels consécutifs
        for(i=15;i>=0;i--)
        {
                if((texte.intervalle)&(0x01<<i)) *p |= 0x01;
                else *p &= 0xfe;
                p++;
        }


//Enfouit la longueur du chemin absolu du fichier .txt dans l'image .pgm
	for(i=15;i>=0;i--)
	{
		if((texte.pathlen)&(0x01<<i)) *p |= 0x01;
		else *p &= 0xfe;
		p+=texte.intervalle;
	}

//Enfouit la taille du fichier .txt dans l'image .pgm
	for(i=15;i>=0;i--)
        {
                if((texte.taille)&(0x01<<i)) *p |= 0x01;
                else *p &= 0xfe;
                p+=texte.intervalle;
        }

//Enfouit le chemin d'accès du fichier .txt dans l'image .pgm
	for(i=0;i<strlen(texte.path);i++)
	{
		c=texte.path[i];
		for(j=7;j>=0;j--)
		{
			if(c&(0x01<<j)) *p |= 0x01;
			else *p &= 0xfe;
			p+=texte.intervalle;
		}
	}

//Enfouit le contenu du fichier .txt dans l'image .pgm
	for(i=0;i<texte.taille;i++)
	{
		c=texte.tab[i];
		for(j=7;j>=0;j--)
		{
			if(c&(0x01<<j)) *p |= 0x01;
			else *p &= 0xfe;
			p+=texte.intervalle;
		}
	}
	return 0;
}
