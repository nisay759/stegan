/**
 * \file txt.c
 * \brief Définition des fonctions de gestion de la structure Texte
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include "../headers/txt.h"
#include "../headers/macros.h"

int lireText (char *nomFichier, Texte* texte)
{
	FILE *fichier;
	int fd;
	struct stat status;

	if((fichier=fopen(nomFichier,"r"))==NULL)
	{
		fprintf(stderr,"Erreur de lecture du fichier texte.\n");
		return ERREUR_OUVERTURE_TXT;
	}

	fd=fileno(fichier);
//Récupère les informations relatives au fichier .txt
	if(fstat(fd,&status)<0)
	{
		fprintf(stderr,"Erreur lors de la recuperation des informations du fichier texte.\n");
		return ERREUR_LECTURE_TXT;
	}
//Teste si la taille du fichier.txt peut tenir sur 2 octets
	if(status.st_size>65535)
	{
		fprintf(stderr,"Erreur: Taille du fichier texte trop grande.\n");
		return ERREUR_TAILLE_TXT;
	}

	//Récupère la taille du fichier .txt en octets
	texte->taille=(status.st_size);
//Alloue de la mémoire pour acceuillir le contenu du fichier .txt
	texte->tab=malloc((texte->taille)*sizeof(char));
//Récupère le chemin absolu du fichier .txt
	texte->path=realpath(nomFichier,NULL);
//Récupère la longueur du chemin absolu du fichier .txt
	texte->pathlen=strlen(texte->path);
//Met l'intervalle à 0
	texte->intervalle=0;
//Récupère le contenu du fichier .txt
	fread(texte->tab,sizeof(char),(texte->taille),fichier);
//Désalloue le pointeur vers le fichier
	fclose(fichier);

	return 0;
}

int ecrireTexte(Texte texte,char* dossier)
{
	FILE *fichier;
	int i=strlen(texte.path);
	int j=0;
	char nom[40];
	char* cheminAbsolu;

	if((cheminAbsolu=(char*)malloc(140*sizeof(char)))==NULL)
		return ERREUR_ECRITURE_TXT;

	cheminAbsolu[0]='\0';
	cheminAbsolu=strcat(cheminAbsolu,dossier);
	cheminAbsolu=strcat(cheminAbsolu,"/");

	while(texte.path[i]!='/') i--;
	i++;

	while(texte.path[i]!='\0')
	{
		nom[j]=texte.path[i];
		i++;
		j++;
	}

	nom[j]='\0';

	cheminAbsolu=strcat(cheminAbsolu,nom);

	if( (fichier=fopen(cheminAbsolu,"w") ) == NULL)
	{
		fprintf(stderr,"Erreur d\'ecriture du fichier texte\n");
		return ERREUR_ECRITURE_TXT;
	}

	fwrite(texte.tab, sizeof(char) , texte.taille, fichier);

	free(cheminAbsolu);
	fclose(fichier);

	return 0;
}
