/*
** get_next_line.c for raytracer in /home/fouhet_k/Perso/raytracer
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun May 25 01:53:22 2014 Kevin Fouhety
** Last update Thu Jun  5 12:02:06 2014 Kevin Fouhety
*/

#include "obj_parsing.h"

int	size_of_next_line(char *str, int i)
{
  int	n;

  n = 0;
  while (str[i + n] != '\0' && str[i + n] != '\n')
    n++;
  return (n);
}

char	*get_next_line_obj(char *str)
{
  static int	i = 0;
  int		n;
  char		*ret;

  n = 0;
  while (str[i] == '\n' && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    {
      i = 0;
      return (NULL);
    }
  ret = x_malloc((size_of_next_line(str, i) + 1));
  while (str[i] != '\n' && str[i] != '\0')
    {
      ret[n] = str[i];
      i++;
      n++;
    }
  if (ret[n - 1] == ' ')
    while (ret[n - 1] == ' ')
      n--;
  ret[n] = '\0';
  return (ret);
}
