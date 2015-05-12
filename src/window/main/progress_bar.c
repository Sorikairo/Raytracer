/*
** progress_bar.c for rt in /home/deffon_k/repo-raytracer
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Jun  6 17:31:11 2014 deffontaine kevin
** Last update Sun Jun  8 11:48:52 2014 deffontaine kevin
*/

#include "window.h"

void		creat_prog_bar(t_init *init, t_launch_infos *infos)
{
  gtk_box_pack_start(GTK_BOX(init->vbox), infos->hbox, FALSE, FALSE, 0);
  infos->prog_bar->align = gtk_alignment_new(0.005, 0.5, 0.1, 0);
  infos->prog_bar->adj = (GtkAdjustment*)gtk_adjustment_new(0,
							    1, 150, 0, 0, 0);
  infos->prog_bar->bar = gtk_progress_bar_new_with_adjustment(
							      infos->prog_bar->adj);
  gtk_progress_bar_set_bar_style(GTK_PROGRESS_BAR(infos->prog_bar->bar),
				 GTK_PROGRESS_CONTINUOUS);
}
