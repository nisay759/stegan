/**
 * \file test_stg.c
 * \brief Programme de teste pour les images .stg
 *
 * Le programme prend une image à l'extension .stg générée par le programme stegin, et affiche les informations relatives au fichier texte enfoui à l'écran
 * \author Tioual.Y
 * \date 8 mai 2015
 * \version 1.0
*/

#include "../headers/extraire.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage: %s image.stg\n",argv[0]);
		return 1;
	}
	Texte texte;
	Image image;
	char reponse;
	int i=0;
	lireImage(argv[1],&image);
	extraire(image,&texte);

	printf("Chemin d'acces du fichier:\t %s \n",texte.path);
	printf("Longueur du chemin d'acces:\t %d \n",texte.pathlen);
	printf("Taille du fichier:\t\t %d octets \n",texte.taille);
	printf("Intervalle d'espacement:\t %d \n",texte.intervalle);

	do
	{
		printf("Afficher le contenu du texte cache dans l'image ? (O/N): ");
		scanf("%c",&reponse);
		if(i) printf("Valeurs possibles: {o/O/n/N}\n");
		if(!i) i=1;
	}while(reponse!='O' && reponse!='o' && reponse!='n' && reponse!='N');

	if(reponse=='o' || reponse=='O')
		printf("Contenu du texte caché: \n%s\n",texte.tab);

	return 0;
}
