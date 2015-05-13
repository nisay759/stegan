#ifndef _ENFOUIR_H_
#define _ENFOUIR_H_ 1

/**
 * \file enfouir.h
 * \brief Prototype de la fonction enfouir
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 27 Février 2015
*/

#include "image.h"
#include "txt.h"

/**
 * \fn int enfouir(Image* image, Texte* texte)
 * \brief Enfouit une structure Texte dans une structure Image
 *
 * La fonction permet aussi de tester si c'est bien possible d'enfouir texte dans image, en fonction comparant la taille de l'image d'une part, et la taille du fichier texte ainsi que la longueur de son chemin d'accès absolu d'une autre part
 * \param image Pointeur vers la structure Image à utiliser
 * \param texte Structure Texte à enfouir
 * \return Code d'erreur
*/
int enfouir(Image* image, Texte texte);


#endif
