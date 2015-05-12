/*
** tmath.h for tmath in /home/fourri_l/Projects/lib/tmath
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Dec  4 11:14:50 2013 Laurent Fourrier
** Last update Sun Jan  5 17:01:54 2014 Laurent Fourrier
*/

#ifndef TMATH_H_
#define TMATH_H_

typedef struct	s_vec2i
{
  int		x;
  int		y;
}		t_vec2i;

typedef struct	s_vec3i
{
  int		x;
  int		y;
  int		z;
}		t_vec3i;

typedef struct	s_vec2d
{
  double	x;
  double	y;
}		t_vec2d;

typedef struct	s_vec3d
{
  double	x;
  double	y;
  double	z;
}		t_vec3d;

typedef struct	s_quadra_sol
{
  int		nbr;
  double	first_sol;
  double	second_sol;
}		t_quadra_sol;

t_vec2i		new_vec2i(int x, int y);
t_vec3i		new_vec3i(int x, int y, int z);
t_vec2d		new_vec2d(double x, double y);
t_vec3d		new_vec3d(double x, double y, double z);

int		is_numeric(char *str);
int		strtoi(char *str);

t_quadra_sol	solve_quadra(double a, double b, double c);

#endif
