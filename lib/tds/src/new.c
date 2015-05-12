/*
** new.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Mar  9 19:36:15 2014 Laurent Fourrier
** Last update Mon Mar 10 09:31:11 2014 Laurent Fourrier
*/

#include <tsys.h>
#include "tds.h"

t_tds_var	*tds_new_var()
{
  t_tds_var	*rtn;

  if ((rtn = ts_malloc(sizeof(t_tds_var))) == NULL)
    return (NULL);
  rtn->type = TDS_TYPE_UNKWN;
  rtn->name = NULL;
  rtn->data = NULL;
  rtn->next = NULL;
  return (rtn);
}

t_tds_block	*tds_new_block()
{
  t_tds_block	*rtn;

  if ((rtn = ts_malloc(sizeof(t_tds_block))) == NULL)
    return (NULL);
  rtn->name = NULL;
  rtn->var_list = NULL;
  rtn->next = NULL;
  return (rtn);
}
