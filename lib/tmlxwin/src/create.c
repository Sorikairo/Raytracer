/*
** create.c for tmlxwin in /home/fourri_l/Projects/lib/tmlxwin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 15:10:41 2014 Laurent Fourrier
** Last update Mon Feb  3 16:12:01 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <mlx.h>
#include "tmlxwin.h"

t_mlxwin	mlxwin_create(void *mlx, int width, int height, char *title)
{
  t_mlxwin	rtn;

  rtn.mlx = mlx;
  if ((rtn.win = mlx_new_window(mlx, width, height, title)) != NULL)
    {
      rtn.buf = 0;
      rtn.screen = mlximg_create(mlx, width, height);
      if (rtn.screen.ptr == NULL)
	rtn.win = NULL;
    }
  return (rtn);
}
