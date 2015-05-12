/*
** cpy_struct.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Jun  2 15:23:48 2014 Kevin Fouhety
** Last update Tue Jun  3 12:55:46 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

t_poly          *cpy_struct_elem(t_poly *elem)
{
  t_poly        *ret;

  if ((ret = malloc (sizeof (t_poly))) == NULL)
    {
      write(1, "Error, malloc elem2 obj\n", 24);
      exit(0);
    }
  ret->v1 = elem->v2;
  ret->v2 = elem->v3;
  ret->vt1 = elem->vt2;
  ret->vt2 = elem->vt3;
  return (ret);
}

t_vec3d         *cpy_struct_vert(t_vertex *vert)
{
  t_vec3d       *ret;

  if ((ret = malloc(sizeof (t_vec3d))) == NULL)
    exit(write(1, "Error on malloc\n", 16));
  ret->x = vert->x;
  ret->y = vert->y;
  ret->z = vert->z;
  return (ret);
}

t_vec3d         *cpy_struct_text(t_text *point)
{
  t_vec3d       *ret;

  if ((ret = malloc(sizeof (t_vec3d))) == NULL)
    exit(write(1, "Error on malloc\n", 16));
  ret->x = point->x;
  ret->y = point->y;
  ret->z = point->z;
  return (ret);
}

t_vec3d         *cpy_struct_vec3d(t_vec3d *point)
{
  t_vec3d       *ret;

  if ((ret = malloc(sizeof (t_vec3d))) == NULL)
    exit(write(1, "Error on malloc\n", 16));
  ret->x = point->x;
  ret->y = point->y;
  ret->z = point->z;
  return (ret);
}
