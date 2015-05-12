/*
** get_tds_def.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 04:11:53 2014 Laurent Fourrier
** Last update Sat Jun  7 10:54:40 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tds.h>
#include <tutils.h>
#include "parsing.h"

t_tds_def	g_tds_def[] =
  {
    {"rt_camera", TDS_CAMERA, &parse_caster, NULL},
    {"rt_light", TDS_LIGHT, &parse_caster, &parse_caster_color},
    {"rt_plane", TDS_PLANE, &parse_object, NULL},
    {"rt_sphere", TDS_SPHERE, &parse_object, &parse_object_radius},
    {"rt_cylinder", TDS_CYLINDER, &parse_object, &parse_object_radius},
    {"rt_cone", TDS_CONE, &parse_object, &parse_object_angle},
    {"rt_obj", TDS_MODEL, &parse_object, &parse_object_model},
    {NULL, 0, NULL, NULL}
  };

t_tds_def	get_tds_def(char *str)
{
  int		it;

  it = 0;
  while (g_tds_def[it].str)
    {
      if (utl_strcmp(g_tds_def[it].str, str) == 0)
	return (g_tds_def[it]);
      it++;
    }
  return (g_tds_def[it]);
}
