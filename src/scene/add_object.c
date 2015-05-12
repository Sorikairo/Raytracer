/*
** add_object.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 12:52:07 2014 Laurent Fourrier
** Last update Wed Jun  4 13:26:35 2014 Laurent Fourrier
*/

#include "scene.h"
#include "object.h"

void		add_object(t_scene *scene, t_object *object)
{
  t_object	*list;

  list = scene->object;
  if (!list)
    scene->object = object;
  else
    {
      while (list->next)
	list = list->next;
      list->next = object;
    }
}
