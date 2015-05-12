/*
** int32.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar 10 16:21:49 2014 Laurent Fourrier
** Last update Mon Mar 10 16:22:20 2014 Laurent Fourrier
*/

#include <tsys.h>

void	*tcs_type_int32(char *data)
{
  void	*rtn;

  if ((rtn = ts_malloc(4)) == NULL)
    return (NULL);
  return (ts_memcpy(data, rtn, 4));
}
