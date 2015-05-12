/*
** open.c for rt in /home/deffon_k/repo-raytracer
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Jun  6 13:57:45 2014 deffontaine kevin
** Last update Sun Jun  8 13:13:00 2014 deffontaine kevin
*/

#include "window.h"
#include <tutils.h>

void		open_gfile(const gchar *file_name, GtkTextView *text_view)
{
  gchar		*contents;
  gchar		*utf8;
  GtkTextIter	iter;
  GtkTextBuffer	*text_buffer;

  contents = NULL;
  utf8 = NULL;
  text_buffer = NULL;
  g_return_if_fail(file_name && text_view);
  if (g_file_get_contents(file_name, &contents, NULL, NULL))
    {
      docs.actif = g_malloc(sizeof(*docs.actif));
      docs.actif->path = g_strdup(file_name);
      docs.actif->text_view = text_view;
      docs.actif->save = TRUE;
      text_buffer = gtk_text_view_get_buffer(text_view);
      gtk_text_buffer_get_iter_at_line(text_buffer, &iter, 0);
      utf8 = g_locale_to_utf8(contents, -1, NULL, NULL, NULL);
      g_free(contents);
      contents = NULL;
      gtk_text_buffer_insert(text_buffer, &iter, utf8, -1);
      g_free(utf8);
      utf8 = NULL;
    }
}

void			open_func(GtkWidget *widget, gpointer user_data)
{
  t_launch_infos	*infos;
  GtkWidget		*dialog;
  gchar			*file_name;

  infos = user_data;
  dialog = NULL;
  file_name = NULL;
  dialog = gtk_file_chooser_dialog_new("Open file", NULL,
				       GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL,
				       GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      infos->path = utl_strcpy(file_name);
      infos->notebook->text_buffer = gtk_text_buffer_new(NULL);
      gtk_text_view_set_buffer(GTK_TEXT_VIEW(infos->notebook->text_view),
			       infos->notebook->text_buffer);
      open_gfile(file_name, GTK_TEXT_VIEW(infos->notebook->text_view));
      g_free(file_name);
      file_name = NULL;
    }
  gtk_widget_destroy(dialog);
  (void)widget;
}
