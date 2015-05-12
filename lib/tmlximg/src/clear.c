/*
** clear.c for tmlximg in /home/fourri_l/Projects/lib/tmlximg
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 11:47:14 2014 Laurent Fourrier
** Last update Mon Feb  3 13:16:15 2014 Laurent Fourrier
*/

#include "tmlximg.h"

void	mlximg_clear(t_mlximg img, int color)
{
  mlximg_put_rect(img, new_imgcoord(0, 0), img.size, color);
}
