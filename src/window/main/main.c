/*
** main.c for rt in /home/deffon_k
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Jun  6 11:53:44 2014 deffontaine kevin
** Last update Sun Jun  8 12:46:11 2014 Laurent Fourrier
*/

#include <tutils.h>
#include "window.h"

t_docs docs = {NULL, NULL};

void		init_window(int argc, char **argv, t_init *init, t_launch_infos *infos)
{
  gtk_init(&argc, &argv);
  init->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_maximize(GTK_WINDOW(init->window));
  init->vbox = gtk_vbox_new(FALSE, 1);
  infos->hbox = gtk_hbox_new(FALSE, 1);
  gtk_container_add(GTK_CONTAINER(init->window), init->vbox);
}

int			mainwindow_main(int argc, char **argv)
{
  t_menu		menu;
  t_init		init;
  t_prog_bar		prog_bar;
  t_notebook		notebook;
  t_launch_infos	infos;

  infos.prog_bar = &prog_bar;
  infos.notebook = &notebook;
  init_window(argc, argv, &init, &infos);
  infos.path = (argc > 1) ? utl_strcpy(argv[1]) : NULL;
  creat_menu(&menu, &init);
  creat_notebook(&init, &menu, &infos);
  creat_prog_bar(&init, &infos);
  gtk_box_pack_start(GTK_BOX(infos.hbox),
		       infos.prog_bar->align, TRUE, TRUE, 0);
  gtk_container_add(GTK_CONTAINER(infos.prog_bar->align), infos.prog_bar->bar);
  infos.notebook->label = gtk_label_new("Open then run a '.tds' file");
  gtk_box_pack_start(GTK_BOX(infos.hbox),
		       infos.notebook->label, FALSE, FALSE, 20);
  g_signal_connect_swapped(G_OBJECT(init.window), "destroy",
			  G_CALLBACK(gtk_main_quit), G_OBJECT(init.window));
  bind_server(&infos, &menu);
  gtk_widget_show_all(init.window);
  gtk_main();
  return (0);
}
