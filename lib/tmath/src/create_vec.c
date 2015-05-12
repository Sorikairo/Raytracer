/*
** create_vec.c for tmath in /home/fourri_l/Projects/lib/tmath
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Dec  4 12:20:25 2013 Laurent Fourrier
** Last update Mon Feb  3 11:26:14 2014 Laurent Fourrier
*/

#include "tmath.h"

t_vec2i		new_vec2i(int x, int y)
{
  t_vec2i	rtn;

  rtn.x = x;
  rtn.y = y;
  return (rtn);
}

t_vec3i		new_vec3i(int x, int y, int z)
{
  t_vec3i	rtn;

  rtn.x = x;
  rtn.y = y;
  rtn.z = z;
  return (rtn);
}

t_vec2d		new_vec2d(double x, double y)
{
  t_vec2d	rtn;

  rtn.x = x;
  rtn.y = y;
  return (rtn);
}

t_vec3d		new_vec3d(double x, double y, double z)
{
  t_vec3d	rtn;

  rtn.x = x;
  rtn.y = y;
  rtn.z = z;
  return (rtn);
}
