/*
** solve_quadra.c for tmath in /home/fourri_l/Projects/lib/tmath
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Jan  5 17:00:07 2014 Laurent Fourrier
** Last update Sun Jan  5 17:11:06 2014 Laurent Fourrier
*/

#include <math.h>
#include "tmath.h"

t_quadra_sol	get_quadra_zero()
{
  t_quadra_sol	rtn;

  rtn.nbr = 0;
  rtn.first_sol = 0.0;
  rtn.second_sol = 0.0;
  return (rtn);
}

t_quadra_sol	get_quadra_one(double a, double b, double delta)
{
  t_quadra_sol	rtn;

  rtn.nbr = 1;
  rtn.first_sol = (-b) / (2.0 * a);
  rtn.second_sol = 0.0;
  return (rtn);
}

t_quadra_sol	get_quadra_two(double a, double b, double delta)
{
  t_quadra_sol	rtn;

  rtn.nbr = 2;
  rtn.first_sol = (-b + sqrt(delta)) / (2.0 * a);
  rtn.second_sol = (-b - sqrt(delta)) / (2.0 * a);
  return (rtn);
}

t_quadra_sol	solve_quadra(double a, double b, double c)
{
  double	delta;

  delta = pow(b, 2.0) - (4.0 * a * c);
  return ((delta > 0) ? get_quadra_two(a, b, delta) :
	  (delta == 0) ? get_quadra_one(a, b, delta) :
	  get_quadra_zero());
}
