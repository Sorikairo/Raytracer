/*
** tds.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 09:26:35 2014 Laurent Fourrier
** Last update Sat Jun  7 11:17:35 2014 Laurent Fourrier
*/

#include <string.h>
#include <tio.h>
#include <tds.h>
#include "parsing.h"

t_tds_typedef	g_tds_typedef[] =
  {
    {TDS_TYPE_INT8, "INT8", sizeof(char)},
    {TDS_TYPE_INT32, "INT32", sizeof(int)},
    {TDS_TYPE_FLT64, "FLT64", sizeof(double)},
    {TDS_TYPE_STR, "STR", -1},
    {0, NULL, 0}
  };

static char		tds_checktype(t_tds_var *var, t_tds_typedef def)
{
  if (!def.name || var->type != def.type)
    {
      write_str(g_fstdout, "Syntax error: attribute ");
      write_str(g_fstdout, var->name);
      write_str(g_fstdout, " is not of required type ");
      write_str(g_fstdout, def.name);
      write_str(g_fstdout, ".\n");
      flush_file(g_fstdout);
      return (0);
    }
  return (1);
}

static t_tds_typedef	tds_get_typedef(char type)
{
  int			it;

  it = 0;
  while (g_tds_typedef[it].type)
    {
      if (g_tds_typedef[it].type == type)
	return (g_tds_typedef[it]);
      it++;
    }
  return (g_tds_typedef[it]);
}

void			tds_bind(void *dst, t_tds_var *var,
				 int type, char *name)
{
  void			**ptr;
  t_tds_typedef		def;

  def = tds_get_typedef(type);
  if (strcmp(var->name, name) == 0)
    {
      if (tds_checktype(var, def))
	{
	  if (def.size == -1)
	    {
	      ptr = dst;
	      *ptr = var->data;
	    }
	  else
	    memcpy(dst, var->data, def.size);
	}
    }
}
