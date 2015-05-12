/*
** inter_sphere.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 02:26:23 2014 
** Last update Sun Jun  8 23:22:18 2014 Barneaud Viveka
*/

#include <math.h>
#include "scene.h"
#include "caster.h"
#include "object.h"
#include "intersection.h"

void	inter_sphere(t_caster *caster, t_object *sphere)
{
  double	delt;
  double	a;
  double	b;
  double	c;

  init_temp_pos(caster, sphere);
  a = A1(caster->temp_vec.x, caster->temp_vec.y, caster->temp_vec.z);
  b = B1(caster->temp_vec.x, caster->temp_pos.x, caster->temp_vec.y,
	 caster->temp_pos.y, caster->temp_vec.z, caster->temp_pos.z);
  c = C1(sphere->data.radius, caster->temp_pos.x, caster->temp_pos.y
	 , caster->temp_pos.z);
  delt = (pow(b, 2.0) - 4.0 * (a * c));
  if (delt >= 0.0)
    {
      sphere->dist = get_nearest((- b - sqrt(delt)) / (2.0 * a),
				 (- b + sqrt(delt)) / (2.0 * a));
      if (sphere->dist > 0.0 && sphere->dist < caster->intersection.dist)
	{
	  caster->intersection.brightness = sphere->brightness;
	  init_intersection(caster, sphere);
	  rotate_caster(caster, sphere);
	}
    }
}

void	inter_plan(t_caster *caster, t_object *plan)
{
  double	dist;

  init_temp_pos(caster, plan);
  if (rint(caster->temp_vec.z) != 0.0
      && ((dist = -(caster->temp_pos.z / caster->temp_vec.z)) > 0.0))
    {
     plan->dist = dist;
     if (plan->dist > 0.0 && plan->dist < caster->intersection.dist)
       {
	 caster->intersection.brightness = plan->brightness;
	 init_intersection(caster, plan);
	 rotate_caster(caster, plan);
	}
    }
}

void	inter_cone(t_caster *caster, t_object *cone)
{
  double	a;
  double	b;
  double	c;
  double	delt;

  init_temp_pos(caster, cone);
  a = A2(caster->temp_vec.x, caster->temp_vec.y, caster->temp_vec.z,
	 cone->data.angle);
  b = B2(caster->temp_vec.x, caster->temp_pos.x, caster->temp_vec.y,
	 caster->temp_pos.y, caster->temp_vec.z, caster->temp_pos.z,
	 cone->data.angle);
  c = C2(caster->temp_pos.x, caster->temp_pos.y, caster->temp_pos.z,
	 cone->data.angle);
  delt = (pow(b, 2.0) - 4.0 * (a * c));
  if (delt >= 0.0)
    {
      cone->dist = get_nearest((-b - sqrt(delt)) / (2.0 * a),
			       (-b + sqrt(delt)) / (2.0 * a));
      if (cone->dist > 0.0 && cone->dist < caster->intersection.dist)
	{
	  caster->intersection.brightness = cone->brightness;
	  init_intersection(caster, cone);
	  rotate_caster(caster, cone);
	}
    }
}

void	inter_cylindre(t_caster *caster, t_object *cylindre)
{
  double		delt;
  double		a;
  double		b;
  double		c;

  init_temp_pos(caster, cylindre);
  a = A(caster->temp_vec.x, caster->temp_vec.y);
  b = B(caster->temp_vec.x, caster->temp_pos.x, caster->temp_vec.y,
	caster->temp_pos.y);
  c = C(cylindre->data.radius, caster->temp_pos.x, caster->temp_pos.y);
  delt = (pow(b, 2.0) - 4.0 * (a * c));
  if (delt >= 0.0)
    {
      cylindre->dist = get_nearest((-b - sqrt(delt)) / (2.0 * a),
				   (-b + sqrt(delt)) / (2.0 * a));
      if (cylindre->dist > 0.0 && cylindre->dist < caster->intersection.dist)
	{
	  caster->intersection.brightness = cylindre->brightness;
	  init_intersection(caster, cylindre);
	  rotate_caster(caster, cylindre);
	}
    }
}
