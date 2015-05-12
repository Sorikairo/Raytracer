/*
** caster.h for rt in /home/cruvei_t/RAYTRACER/MUL_2013_rtracer/include
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 00:53:28 2014 
** Last update Sun Jun  8 13:21:37 2014 Kevin Fouhety
*/

#ifndef		CASTER_H_
# define	CASTER_H_

# include	<tmath.h>
# include	"color.h"
# include	"intersection.h"
# include	"object.h"

struct			s_caster
{
  t_vec3d		pos;
  t_vec3d		temp_pos;
  t_vec3d		vec;
  t_vec3d		temp_vec;
  t_intersect		intersection;
  t_color		color;
  struct s_caster	*next;
};
typedef	struct s_caster t_caster;

void		inter_sphere(t_caster *, t_object *);
void		inter_plan(t_caster *, t_object *);
void		inter_cone(t_caster *, t_object *);
void		inter_cylindre(t_caster *, t_object *);
void		inter_triangle(t_caster *, t_object *);
void		norme_sphere(t_caster *, t_object *);
void		norme_triangle(t_caster *, t_object *);
void		norme_cone(t_caster *, t_object *);
void		norme_cylindre(t_caster *, t_object *);
void		norme_plan(t_caster *, t_object *);
void		rotate_coordinate(t_vec3d *, double*);
double		*rotation_z(double);
double		*rotation_y(double);
double		*rotation_x(double);
void		init_temp_pos(t_caster *, t_object *);
double		get_nearest(double, double);
void		init_intersection(t_caster *, t_object *);
void		rotate_caster(t_caster *, t_object *);
void		inter_object(t_caster *, t_object *);

#endif	/* CASTER_H_ */
