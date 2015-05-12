/*
** int32.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 15:02:48 2014 Laurent Fourrier
** Last update Wed Mar 12 15:03:24 2014 Laurent Fourrier
*/

#include <tsys.h>

char	*tcs_wtype_int32(void *data)
{
  char	*rtn;

  if ((rtn = ts_malloc(4)) == NULL)
    return (NULL);
  ts_memcpy(data, rtn, 4);
  return (rtn);
}
