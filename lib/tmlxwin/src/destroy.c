/*
** destroy.c for tmlxwin in /home/fourri_l/Projects/lib/tmlxwin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 15:25:44 2014 Laurent Fourrier
** Last update Fri Mar 14 13:47:41 2014 Laurent Fourrier
*/

#include <mlx.h>
#include "tmlxwin.h"

void	mlxwin_destroy(t_mlxwin *window)
{
  mlx_destroy_window(window->mlx, window->win);
}
