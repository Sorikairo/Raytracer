/*
** intersection.h for rt in /home/cruvei_t/RAYTRACER/MUL_2013_rtracer/include
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 00:50:33 2014 
** Last update Sun Jun  8 23:18:15 2014 Barneaud Viveka
*/

#ifndef		INTERSECTION_H_
# define	INTERSECTION_H_

# include	<tmath.h>
# include	"color.h"

# define A(ux, uy) (pow(ux, 2.00) + pow(uy, 2.00))
# define B(ux, x, uy, y) (2.00 * (ux * x + uy * y))
# define C(r, x, y) -(pow(r, 2.00) - pow(x, 2.00) - pow(y, 2.00))
# define A1(ux, uy, uz) (pow(ux, 2.00) + pow(uy, 2.00) + pow(uz, 2.00))
# define B1(ux, x, uy, y, uz, z) (2.00 * (ux * x + uy * y + uz * z))
# define C1(r, x, y, z) -(pow(r, 2.00) - pow(x, 2.00) - pow(y, 2.00) - pow(z, 2.00))
# define A2(ux, uy, uz, a) (pow(ux, 2.00) + pow(uy, 2.00) - pow(uz, 2.00) / pow(tan(a), 2.00))
# define B2(ux, x, uy, y, uz, z, a) (2.00 * (ux * x + uy * y - ((uz * z) / pow(tan(a), 2.00))))
# define C2(x, y, z, a) -(-pow(x, 2.00) - pow(y, 2.00) + pow(z, 2.00) / pow(tan(a), 2.00))

struct	s_intersection
{
  int		exist;
  t_vec3d	pos;
  t_vec3d	v_norme;
  t_color	color;
  double	brightness;
  double	dist;
};
typedef struct s_intersection t_intersect;

#endif /* INTERSECTION_H_ */
