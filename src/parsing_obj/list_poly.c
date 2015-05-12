/*
** list_poly.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri May 30 11:36:45 2014 Kevin Fouhety
** Last update Sat Jun  7 22:26:59 2014 Kevin Fouhety
*/

# include "obj_parsing.h"

t_vec3d         *take_next_vertex(char *line, t_vertex *point, float num)
{
  if (!g_pos_vert)
    g_pos_vert = point;
  if (g_pos_vert->number >= num)
    while (g_pos_vert)
      {
	if (num == g_pos_vert->number)
	  return(cpy_struct_vert(g_pos_vert));
	g_pos_vert = g_pos_vert->next;
      }
  else
    while (g_pos_vert)
      {
	if (num == g_pos_vert->number)
	  return(cpy_struct_vert(g_pos_vert));
	g_pos_vert = g_pos_vert->preview;
      }
  write(1, "Missing a Vertex\n", 17);
  exit(-1);
}

t_vec3d         *take_next_text(char *line, t_text *text, float num)
{
  if (!g_pos_text)
    g_pos_text = text;
  if (g_pos_text->number >= num)
    while (g_pos_text)
      {
	if (num == g_pos_text->number)
	  return(cpy_struct_text(g_pos_text));
	g_pos_text = g_pos_text->next;
      }
  else
    while (g_pos_text)
      {
	if (num == g_pos_text->number)
	  return(cpy_struct_text(g_pos_text));
	g_pos_text = g_pos_text->preview;
      }
  write(1, "Missing a textur\n", 17);
  exit(-1);
}
