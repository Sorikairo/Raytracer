/*
** add_double_triangle_obj.c for raytracer in /home/fouhet_k/Perso/raytracer/parsing_obj
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Jun  4 01:11:49 2014 Kevin Fouhety
** Last update Sun Jun  8 13:44:54 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

t_object	*take_cpy_tmp(t_object *obj, t_poly *tmp)
{
  if ((obj->data.triangle = malloc(sizeof (t_poly))) == NULL)
    {
      write(1, "Error creat list obj\n", 21);
      exit(-1);
    }
  obj->data.triangle->v1 = tmp->v1;
  obj->data.triangle->v2 = tmp->v2;
  obj->data.triangle->v3 = tmp->v3;
  obj->data.triangle->vt1 = tmp->vt1;
  obj->data.triangle->vt2 = tmp->vt2;
  obj->data.triangle->vt3 = tmp->vt3;
  return (obj);
}

void            add_double_tri(char *line, t_poly ***poly,
			       t_obj_list *list, t_object *obj)
{
  t_name        *num;
  t_poly	*tmp;

  if (((**poly) = malloc(sizeof (t_poly))) == NULL)
    {
      write(1, "Error creat list obj\n", 21);
      exit(-1);
    }
  tmp = x_malloc_poly(sizeof (t_poly));
  num = take_next_point(line, 4);
  (**poly)->v1 = take_next_vertex(line, list->vect, num->v);
  (**poly)->vt1 = take_next_text(line, list->text, num->vt);
  num = take_next_point(line, 4);
  (**poly)->v2 = take_next_vertex(line, list->vect, num->v);
  (**poly)->vt2 = take_next_text(line, list->text, num->vt);
  num = take_next_point(line, 4);
  (**poly)->v3 = take_next_vertex(line, list->vect, num->v);
  (**poly)->vt3 = take_next_text(line, list->text, num->vt);
  obj = add_to_list_obj(obj);
  tmp = cpy_struct_elem(**poly);
  num = take_next_point(line, 4);
  tmp->v3 = take_next_vertex(line, list->vect, num->v);
  tmp->vt3 = take_next_text(line, list->text, num->vt);
  obj = take_cpy_tmp(obj, tmp);
}

void            add_double_tri_no_text(char *line, t_poly ***poly,
				       t_vertex *vect, t_object *obj)
{
  t_name        *num;
  t_poly	*tmp;

  if (((**poly) = malloc(sizeof (t_poly))) == NULL)
    {
      write(1, "Error creat list obj\n", 21);
      exit(-1);
    }
  tmp = x_malloc_poly(sizeof (t_poly));
  num = take_next_point(line, 4);
  (**poly)->v1 = take_next_vertex(line, vect, num->v);
  (**poly)->vt1 = NULL;
  num = take_next_point(line, 4);
  (**poly)->v2 = take_next_vertex(line, vect, num->v);
  (**poly)->vt2 = NULL;
  num = take_next_point(line, 4);
  (**poly)->v3 = take_next_vertex(line, vect, num->v);
  (**poly)->vt3 = NULL;
  obj = add_to_list_obj(obj);
  tmp = cpy_struct_elem(**poly);
  num = take_next_point(line, 4);
  tmp->v3 = take_next_vertex(line, vect, num->v);
  tmp->vt3 = NULL;
  obj = take_cpy_tmp(obj, tmp);
}


t_object	*add_double_triangle(char *line, t_poly **poly,
				     t_obj_list *list, t_object *obj)
{
  if (list->text != NULL)
    add_double_tri(line, &poly, list, obj);
  else
    add_double_tri_no_text(line, &poly, list->vect, obj);
  return (obj);
}

