/*
** next_point_poly.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Jun  2 15:25:31 2014 Kevin Fouhety
** Last update Sun Jun  8 13:38:04 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

int     go_to_next_number(char *line, int i)
{
  int   n;

  n = i;
  while (line[n] != ' ' && line[n] != '\t' && line[n] != '\0')
    n++;
  while ((line[n] == ' ' || line[n] == '\t') && line[n] != '\0')
    n++;
  return (n);
}

t_name  *take_the_val(char *tmp)
{
  t_name        *ret;
  char          *tmp1;
  char          *tmp2;

  if ((ret = malloc(sizeof (t_name))) == NULL)
    {
      write(1, "Error malloc\n", 13);
      exit(-1);
    }
  ret->v = atof((tmp1 = get_the_nbr(tmp)));
  ret->vt = atof((tmp2 = get_the_second_nbr(tmp)));
  free(tmp1);
  free(tmp2);
  return (ret);
}

t_name          *take_next_point(char *line, int nb)
{
  static int    i = 0;
  char          *tmp;
  int           n;
  t_name        *ret;
  static int    k = 0;

  i = go_to_next_number(line, i);
  tmp = x_malloc(size_of_number(line, i) + 1);
  n = 0;
  while ((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == '/')
    {
      tmp[n] = line[i];
      i++;
      n++;
    }
  tmp[n] = '\0';
  if (++k % nb == 0)
    {
      i = 0;
      k = 0;
    }
  ret = take_the_val(tmp);
  return (ret);
}
