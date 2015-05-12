/*
** drawbuffer.c for tmlxwin in /home/fourri_l/Projects/lib/tmlxwin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 15 16:36:57 2014 Laurent Fourrier
** Last update Sat Mar 15 16:37:42 2014 Laurent Fourrier
*/

#include <mlx.h>
#include "tmlxwin.h"

void	mlxwin_drawbuffer(t_mlxwin *window)
{
  mlx_put_image_to_window(window->mlx, window->win, window->screen.ptr, 0, 0);
}
