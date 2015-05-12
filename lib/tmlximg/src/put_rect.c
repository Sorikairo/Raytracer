/*
** put_rect.c for tmlximg in /home/fourri_l/Projects/lib/tmlximg
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 11:57:11 2014 Laurent Fourrier
** Last update Mon Feb  3 13:15:24 2014 Laurent Fourrier
*/

#include "tmlximg.h"

void	mlximg_put_rect(t_mlximg img, t_imgcoord pos, t_imgcoord size,
			int color)
{
  int	x;
  int	y;

  x = 0;
  while (x < size.x)
    {
      y = 0;
      while (y < size.y)
	{
	  mlximg_put_pixel(img, new_imgcoord(pos.x + x, pos.y + y), color);
	  y++;
	}
      x++;
    }
}
