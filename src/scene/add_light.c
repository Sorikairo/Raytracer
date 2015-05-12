/*
** add_light.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 12:45:05 2014 Laurent Fourrier
** Last update Sun Jun  8 18:25:50 2014 Barneaud Viveka
*/

#include "scene.h"
#include "caster.h"

void		add_light(t_scene *scene, t_caster *light)
{
  t_caster	*list;

  list = scene->light;
  if (!list)
    scene->light = light;
  else
    {
      while (list && list->next)
	list = list->next;
      list->next = light;
    }
}
