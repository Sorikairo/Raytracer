/*
** float32.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 12:53:08 2014 Laurent Fourrier
** Last update Thu Mar 13 12:55:41 2014 Laurent Fourrier
*/

#include <tsys.h>

void	*tcs_type_float32(char *data)
{
  void	*rtn;

  if ((rtn = ts_malloc(4)) == NULL)
    return (NULL);
  return (ts_memcpy(data, rtn, 4));
}
