/*
** int8.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 10:24:21 2014 Laurent Fourrier
** Last update Wed Mar 12 16:11:49 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>

void	*tds_type_int8(char *line)
{
  char	*rtn;

  if ((rtn = ts_malloc(1)) == NULL)
    return (NULL);
  *rtn = utl_atoi(line);
  return (rtn);
}
