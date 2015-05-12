/*
** check_poly.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun Jun  1 07:38:31 2014 Kevin Fouhety
** Last update Tue Jun  3 12:55:38 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

int             check_poly(char *line)
{
  int           i;
  int           n;

  i = 0;
  n = 0;
  while (line[i] != '\0')
    {
      if ((line[i] >= '0' && line[i] <= '9') || line[i] == '/')
        {
          while ((line[i] >= '0' && line[i] <= '9') || line[i] == '/')
            i++;
          n++;
        }
      if (line[i] != '\0')
        i++;
    }
  if (n == 3 || n == 4)
    return (n);
  return (-1);
}
