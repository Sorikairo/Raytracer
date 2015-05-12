/*
** obj_parsing.h for raytracer in /home/fouhet_k/Perso/raytracer/repo-rt/include
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue Jun  3 12:51:21 2014 Kevin Fouhety
** Last update Sun Jun  8 23:19:01 2014 Barneaud Viveka
*/

#ifndef OBJ_PARSING_H_
# define OBJ_PARSING_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "struct_obj.h"
#include <tmath.h>
#include "object.h"
#include "color.h"

t_vertex	*g_pos_vert;
t_text		*g_pos_text;

/* list_vertex */

char		*add_to_vertex(char *line, t_vertex **list, int i);
char		*get_the_nbr(char *tmp);
t_object	*add_to_list_obj(t_object *obj);

/* list_texture */

char		*add_to_text(char *line, t_text **list, int i);
double		take_next_val(char *line);
t_vec3d		*take_next_text(char *line, t_text *text, float num);
char		*get_the_second_nbr(char *tmp);


/* list_poly */

int		check_poly(char *line);
t_name		*take_next_point(char *line, int nb);
void		init_elem_poly(t_poly **elem);
char		*add_simple_triangle(char *line, t_poly **poly,
				     t_vertex *vert, t_text *text);
t_object	*add_double_triangle(char *line, t_poly **poly,
				     t_obj_list *list, t_object *object);
t_vec3d		*take_next_vertex(char *line, t_vertex *vertex, float num);

/* cpy */

t_poly		*cpy_struct_elem(t_poly *elem);
t_vec3d		*cpy_struct_vert(t_vertex *vert);
t_vec3d		*cpy_struct_text(t_text *point);
t_vec3d		*cpy_struct_vec3d(t_vec3d *vertex);

/* utils */

void		init_list_obj(t_obj_list **list);

char		*read_inf(char *path);

char		*x_malloc(int size);
t_poly		*x_malloc_poly(int size);
char		*get_next_line_obj(char *str);
int		size_of_number(char *str, int i);

void		free_list(t_obj_list *list);
void		free_list_v(t_vertex *list);
void		free_list_text(t_text *list);

t_object	*parsing_obj(char *path, t_object *object);

#endif
