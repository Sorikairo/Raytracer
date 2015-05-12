/*
** notebook.c for rt in /home/deffon_k/repo-raytracer
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Jun  6 17:30:06 2014 deffontaine kevin
** Last update Sun Jun  8 11:47:17 2014 deffontaine kevin
*/

#include "window.h"

void		creat_editor(t_menu *menu, t_launch_infos *infos)
{
  infos->notebook->tablabel = gtk_label_new("EDITOR");
  infos->notebook->scroll = gtk_scrolled_window_new(NULL, NULL);
  infos->notebook->table = gtk_table_new(3, 1, FALSE);
  gtk_container_add(GTK_CONTAINER(infos->notebook->scroll),
		    infos->notebook->text_view);
  gtk_table_attach_defaults(GTK_TABLE(infos->notebook->table),
			    infos->notebook->scroll, 0, 1, 0, 1);
  gtk_notebook_append_page(GTK_NOTEBOOK(infos->notebook->notebook),
			   infos->notebook->table, infos->notebook->tablabel);
  g_signal_connect(G_OBJECT(menu->open), "activate",
		   G_CALLBACK(open_func), infos);
  g_signal_connect(G_OBJECT(menu->save_as), "activate",
		   G_CALLBACK(save_as_func), infos->notebook->text_view);
  g_signal_connect(G_OBJECT(menu->run), "activate",
  		   G_CALLBACK(launch_rt), infos);
}

void		creat_notebook(t_init *init, t_menu *menu, t_launch_infos *infos)
{
  infos->notebook->notebook = gtk_notebook_new();
  gtk_box_pack_start(GTK_BOX(init->vbox),
		     infos->notebook->notebook, TRUE, TRUE, 0);
  infos->notebook->text_view = gtk_text_view_new();
  infos->notebook->text_buffer = gtk_text_view_get_buffer(
							  GTK_TEXT_VIEW(infos->notebook->text_view));
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(infos->notebook->text_view),
			      GTK_WRAP_WORD);
  creat_editor(menu, infos);
  infos->notebook->tablabel = gtk_label_new("SCENE");
  infos->notebook->image = gdk_image_new(GDK_IMAGE_NORMAL,
					 gdk_visual_get_system(), 800, 600);
  infos->notebook->scene = gtk_image_new_from_image(infos->notebook->image,
						    NULL);
  gtk_notebook_append_page(GTK_NOTEBOOK(infos->notebook->notebook),
  			   infos->notebook->scene, infos->notebook->tablabel);
  gtk_notebook_set_tab_pos(GTK_NOTEBOOK(infos->notebook->notebook),
			   GTK_POS_TOP);
  gtk_notebook_set_scrollable(GTK_NOTEBOOK(infos->notebook->notebook), TRUE);
}
