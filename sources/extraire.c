/**
 * \file extraire.c
 * \brief Définition de la fonction extraire
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
*/

#include "../headers/extraire.h"


void extraire(Image image, Texte *texte)
{
	texte->pathlen=0;
	texte->taille=0;
	texte->intervalle=0;
	texte->path=NULL;
	texte->tab=NULL;
	int i,j;

	Pixel* p = &((image.t2D)[0][0]);

//Extrait l'intervalle séparant 2 pixels consécutifs
        for(i=0;i<16;i++)
        {
                texte->intervalle <<= 1;
                if( *p & 0x01 ) texte->intervalle |= 0x01;
                p++;
        }

//Extrait la longueur du chemin d'accès du fichier .txt
	for(i=0;i<16;i++)
	{
		texte->pathlen <<= 1;
		if( *p & 0x01 ) texte->pathlen |= 0x01;
		p+=(texte->intervalle);
	}

//Alloue la mémoire pour texte->path
	texte->path=malloc(((texte->pathlen))*sizeof(char));
	memset(texte->path,'\0',texte->pathlen+1);
//Extrait la taille du fichier .txt
	for(i=0;i<16;i++)
        {
		texte->taille <<= 1;
                if( *p & 0x01 ) texte->taille |= 0x01;
                p+=(texte->intervalle);
        }

//Extrait le chemin d'accès du fichier .txt
	for(i=0;i<texte->pathlen;i++)
	{
		for(j=0;j<8;j++)
		{
			texte->path[i] <<= 1;
			if( *p & 0x01 ) texte->path[i] |= 0x01;
			p+=(texte->intervalle);
		}
	}
//Alloue la mémoire pour texte->tab
	texte->tab=malloc((texte->taille)*sizeof(char));
	memset(texte->tab,'\0',texte->taille);
                
//Extrait le contenu du fichier .txt
	for(i=0;i<texte->taille;i++)
        {
                for(j=0;j<8;j++)
                {
			texte->tab[i] <<= 1;
                        if( *p & 0x01 ) texte->tab[i] |= 0x01;
                        p+=(texte->intervalle);
                }
	}
}
