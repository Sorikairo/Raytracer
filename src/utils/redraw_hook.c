/*
** redraw_hook.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Jun  5 13:47:43 2014 Laurent Fourrier
** Last update Thu Jun  5 16:42:02 2014 Laurent Fourrier
*/

#include <tmlxwin.h>

int		redraw_hook(void *vwin)
{
  t_mlxwin	*win;

  win = vwin;
  mlxwin_drawbuffer(win);
  return (0);
}
