/*
** scene.h for rt in /home/cruvei_t/RAYTRACER/MUL_2013_rtracer/include
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 00:38:28 2014 
** Last update Sun Jun  8 16:43:57 2014 Laurent Fourrier
*/

#ifndef		SCENE_H_
# define	SCENE_H_

# include	<tmlximg.h>
# include	<tmlxwin.h>
# include	"object.h"
# include	"caster.h"

struct		s_scene
{
  int		width;
  int		height;
  t_object	*object;
  t_caster	*eye;
  t_caster	*light;
  /* t_tex		*tex; */
};
typedef struct s_scene t_scene;

void		add_light(t_scene *scene, t_caster *light);
void		add_object(t_scene *scene, t_object *object);
int		is_lighted(t_caster **, t_scene *);
double		get_next_cos(t_scene *scene, t_caster *light);
void		modify_color(t_scene *, t_caster *, double);
void		brightness(t_caster *, t_caster *);
double		angle(t_vec3d, t_vec3d);
void		render_pixel(t_scene *, double, double);
void		get_intersection(t_caster *, t_object **);
void		reset_eye(t_scene *scene, double x, double y);

#endif		/* SCENE_H_ */
