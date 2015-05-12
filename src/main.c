/*
** main.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 02:19:41 2014 Laurent Fourrier
** Last update Sun Jun  8 23:24:41 2014 Barneaud Viveka
*/

#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include <tio.h>
#include <stdio.h>
#include "window.h"
#include "parsing.h"
#include "scene.h"
#include "clustering.h"

void		render_scene(t_scene *scene, t_launch_infos *infos)
{
  int		x;
  int		y;

  x = 0;
  while (x < 800)
    {
      y = 0;
      while (y < 600)
	{
	  reset_eye(scene, x, y);
	  render_pixel(scene, x, y);
	  gdk_image_put_pixel(infos->notebook->image, x, y,
			      scene->eye->intersection.color.value);
	  gtk_progress_set_value(GTK_PROGRESS(infos->prog_bar->bar),
				 ((double)x / 800.0) * 150.0);
	  gtk_widget_queue_draw(infos->notebook->scene);
	  y++;
	}
      x++;
    }
  gtk_widget_queue_draw(infos->notebook->notebook);
}

void		render_scene_serv(t_launch_infos *infos, int *nbr)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  x = 0;
  while (x < 800)
    {
      y = 0;
      while (y < 600)
	{
	  gdk_image_put_pixel(infos->notebook->image, x, y,
			      nbr[i]);
	  gtk_progress_set_value(GTK_PROGRESS(infos->prog_bar->bar),
				 ((double)x / 800.0) * 150.0);
	  gtk_widget_queue_draw(infos->notebook->scene);
	  y++;
	  i++;
	}
      x++;
    }
  gtk_widget_queue_draw(infos->notebook->notebook);
}

void		launch_rt(GtkWidget *widget, t_launch_infos *infos)
{
  t_file	*file;
  t_scene	scene;

  if (infos->path == NULL)
    open_func(NULL, infos);
  init_scene(&scene);
  file = open_file(infos->path, FILE_R);
  if (!parse_scene(&scene, file))
    exit(0);
  close_file(file);
  render_scene(&scene, infos);
}

int		main(int argc, char **argv)
{
  open_fstd();
  /* main_srv(atoi(argv[1]), argv[2]); */
  mainwindow_main(argc, argv);
  close_fstd();
  return (0);
}
