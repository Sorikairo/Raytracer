/*
** free_list.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri May 30 11:37:42 2014 Kevin Fouhety
** Last update Sat Jun  7 22:31:16 2014 Kevin Fouhety
*/

#include "obj_parsing.h"

void		free_list(t_obj_list *list)
{
  if (list == NULL)
    return ;
  if (list->text != NULL)
    free_list_text(list->text);
  free_list_v(list->vect);
  free(list);
}

void		free_list_v(t_vertex *list)
{
  t_vertex	*tmp;

  while (list)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void		free_list_text(t_text *list)
{
  t_text	*tmp;

  while (list)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}
