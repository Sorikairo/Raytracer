/*
** triangle.h for raytracer in /home/fouhet_k/Perso/raytracer/repo-rt/include/object
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue Jun  3 12:52:09 2014 Kevin Fouhety
** Last update Sun Jun  8 03:24:49 2014 Kevin Fouhety
*/

#ifndef TRIANGLE_H_
# define TRIANGLE_H_

# define MLT_NEG(p1, p2)(-p1.x * p2.x - p1.y * p2.y - p1.z * p2.z)
# define MLT(p1, p2)(p1.x * p2.x + p1.y * p2.y + p1.z * p2.z)

typedef struct s_calc_tri
{
  double	d;
  double	a;
  double	b;
}t_calc_tri;

#endif
