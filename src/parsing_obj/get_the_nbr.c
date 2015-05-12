/*
** get_the_nbr.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue May 27 11:13:54 2014 Kevin Fouhety
** Last update Tue Jun  3 18:21:30 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

char    *get_the_nbr(char *tmp)
{
  char  *ret;
  int   i;

  i = 0;
  ret = x_malloc(size_of_number(tmp, 0) + 1);
  while (tmp[i] != '/' && tmp[i] != '\0')
    {
      ret[i] = tmp[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

char    *get_the_second_nbr(char *tmp)
{
  char  *ret;
  int   i;
  int	n;

  n = 0;
  i = 0;
  while (tmp[i] != '/' && tmp[i] != '\0')
    i++;
  while (tmp[i] == '/')
    i++;
  ret = x_malloc(size_of_number(tmp, i) + 1);
  while (tmp[i + n] != '\0')
    {
      ret[n] = tmp[i + n];
      n++;
    }
  ret[n] = '\0';
  free(tmp);
  return (ret);
}
