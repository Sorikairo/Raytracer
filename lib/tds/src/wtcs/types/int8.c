/*
** int8.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 15:00:26 2014 Laurent Fourrier
** Last update Wed Mar 12 15:01:50 2014 Laurent Fourrier
*/

#include <tsys.h>

char	*tcs_wtype_int8(void *data)
{
  char	*rtn;

  if ((rtn = ts_malloc(1)) == NULL)
    return (NULL);
  ts_memcpy(data, rtn, 1);
  return (rtn);
}
