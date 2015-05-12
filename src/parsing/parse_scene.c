/*
** parse_scene.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 01:58:28 2014 Laurent Fourrier
** Last update Sun Jun  8 13:39:44 2014 Kevin Fouhety
*/

#include <mlx.h>
#include <tio.h>
#include <tds.h>
#include <stdlib.h>
#include <tmlxwin.h>
#include "utils.h"
#include "parsing.h"

static void	parse_scene_tds(t_scene *scene, t_tds *tds)
{
  t_tds_def	def;
  t_tds_block	*block;

  block = tds->block_list;
  while (block)
    {
      def = get_tds_def(block->name);
      if (def.object_func)
	def.object_func(scene, block, def.sub_func, def.type);
      block = block->next;
    }
}

void		init_scene(t_scene *scene)
{
  scene->object = NULL;
  scene->eye = NULL;
  scene->light = NULL;
}

int		parse_scene(t_scene *scene, t_file *file)
{
  int		rtn;
  t_tds		tds;

  rtn = 0;
  if (!file || !is_readable(file))
    write_str(g_fstderr, "Error: input file is not readable\n");
  else
    {
      tds = tds_parse(file);
      if (tds.block_list)
	{
	  parse_scene_tds(scene, &tds);
	  rtn = 1;
	}
      else
	write_str(g_fstderr, "Error: input file has syntax errors\n");
    }
  flush_file(g_fstderr);
  return (rtn);
}
