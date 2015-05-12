/*
** draw_triangle.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed May 28 13:20:06 2014 Kevin Fouhety
** Last update Sun Jun  8 04:11:44 2014 Kevin Fouhety
*/

#include "caster.h"
#include "triangle.h"
#include "obj_parsing.h"
#include <tmath.h>

t_vec3d		sub_vect(t_vec3d *b, t_vec3d *u)
{
  t_vec3d	ret;

  ret.x = u->x - b->x;
  ret.y = u->y - b->y;
  ret.z = u->z - b->z;
  return (ret);
}

t_vec3d		cross_product(t_vec3d b, t_vec3d a)
{
  t_vec3d	ret;

  ret.x = (a.y * b.z) - (a.z * b.y);
  ret.y = (a.z * b.x) - (a.x * b.z);
  ret.z = (a.x * b.y) - (a.y * b.x);
  return (ret);
}



void		inter_triangle(t_caster *caster, t_object *triangle)
{
  t_vec3d	u;
  t_vec3d	v;
  t_vec3d	w;
  t_calc_tri	coef;

  if (triangle->data.triangle)
    {
      init_temp_pos(caster, triangle);
      u = sub_vect(triangle->data.triangle->v1, triangle->data.triangle->v2);
      v = sub_vect(triangle->data.triangle->v1, triangle->data.triangle->v3);
      coef.d = -(MLT(cross_product(u, v), caster->temp_vec));
      w = sub_vect(triangle->data.triangle->v1, &(caster->temp_pos));
      coef.a = -(MLT(cross_product(w, v), caster->temp_vec) / coef.d);
      coef.b = -(MLT(cross_product(u, w), caster->temp_vec) / coef.d);
      if ((coef.d == 0.0 || coef.d == -0.0) || (coef.a + coef.b) > 1.0 ||
	  coef.b < 0.0 || coef.a < 0.0)
	return ;
      triangle->dist = MLT(cross_product(u, v), w) / coef.d;
      if (triangle->dist > 0.0 && triangle->dist < caster->intersection.dist)
	{
	  caster->intersection.brightness = triangle->brightness;
	  init_intersection(caster, triangle);
	  rotate_caster(caster, triangle);
	}
    }
}
