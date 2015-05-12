/*
** angle.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 10:57:25 2014 
** Last update Fri Jun  6 17:09:25 2014 Laurent Fourrier
*/

#include <math.h>
#include <tmath.h>

double	angle(t_vec3d v_light, t_vec3d item_norm)
{
  double	cosinus;

  cosinus = (((v_light.x * item_norm.x) +
	      (v_light.y * item_norm.y) +
	      (v_light.z * item_norm.z)) /
	     (sqrt((v_light.x * v_light.x) +
		   (v_light.y * v_light.y) +
		   (v_light.z * v_light.z)) *
	      sqrt((item_norm.x * item_norm.x) +
		   (item_norm.y * item_norm.y) +
		   (item_norm.z * item_norm.z))));
  return (cosinus);
}
