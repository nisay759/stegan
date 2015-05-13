/**
 * \file stegout.h
 * \brief Prototype de la fonction stegout
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 28 Avril 2015
 */

#ifndef _STEGOUT_H_
#define _STEGOUT_H_ 1

/**
 * \fn int stegout(char* imageSource, char* destDossier)
 * \brief Extrait le fichier texte texte enfoui dans l'image par un appel antérieur de la fonction stegin
 *
 * \param imageSource Chaine de caractère contenant le chemin d'accès de l'image à utiliser par la fonction stegout
 * \param destDossier Chaine de caractère contenant le chemin d'accès du dossier où enregistrer le fichier texte extrait
 * \return Code d'erreur
 */
int stegout(char* imageSource, char* destDossier);


#endif
