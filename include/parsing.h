/*
** parsing.h for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 01:31:11 2014 Laurent Fourrier
** Last update Sat Jun  7 10:34:35 2014 Laurent Fourrier
*/

#ifndef PARSING_H_
# define PARSING_H_

# include <tio.h>
# include <tds.h>
# include "scene.h"
# include "object.h"

# define TDS_CAMERA	32
# define TDS_LIGHT	33
# define TDS_PLANE	1
# define TDS_SPHERE	0
# define TDS_CYLINDER	3
# define TDS_CONE	2
# define TDS_MODEL	4 /* Not used */

typedef void (*t_sub_func)(void *data, t_tds_block *block);
typedef void (*t_object_func)(t_scene *scene, t_tds_block *block,
			      t_sub_func sub_func, int type);

typedef struct	s_tds_def
{
  char		*str;
  int		type;
  t_object_func	object_func;
  t_sub_func	sub_func;
}		t_tds_def;

typedef struct	s_tds_typedef
{
  char		type;
  char		*name;
  int		size;
}		t_tds_typedef;

/*
** Master function
*/
void	init_scene(t_scene *scene);
int	parse_scene(t_scene *scene, t_file *file);

/*
** Object functions
*/
void		parse_caster(t_scene *scene, t_tds_block *block,
			     t_sub_func sub_func, int type);
void		parse_object(t_scene *scene, t_tds_block *block,
			     t_sub_func sub_func, int type);

/*
** Sub functions
*/
void		parse_object_model(void *data, t_tds_block *block);
void		parse_object_radius(void *data, t_tds_block *block);
void		parse_object_angle(void *data, t_tds_block *block);
void		parse_caster_color(void *data, t_tds_block *block);

/*
** TDS types thingy and helpers
*/
void		tds_getvar(void *dst, t_tds_var *var, int type);
void		tds_bind(void *dst, t_tds_var *var, int type, char *name);

t_tds_def	get_tds_def(char *str);

#endif
