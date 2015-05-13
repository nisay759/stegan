/**
 * \file main.c
 * \brief Programme principal pour l'interface graphique
 * \author Tioual.Y, Yaakoubi.H, Chebihi.Z, Tagourti.H
 * \version 1.0
 * \date 27 Avril 2015
 * 
 */

#include "../headers/callbacks.h"

int main(int argc, char **argv)
{
	GtkBuilder *builder;
	GtkWidget  *window;
	GError     *error = NULL;

	/* Initialisation GTK+ */
	gtk_init( &argc, &argv );

	/* Create new GtkBuilder object */
	builder = gtk_builder_new();
	/* Chargement du fichier xml, on quitte si il y a une erreur */
	if( !gtk_builder_add_from_file(builder,"../GUI/Fenetre.glade", &error) )
	{
		g_warning("%s", error->message);
		g_free(error);
		return(1);
	}


	/* Get main window pointer from UI */
	window = GTK_WIDGET( gtk_builder_get_object(builder,"window") );

	/* On connecte les signaux */
	gtk_builder_connect_signals(builder,NULL);

	/* Destroy builder, since we don't need it anymore */
	g_object_unref( G_OBJECT(builder) );

	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show(window);

	/* Start main loop */
	gtk_main();
	return 0;
}
