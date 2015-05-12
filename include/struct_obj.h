/*
** struct_obj.h for raytracer in /home/fouhet_k/Perso/raytracer/repo-rt/include
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue Jun  3 12:54:33 2014 Kevin Fouhety
** Last update Wed Jun  4 15:51:22 2014 Kevin Fouhety
*/

#ifndef STRUCT_OBJ_H_
# define STRUCT_OBJ_H_

#include <tmath.h>

typedef struct s_vertex
{
  float			number;
  double		x;
  double		y;
  double		z;
  struct s_vertex	*next;
  struct s_vertex	*preview;
}			t_vertex;

typedef struct s_text
{
  float			number;
  double		x;
  double		y;
  double		z;
  struct s_text		*next;
  struct s_text		*preview;
}			t_text;

typedef struct s_obj_list
{
  float			i;
  float			n;
  t_text		*text;
  t_vertex		*vect;
}			t_obj_list;

typedef struct s_name
{
  float			v;
  float			vt;
}			t_name;

typedef struct s_poly
{
  t_vec3d		*v1;
  t_vec3d		*v2;
  t_vec3d		*v3;
  t_vec3d		*vt1;
  t_vec3d		*vt2;
  t_vec3d		*vt3;
}			t_poly;

#endif
