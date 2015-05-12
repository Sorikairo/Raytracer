/*
** render_pixel.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 01:44:54 2014 
** Last update Sat Jun  7 05:19:07 2014 
*/

#include <stdio.h>
#include <stdlib.h>
#include <tmlximg.h>
#include "scene.h"
#include "caster.h"
#include "object.h"
#include "intersection.h"

void	get_intersection(t_caster *caster, t_object **object)
{
  t_object	*tmp;

  tmp = *object;
  while (tmp)
    {
      inter_object(caster, tmp);
      tmp = tmp->next;
    }
}

void	render_pixel(t_scene *scene, double x, double y)
{
  int	current;

  get_intersection(scene->eye, &scene->object);
  if (!scene->eye->intersection.exist)
    return;
  current = is_lighted(&scene->light, scene);
  if (current == 0)
    {
      scene->eye->intersection.color.value = 0;
      return;
    }
}
