/**
 * \file test_txt.c
 * \brief Programme de test pour le module "txt"
 *
 * Le programme prend en paramètre un fichier texte et affiche à l'écran, dans l'ordre, sa taille en octets, son chemin d'accès, la longueur de son chemin d'accès et son contenu
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \date 4 mars 2015
 * \version 1.0
*/


#include <stdio.h>
#include <stdlib.h>
#include "../headers/txt.h"

int main(int argc, char **argv)
{
	if(argc!=2)
	{
		fprintf(stderr,"Usage: %s texte.txt\n", argv[0]);
		return EXIT_FAILURE;
	}
	Texte texte;
	lireText(argv[1],&texte);

	printf("Taille du fichier texte: %d octets.\n", texte.taille);
	printf("Chemin d'acces du texte: %s\n", texte.path);
	printf("Longueur du chemin d'acces du texte: %d\n", texte.pathlen);
	printf("Contenu du fichier texte: %s\n", texte.tab);

	return EXIT_SUCCESS;


}
