/*
** add_to_list_poly.c for raytracer in /home/fouhet_k/Perso/raytracer
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun May 25 02:37:33 2014 Kevin Fouhety
** Last update Wed Jun  4 03:52:47 2014 Kevin Fouhety
*/

#include "obj_parsing.h"

void		add_list_tri(char *line, t_poly ***poly, t_vertex *point, t_text *text)
{
  t_name	*num;

  num = take_next_point(line, 3);
  (**poly)->v1 = take_next_vertex(line, point, num->v);
  (**poly)->vt1 = take_next_text(line, text, num->vt);
  num = take_next_point(line, 3);
  (**poly)->v2 = take_next_vertex(line, point, num->v);
  (**poly)->vt2 = take_next_text(line, text, num->vt);
  num = take_next_point(line, 3);
  (**poly)->v3 = take_next_vertex(line, point, num->v);
  (**poly)->vt3 = take_next_text(line, text, num->vt);
}

void		add_list_tri_no_text(char *line, t_poly ***poly, t_vertex *point)
{
  t_name	*num;

  num = take_next_point(line, 3);
  (**poly)->v1 = take_next_vertex(line, point, num->v);
  (**poly)->vt1 = NULL;
  num = take_next_point(line, 3);
  (**poly)->v2 = take_next_vertex(line, point, num->v);
  (**poly)->vt2 = NULL;
  num = take_next_point(line, 3);
  (**poly)->v3 = take_next_vertex(line, point, num->v);
  (**poly)->vt3 = NULL;
}

char		*add_simple_triangle(char *line, t_poly **poly,
				     t_vertex *vert, t_text *text)
{
  if (((*poly) = malloc(sizeof (t_poly))) == NULL)
    {
      write(1, "Error creat list obj\n", 21);
      exit(-1);
    }
  if (text != NULL)
    add_list_tri(line, &poly, vert, text);
  else
    add_list_tri_no_text(line, &poly, vert);
  return ("ok");
}
