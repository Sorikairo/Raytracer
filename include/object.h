/*
** object.h for rt in /home/cruvei_t/RAYTRACER/MUL_2013_rtracer/include
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 00:42:07 2014 
** Last update Sun Jun  8 13:56:19 2014 Kevin Fouhety
*/

#ifndef		OBJECT_H_
# define	OBJECT_H_

# include	<tmath.h>
# include	<tlist.h>
# include	"triangle.h"
# include	"color.h"
# include	"struct_obj.h"

struct			s_object
{
  int			type;
  t_vec3d		pos;
  t_vec3d		temp_pos;
  t_vec3d		rotation;
  t_list		*limit;
  union
  {
    double		angle;
    double		radius;
    t_poly		*triangle;
  }			data;
  double		dist;
  double		brightness;
  t_color		color;
  char			reflexion;
  struct s_object	*next;
};
typedef struct s_object t_object;

#endif		/* OBJECT_H_ */
