/*
** put_pixel.c for tmlximg in /home/fourri_l/Projects/lib/tmlximg
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 11:40:29 2014 Laurent Fourrier
** Last update Mon Feb  3 13:18:10 2014 Laurent Fourrier
*/

#include "tmlximg.h"

void	put_pixel_le(char *px, int color)
{
  px[0] = (color >> 24) & 0xFF;
  px[1] = (color >> 16) & 0xFF;
  px[2] = (color >> 8) & 0xFF;
  px[3] = color & 0xFF;
}

void	put_pixel_be(char *px, int color)
{
  px[0] = color & 0xFF;
  px[1] = (color >> 8) & 0xFF;
  px[2] = (color >> 16) & 0xFF;
  px[3] = (color >> 24) & 0xFF;
}

void	mlximg_put_pixel(t_mlximg img, t_imgcoord pos, int color)
{
  int	arrpos;

  if ((pos.x > 0 && pos.x < img.size.x) && (pos.y > 0 && pos.y < img.size.y))
    {
      arrpos = (pos.y * img.linesize) + (pos.x * (img.bpp / 8));
      if (img.endianness)
	put_pixel_le(img.data + arrpos, color);
      else
	put_pixel_be(img.data + arrpos, color);
    }
}
