/*
** add_to_list_text.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun Jun  1 16:03:30 2014 Kevin Fouhety
** Last update Sun Jun  8 13:37:46 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

int		check_line_text(char *line)
{
  int		i;
  int		n;

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
  if (n == 2 || n == 3)
    return (0);
  return (-1);
}

char		*add_to_text(char *line, t_text **list, int n)
{
  t_text	*elem;

  if (check_line_text(line) == -1)
    {
      if (*list != NULL)
	free_list_text(*list);
      write(1, "Error list text\n", 17);
      free(line);
      return (NULL);
    }
  if ((elem = malloc(sizeof (t_vertex))) == NULL)
    {
      write(1, "Error malloc\n", 13);
      exit(-1);
    }
  elem->number = n;
  elem->x = take_next_val(line);
  elem->y = take_next_val(line);
  elem->z = take_next_val(line);
  elem->preview = NULL;
  elem->next = *list;
  if (elem->next != NULL)
    elem->next->preview = elem;
  *list = elem;
  return ("ok");
}
