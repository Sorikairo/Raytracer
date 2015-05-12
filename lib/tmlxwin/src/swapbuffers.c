/*
** swapbuffers.c for tmlxwin in /home/fourri_l/Projects/lib/tmlxwin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 16:11:30 2014 Laurent Fourrier
** Last update Sat Mar 15 16:38:03 2014 Laurent Fourrier
*/

#include <mlx.h>
#include "tmlxwin.h"

void	mlxwin_swapbuffers(t_mlxwin *window)
{
  mlxwin_drawbuffer(window);
  window->buf = !window->buf;
  window->screen = (window->buf) ? window->buf_first : window->buf_second;
}
