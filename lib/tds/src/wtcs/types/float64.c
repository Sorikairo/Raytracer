/*
** float64.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 16:00:55 2014 Laurent Fourrier
** Last update Thu Mar 13 16:01:38 2014 Laurent Fourrier
*/

#include <tsys.h>

char	*tcs_wtype_float64(void *data)
{
  char	*rtn;

  if ((rtn = ts_malloc(8)) == NULL)
    return (NULL);
  ts_memcpy(data, rtn, 8);
  return (rtn);
}
