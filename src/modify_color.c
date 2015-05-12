/*
** modify_color.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 10:14:32 2014 
** Last update Sun Jun  8 17:01:15 2014 Laurent Fourrier
*/

#include "scene.h"
#include "caster.h"
#include "object.h"
#include "intersection.h"

double		get_next_cos(t_scene *scene, t_caster *light)
{
  double	cos;

  cos = angle(light->vec, scene->eye->intersection.v_norme);
  cos = -cos;
  if (cos > 0.0)
    return (cos);
  return (0.0);
}

void		modify_color(t_scene *scene, t_caster *light, double cos)
{
  int		it;

  if (!light)
    scene->eye->intersection.color.value = 0;
  else
    brightness(scene->eye, light);
  it = 0;
  while (it < 3)
    scene->eye->intersection.color.array[it++] *= cos;
}
