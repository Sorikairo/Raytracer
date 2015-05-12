/*
** add_to_list_point.c for raytracer in /home/fouhet_k/Perso/raytracer
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun May 25 02:02:27 2014 Kevin Fouhety
** Last update Sun Jun  8 13:37:33 2014 Kevin Fouhety
*/

#include "obj_parsing.h"

int	check_line(char *line)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (line[i] != '\0')
    {
      if ((line[i] >= '0' && line[i] <= '9') ||
	  line[i] == '-' || line[i] == '.')
	{
	  while ((line[i] >= '0' && line[i] <= '9') ||
		 line[i] == '-' || line[i] == '.')
	    i++;
	  n++;
	}
      if (line[i] != '\0')
	i++;
    }
  if (n == 3)
    return (0);
  return (-1);
}

int	size_of_number(char *line, int i)
{
  int	n;

  n = 0;
  while (line[i + n] != ' ' && line[i + n] != '\0')
    n++;
  return (n);
}

double	take_next_val(char *line)
{
  static int	i = 0;
  char		*tmp;
  int		n;
  double	ret;
  static int	k = 0;

  n = 0;
  while (line[i] != '-' && (line[i] < '0' ||
			    line[i] > '9') && line[i] != '\0')
    i++;
  tmp = x_malloc(size_of_number(line, i) + 1);
  while ((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == '.')
    {
      tmp[n] = line[i];
      i++;
      n++;
    }
  tmp[n] = '\0';
  if (++k % 3 == 0)
    i = 0;
  ret = atof(tmp);
  free(tmp);
  return (ret);
}

char	*add_to_vertex(char *line, t_vertex **list, int i)
{
  t_vertex	*elem;

  if (check_line(line) == -1)
    {
      if (*list != NULL)
      	free_list_v(*list);
      write(1, "Error list point\n", 17);
      free(line);
      return (NULL);
    }
  if ((elem = malloc(sizeof (t_vertex))) == NULL)
    {
      write(1, "Error malloc\n", 12);
      exit(-1);
    }
  elem->number = i;
  elem->x = take_next_val(line);
  elem->z = take_next_val(line);
  elem->y = take_next_val(line);
  elem->preview = NULL;
  elem->next = *list;
  if (elem->next != NULL)
    elem->next->preview = elem;
  *list = elem;
  return ("ok");
}
