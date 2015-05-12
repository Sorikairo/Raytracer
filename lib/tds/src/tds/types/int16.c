/*
** int16.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 10:26:35 2014 Laurent Fourrier
** Last update Thu Feb 27 10:42:25 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>

void	*tds_type_int16(char *line)
{
  short	*rtn;

  if ((rtn = ts_malloc(2)) == NULL)
    return (NULL);
  *rtn = utl_atoi(line);
  return (rtn);
}
