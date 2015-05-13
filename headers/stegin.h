/**
 *  * \file stegin.h
 *  * \brief Prototype de la fonction stegin
 *  * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 *  * \version 1.0
 *  * \date 27 Avril 2015
 */


#ifndef _STEGIN_H_
#define _STEGIN_H_ 1

#include "../headers/enfouir.h"


/**
 * \fn int stegin(char* img,char* txt,char* destFolder)
 * \brief Enfouit un fichier texte dans une image PGM et enregistre le résultat dans le dossier de destination choisit par l'utilisateur
 *
 * \param *img Chaine de caractères contenant le chemin d'accès de l'image PGM à utiliser
 * \param *txt Chaine de caractères contenant le chemin d'accès du fichier texte à utiliser
 * \param *destFolder Dossier de destination pour enregister l'image résultante
 *
 * \return Code d'erreur
 */

int stegin(char* img,char* txt,char* destFolder);

#endif
