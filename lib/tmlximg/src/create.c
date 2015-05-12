/*
** create.c for tmlximg in /home/fourri_l/Projects/lib/tmlximg
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 11:33:56 2014 Laurent Fourrier
** Last update Mon Feb  3 13:17:14 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <mlx.h>
#include "tmlximg.h"

t_mlximg	mlximg_create(void *mlx, int width, int height)
{
  t_mlximg	rtn;

  if ((rtn.ptr = mlx_new_image(mlx, width, height)) != NULL)
    {
      rtn.size.x = width;
      rtn.size.y = height;
      rtn.data = mlx_get_data_addr(rtn.ptr, &rtn.bpp, &rtn.linesize,
				   &rtn.endianness);
    }
  return (rtn);
}
