/*
** main.c for raytracer in /home/fouhet_k/Perso/raytracer
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun May 25 00:54:03 2014 Kevin Fouhety
** Last update Sat Jun  7 22:41:33 2014 Kevin Fouhety
*/

#include "obj_parsing.h"
# include <stdio.h>

int		my_strncmp(char *line, char *cmp, int nb)
{
  int   i;

  i = 0;
  while (i < nb && line[i] != '\0')
    {
      if (line[i] != cmp[i])
        return (-1);
      i++;
    }
  return (0);
}

t_object	*add_to_list_obj(t_object *obj)
{
  t_object	*elem;

  if ((elem = malloc(sizeof (t_object))) == NULL)
    exit(-1);
  elem->data.triangle = NULL;
  elem->type = obj->type;
  elem->pos = obj->pos;
  elem->temp_pos = obj->temp_pos;
  elem->limit = obj->limit;
  elem->color.value = obj->color.value;
  elem->next = NULL;
  while (obj->next)
    obj = obj->next;
  obj->next = elem;
  return (obj);
}

t_obj_list	*take_vect_text(char *read)
{
  char		*line;
  t_obj_list	*list;

  g_pos_vert = NULL;
  g_pos_text = NULL;
  init_list_obj(&list);
  while ((line = get_next_line_obj(read)))
    {
      if ((((my_strncmp(line, "v ", 2) == 0) || my_strncmp(line, "vn ", 3) == 0)
	   && ((add_to_vertex(line, &(list->vect), list->i++)) == NULL)) ||
	  ((my_strncmp(line, "vt ", 3) == 0) &&
	   ((add_to_text(line, &(list->text), list->n++)) == NULL)))
	return (NULL);
      free(line);
    }
  return (list);
}

t_object	*parsing_obj(char *path, t_object *obj)
{
  char		*read;
  t_obj_list	*list;
  char		*line;

  if ((read = read_inf(path)) == NULL)
    return (obj);
  if ((list = take_vect_text(read)) == NULL)
    return (obj);
  while ((line = get_next_line_obj(read)))
    {
      if (((my_strncmp(line, "f ", 2)) == 0))
	{
	  obj = add_to_list_obj(obj);
	  if (((check_poly(line) == 3) &&
	       (add_simple_triangle(line, &(obj->data.triangle),
				    list->vect, list->text)) == NULL) ||
	      (((check_poly(line) == 4) &&
		 ((obj = add_double_triangle(line, &(obj->data.triangle),
					     list, obj))) == NULL) || (check_poly(line) == -1)))
	    return (obj);
	}
      free(line);
    }
  free_list(list);
  return (obj);
}
