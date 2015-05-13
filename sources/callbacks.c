/**
 * \file callbacks.c
 * \brief Définition des fonctions callbacks à utiliser par GTK
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 28 Avril 2015
 * 
 */

#include "../headers/callbacks.h"
#include "../headers/variables.h"

G_MODULE_EXPORT void gtk_widget_hide_apropos(GtkWidget *dialog, GtkWidget *param)
{
	        gtk_widget_hide(param);
}

G_MODULE_EXPORT void gtk_widget_show_apropos(GtkWidget *dialog, GtkWidget *param)
{
	        gtk_widget_show(param);
}

G_MODULE_EXPORT void gtk_widget_hide_dialog(GtkWidget *dialog, GtkWidget *param)
{
	gtk_widget_hide(dialog);
}

G_MODULE_EXPORT void imageSource_cb(GtkFileChooser *button, GtkWidget *file_selection)
{
	imageStegin=(char*)gtk_file_chooser_get_filename(button);
}
G_MODULE_EXPORT void texteSource_cb(GtkFileChooser *button, GtkWidget *file_selection)
{
	texte=(char*)gtk_file_chooser_get_filename(button);
}
G_MODULE_EXPORT void enfouirDest_cb(GtkFileChooser *button, GtkFileChooser *file_selection)
{
	destEnfouir=(char*)gtk_file_chooser_get_filename(button);
}
G_MODULE_EXPORT void enfouir_cb(GtkFileChooser *button, GtkMessageDialog *dialog)
{
	if(imageStegin!=NULL && texte!=NULL && destEnfouir!=NULL)
	{
		int erreur=stegin(imageStegin,texte,destEnfouir);

		switch(erreur)
		{
			case ERREUR_OUVERTURE_IMG:	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_OUVERTURE_IMG);
						   	break;
			case ERREUR_FORMAT_IMG: 	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_FORMAT_IMG);
							break;
			case ERREUR_OUVERTURE_TXT: 	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_OUVERTURE_TXT);
							break;
			case ERREUR_LECTURE_TXT:	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_LECTURE_TXT);
							break;
			case ERREUR_TAILLE_TXT:		gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_TAILLE_TXT);
							break;
			case ERREUR_ECRITURE_IMG:	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_ECRITURE_IMG);
							break;
			default: 			break;
		}
		
		if(erreur) gtk_widget_show((GtkWidget*)dialog);
	}
	else
	{
		if(imageStegin==NULL)
			gtk_message_dialog_format_secondary_text(dialog,IMAGE_SOURCE_ERROR);
		else if(texte==NULL)
                        gtk_message_dialog_format_secondary_text(dialog,TEXT_SOURCE_ERROR);
		else
			gtk_message_dialog_format_secondary_text(dialog,FOLDER_SOURCE_ERROR);

		gtk_widget_show((GtkWidget*)dialog);
	}
}


G_MODULE_EXPORT void imageDest_cb(GtkFileChooser *button, GtkWidget *file_selection)
{
	imageStegout=(char*)gtk_file_chooser_get_filename(button);
}
G_MODULE_EXPORT void extraireDest_cb(GtkFileChooser *button, GtkWidget *file_selection)
{
	destExtraire=(char*)gtk_file_chooser_get_filename(button);
}

G_MODULE_EXPORT void extraire_cb(GtkFileChooser *button, GtkMessageDialog *dialog)
{
	if(imageStegout!=NULL && destExtraire!=NULL)
	{
		int erreur=stegout(imageStegout,destExtraire);

		switch(erreur)
		{
			case ERREUR_OUVERTURE_IMG:	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_OUVERTURE_IMG);
							break;
			case ERREUR_FORMAT_IMG:		gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_FORMAT_IMG);
							break;
			case ERREUR_ECRITURE_TXT:	gtk_message_dialog_format_secondary_text(dialog,MSG_ERR_ECRITURE_TXT);
		}

		if(erreur) gtk_widget_show((GtkWidget*)dialog);
	}
	else
	{
		if(imageStegout==NULL)
			gtk_message_dialog_format_secondary_text(dialog,IMAGE_SOURCE_ERROR);
		else
			gtk_message_dialog_format_secondary_text(dialog,FOLDER_SOURCE_ERROR);

		gtk_widget_show((GtkWidget*)dialog);
	}
}
