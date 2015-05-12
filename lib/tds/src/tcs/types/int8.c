/*
** int8.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar 10 16:09:43 2014 Laurent Fourrier
** Last update Mon Mar 10 16:21:34 2014 Laurent Fourrier
*/

#include <tsys.h>

void	*tcs_type_int8(char *data)
{
  void	*rtn;

  if ((rtn = ts_malloc(1)) == NULL)
    return (NULL);
  return (ts_memcpy(data, rtn, 1));
}
