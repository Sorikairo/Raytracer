/*
** bind_server.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Jun  7 16:39:24 2014 Laurent Fourrier
** Last update Sun Jun  8 16:06:05 2014 deffontaine kevin
*/

#include <gtk/gtk.h>
#include "window.h"
#include "clustering.h"

static void		server_callback(GtkWidget *wid, gpointer ptr)
{
  t_launch_infos	*infos;

  infos = ptr;
  (void)wid;
  main_srv(5942, infos);
}

void		bind_server(t_launch_infos *info, t_menu *menu)
{
  g_signal_connect(G_OBJECT(menu->server), "activate",
		   G_CALLBACK(server_callback), info);
}
