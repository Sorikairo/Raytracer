/*
** save_as.c for rt in /home/deffon_k/repo-raytracer
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Sat Jun  7 11:24:59 2014 deffontaine kevin
** Last update Sun Jun  8 11:44:29 2014 deffontaine kevin
*/

#include "window.h"

void		save(GtkTextBuffer *text_buffer, GtkTextIter start, GtkTextIter end)
{
  FILE		*file;
  gchar		*contents;
  gchar		*locale;

  if (docs.actif->path)
    {
      file = fopen(docs.actif->path, "w");
      if (file)
	{
	  text_buffer = gtk_text_view_get_buffer(docs.actif->text_view);
	  gtk_text_buffer_get_bounds(text_buffer, &start, &end);
	  contents = gtk_text_buffer_get_text(text_buffer, &start, &end, FALSE);
	  locale = g_locale_from_utf8(contents, -1, NULL, NULL, NULL);
	  g_free(contents);
	  contents = NULL;
	  fprintf(file, "%s", locale);
	  g_free(locale);
	  locale = NULL;
	  fclose(file);
	  file = NULL;
	  docs.actif->save = TRUE;
	}
    }
}

void		save_choose()
{
  GtkWidget	*dialog;

  dialog = NULL;
  dialog = gtk_file_chooser_dialog_new("Save file", NULL,
				       GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				       GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    docs.actif->path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
  gtk_widget_destroy(dialog);
}

void		save_file(GtkWidget *widget, gpointer user_data)
{
  GtkTextIter	start;
  GtkTextIter	end;
  GtkTextBuffer	*text_buffer;

  text_buffer = NULL;
  if (docs.actif)
    {
      if (!docs.actif->save)
	{
	  if (!docs.actif->path)
	    save_choose();
	  save(text_buffer, start, end);
	}
    }
  (void)widget;
  (void)user_data;
}

void		save_as_func(GtkWidget *widget, gpointer user_data)
{
  t_actif	temp;

  if (docs.actif)
    {
      temp = *docs.actif;
      docs.actif->path = NULL;
      docs.actif->save = FALSE;
      save_file(widget, user_data);
      if (!docs.actif->save)
	*docs.actif = temp;
    }
  else
    {
      docs.actif = g_malloc(sizeof(*docs.actif));
      docs.actif->path = g_strdup("/home");
      docs.actif->text_view = user_data;
      docs.actif->save = TRUE;
      save_as_func(widget, user_data);
    }
}
