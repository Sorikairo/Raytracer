/*
** tmlxwin.h for tmlxwin in /home/fourri_l/Projects/lib/tmlxwin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 13:27:17 2014 Laurent Fourrier
** Last update Sat Mar 15 16:36:41 2014 Laurent Fourrier
*/

#ifndef TMLXWIN_H_
# define TMLXWIN_H_

#include <tmlximg.h>

typedef struct	s_mlxwin
{
  void		*mlx;
  void		*win;
  int		buf;
  t_mlximg	screen;
  t_mlximg	buf_first;
  t_mlximg	buf_second;
}		t_mlxwin;

t_mlxwin	mlxwin_create(void *mlx, int width, int height, char *title);

void		mlxwin_drawbuffer(t_mlxwin *window);
void		mlxwin_swapbuffers(t_mlxwin *window);

void		mlxwin_destroy(t_mlxwin *window);

#endif
