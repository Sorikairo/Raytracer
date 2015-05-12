/*
** brightness.c<2> for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 10:10:46 2014 
** Last update Sun Jun  8 16:58:20 2014 Laurent Fourrier
*/

#include <stdio.h>
#include <math.h>
#include "caster.h"
#include "scene.h"

int		intersect_same(t_intersect light, t_intersect eye)
{
  if (rint(light.pos.x) == rint(eye.pos.x))
    if (rint(light.pos.y) == rint(eye.pos.y))
      if (rint(light.pos.z) == rint(eye.pos.z))
	return (1);
  return (0);
}

void		get_light_vec(t_caster *light, t_scene *scene)
{
  light->intersection.dist = 100000000.0;
  light->vec.x = scene->eye->intersection.pos.x - light->pos.x;
  light->vec.y = scene->eye->intersection.pos.y - light->pos.y;
  light->vec.z = scene->eye->intersection.pos.z - light->pos.z;
}

int		is_lighted(t_caster **light, t_scene *scene)
{
  t_caster	*tmp;
  t_caster	*real;
  double	cos;
  double	mult;

  tmp = *light;
  real = NULL;
  mult = 0.0;
  while (tmp)
    {
      get_light_vec(tmp, scene);
      get_intersection(tmp, &scene->object);
      if (tmp->intersection.exist)
	if (intersect_same(tmp->intersection, scene->eye->intersection) &&
	    (cos = get_next_cos(scene, tmp)) > mult)
	  {
	    mult = cos;
	    real = tmp;
	  }
      tmp = tmp->next;
    }
  modify_color(scene, real, mult);
  return (mult > 0.0);
}

void		brightness(t_caster *eye, t_caster *light)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      eye->intersection.color.array[i] *= (1.0 - eye->intersection.brightness);
      eye->intersection.color.array[i] += (light->color.array[i] 
					   * eye->intersection.brightness);
      i++;
    }
}
