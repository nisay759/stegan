#ifndef _TXT_H_
#define _TXT_H_ 1

/**
 * \file txt.h
 * \brief Définition de la structure Texte et des fonctions qui agissent dessus
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 26 Février 2015
*/

#include <stdint.h>
#include <string.h>

/**
 * \struct Texte
 * \brief Structure contenant les informations relatives à un fichier .txt
*/
typedef struct
{
	uint16_t intervalle; /*!< Intervalle séparant deux pixels consécutifs */
	uint16_t pathlen; /*!< Longueur du chemin d'accès absolu du fichier .txt */
	uint16_t taille; /*!< Taille en octets du fichier .txt */
	char *path; /*!< Chemin d'accès absolu du fichier .txt */
	
	char *tab; /*!< Contenu du fichier .txt */
} Texte;

/**
 * \fn int lireText(char *nomFichier, Texte* texte)
 * \brief Récupère les informations relatives au fichier .txt et les stock dans une structure Texte
 *
 * \param nomFichier Nom du fichier à traiter
 * \param texte Pointeur sur une structure Texte qui recevrea les informations relatives au fichier texte
 * \return Code d'erreur
*/
int lireText(char* nomFichier, Texte* texte);

/**
 * \fn void ecrireTexte(Texte texte, char *nomFichier)
 * \brief Ecrit le contenu stocké dans la strucure Texte dans un fichier .txt
 *
 * \param texte Structure Texte à stocker
 * \param destDossier Dossier de destination pour enregister le fichier texte
 * \return Code d'erreur
*/
int ecrireTexte(Texte texte,char* destDossier);

#endif
