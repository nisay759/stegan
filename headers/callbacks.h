#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_ 1

/**
 * \file callbacks.h
 * \brief En-tête des fonctions callbacks utilisées par les appels de GTK
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 28 Avril 2015
 * 
 */

#include <gtk/gtk.h>
#include "stegin.h"
#include "stegout.h"

/**
 * \fn G_MODULE_EXPORT void gtk_widget_hide_apropos(GtkWidget *widget, GtkWidget *dialog)
 * \brief Permet de cacher la boîte de dialogue "A propos"
 *
 * \param widget Widget ayant émis le signal à gérer par la fonction
 * \param dialog Boite de dialogue "A propos"
 */
G_MODULE_EXPORT void gtk_widget_hide_apropos(GtkWidget *widget, GtkWidget *dialog);

/**
 * \fn G_MODULE_EXPORT void gtk_widget_show_apropos(GtkWidget *widget, GtkWidget *dialog)
 * \brief Permet d'afficher la boîte de dialogue "A propos"
 *
 * \param widget Widget ayant émis le signal à gérer par la fonction
 * \param dialog Boite de dialogue "A propos"
 */
G_MODULE_EXPORT void gtk_widget_show_apropos(GtkWidget *widget, GtkWidget *dialog);

/**
 * \fn G_MODULE_EXPORT void gtk_widget_hide_dialog(GtkWidget *dialog, GtkWidget *param)
 * \brief Permet de cacher la boîte de dialogue affichée lors de l'erreur ou le succès d'une tâche
 *
 * \param dialog Pointeur vers la boîte de dialog à cacher
 * \param param Paramètre optionel (non utilisé dans cette fonction)
*/
G_MODULE_EXPORT void gtk_widget_hide_dialog(GtkWidget *dialog, GtkWidget *param);

/**
 * \fn G_MODULE_EXPORT void imageSource_cb(GtkFileChooser *button, GtkWidget *file_selection)
 * \brief Récupère le chemin absolu de l'image source à utiliser pour l'opération d'enfouissement
 *
 * \param button Boutton de type GtkFileChooser ayant émis le signal
 * \param param Paramètre optionel (non utilisé dans cette fonction)
*/
G_MODULE_EXPORT void imageSource_cb(GtkFileChooser *button, GtkWidget *param);

/**
 * \fn G_MODULE_EXPORT void texteSource_cb(GtkFileChooser *button, GtkWidget *param)
 * \brief Récupère le chemin absolu du fichier texte à utiliser pour l'opération d'enfouissement
 *
 * \param button Boutton de type GtkFileChooser ayant émis le signal
 * \param param Paramètre optionel (non utilisé dans cette fonction)
*/
G_MODULE_EXPORT void texteSource_cb(GtkFileChooser *button, GtkWidget *param);

/**
 * \fn G_MODULE_EXPORT void enfouirDest_cb(GtkFileChooser *button, GtkFileChooser *param)
 * \brief Récupère le chemin absolu du dossier à recevoir le résultat de l'opération d'enfouissement
 *
 * \param button Boutton de type GtkFileChooser ayant émis le signal
 * \param param Paramètre optionel (non utilisé dans cette fonction)
*/
G_MODULE_EXPORT void enfouirDest_cb(GtkFileChooser *button, GtkFileChooser *param);

/**
 * \fn G_MODULE_EXPORT void enfouir_cb(GtkFileChooser *button, GtkMessageDialog *dialog)
 * \brief Procède à l'opération d'enfouissement
 *
 * Teste également si l'utilisateur a bien rempli tout les champs demandés. Dans le cas contraire, une boîte de dialogue est affichée avec un message d'erreur correspondant
 *
 * \param button Boutton ayant émis le signal
 * \param dialog Boîte de dialogue à utiliser pour afficher le message d'erreur
*/
G_MODULE_EXPORT void enfouir_cb(GtkFileChooser *button, GtkMessageDialog *dialog);

/**
 * \fn G_MODULE_EXPORT void imageDest_cb(GtkFileChooser *button, GtkWidget *file_selection)
 * \brief Récupère le chemin absolu de l'image source à utiliser pour l'opération d'extraction
 *
 * \param button Boutton de type GtkFileChooser ayant émis le signal
 * \param param Paramètre optionel (non utilisé dans cette fonction)
*/
G_MODULE_EXPORT void imageDest_cb(GtkFileChooser *button, GtkWidget *file_selection);

/**
 * \fn G_MODULE_EXPORT void extraireDest_cb(GtkFileChooser *button, GtkWidget *file_selection)
 * \brief Récupère le chemin absolu du dossier à recevoir le fichier texte issu de l'opération d'enfouissement
 *
 * \param button Boutton de type GtkFileChooser ayant émis le signal
 * \param param Paramètre optionel (non utilisé dans cette fonction)
*/
G_MODULE_EXPORT void extraireDest_cb(GtkFileChooser *button, GtkWidget *file_selection);

/**
 * \fn G_MODULE_EXPORT void extraire_cb(GtkFileChooser *button, GtkMessageDialog *dialog)
 * \brief Procède à l'opération d'extraction
 *
 * Teste également si l'utilisateur a bien rempli tout les champs demandés. Dans le cas contraire, une boîte de dialogue est affichée avec un message d'erreur correspondant
 *
 * \param button Boutton ayant émis le signal
 * \param dialog Boîte de dialogue à utiliser pour afficher le message d'erreur
*/
G_MODULE_EXPORT void extraire_cb(GtkFileChooser *button, GtkMessageDialog *dialog);

#endif
