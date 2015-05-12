/*
** parse_file.c for parse_file in /home/barnea_v/rendu/MUL_2013_raytracer/src/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Wed Jun  4 14:34:50 2014 Barneaud Viveka
** Last update Sun Jun  8 23:18:19 2014 Laurent Fourrier
*/

#include	<sys/stat.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"parsing.h"
#include	"clustering.h"
#include	"scene.h"

void		init_scene_client(t_scene *scene)
{
  scene->width = 800;
  scene->height = 600;
  scene->object = NULL;
  scene->eye = NULL;
  scene->light = NULL;
}

void		get_coord(t_scene *sc, t_img_buff *cl)
{
  double	x;
  double	y;
  double	xend;
  int		i;

  x = cl->cli_num * (800 / cl->cli_max);
  xend = cl->cli_num + 1;
  xend = xend * (800 / cl->cli_max);
  cl->img = xmalloc_and_set(NULL, sizeof(int) * (200 * 600));
  i = 0;
  fprintf(stdout, "Calculating...\n");
  while (x <= xend)
    {
      y = 0;
      while (y <= 600)
  	{
  	  reset_eye(sc, x, y);
  	  render_pixel(sc, x, y);
  	  (cl->img)[i++] = sc->eye->intersection.color.value;
  	  y++;
  	}
      x++;
    }
  cl->size = i;
}

void		parse_file(const int sfd, const char *filename, t_img_buff *cl)
{
  int		fd;
  t_file	*file;
  t_scene	scene;
  char		*buff;
  int		len;

  if ((fd = open(filename, O_RDONLY)) < 0)
    exit(EXIT_FAILURE);
  file = fd_open_file(fd, FILE_R);
  init_scene_client(&scene);
  if (!parse_scene(&scene, file))
    exit(0);
  cl->img = NULL;
  buff = xmalloc_and_set(NULL, sizeof(*buff) * 10);
  fprintf(stdout, "Parsing done.\nWaiting for server...\n");
  if ((len = read(sfd, buff, 9)) < 0)
    return;
  buff[len] = 0;
  cl->cli_max = atoi(buff);
  get_coord(&scene, cl);
}
