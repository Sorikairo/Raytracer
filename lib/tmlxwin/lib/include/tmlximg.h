/*
** tmlximg.h for tmlximg in /home/fourri_l/Projects/lib/tmlximg
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 11:32:07 2014 Laurent Fourrier
** Last update Mon Feb  3 11:56:59 2014 Laurent Fourrier
*/

#ifndef TMLXIMG_H_
# define TMLXIMG_H_

typedef struct	s_imgcoord
{
  int		x;
  int		y;
}		t_imgcoord;

typedef struct	s_mlximg
{
  void		*ptr;
  char		*data;
  t_imgcoord	size;
  int		bpp;
  int		linesize;
  int		endianness;
}		t_mlximg;

t_mlximg	mlximg_create(void *mlx, int width, int height);

void		mlximg_put_pixel(t_mlximg img, t_imgcoord pos, int color);
void		mlximg_put_rect(t_mlximg img, t_imgcoord pos, t_imgcoord size,
				int color);
void		mlximg_clear(t_mlximg img, int color);

t_imgcoord	new_imgcoord(int x, int y);

#endif
