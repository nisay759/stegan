#ifndef _EXTRAIRE_H_
#define _EXTRAIRE_H_ 1

/**
 * \file extraire.h
 * \brief Prototypes des fonctions pour extraire l'information stockée dans l'image .pgm
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 2 Mars 2015
*/
#include "../headers/image.h"
#include "../headers/txt.h"

/**
 * \fn void extraire(Image image, Texte *texte)
 * \brief Extrait les infos enfouites dans image et les stock dans la structure pointée par *texte
 *
 * \param image Structure image contenant les infos
 * \param *texte Pointeur vers une structure Texte où il faut enregistrer les infos extraites
*/
void extraire(Image image, Texte *texte);






#endif
