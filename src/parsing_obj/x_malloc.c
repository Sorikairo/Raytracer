/*
** x_malloc.c for raytracer in /home/fouhet_k/Perso/raytracer
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun May 25 03:01:39 2014 Kevin Fouhety
** Last update Sun Jun  8 13:24:03 2014 Kevin Fouhety
*/

#include "obj_parsing.h"

char		*x_malloc(int i)
{
  char		*ret;

  if ((ret = malloc(i)) == NULL)
    {
      write(1, "Error on malloc\n", 16);
      exit(0);
    }
  return (ret);
}

t_poly		*x_malloc_poly(int i)
{
  t_poly	*ret;

  if ((ret = malloc(i)) == NULL)
    {
      write(1, "Error on malloc\n", 16);
      exit(0);
    }
  return (ret);
}
