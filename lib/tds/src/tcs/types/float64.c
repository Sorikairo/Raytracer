/*
** float64.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 12:55:50 2014 Laurent Fourrier
** Last update Thu Mar 13 16:06:50 2014 Laurent Fourrier
*/

#include <tsys.h>

void	*tcs_type_float64(char *data)
{
  void	*rtn;

  if ((rtn = ts_malloc(8)) == NULL)
    return (NULL);
  return (ts_memcpy(data, rtn, 8));
}
