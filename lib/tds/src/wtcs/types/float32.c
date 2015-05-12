/*
** float32.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 15:59:50 2014 Laurent Fourrier
** Last update Thu Mar 13 16:00:46 2014 Laurent Fourrier
*/

#include <tsys.h>

char	*tcs_wtype_float32(void *data)
{
  char	*rtn;

  if ((rtn = ts_malloc(4)) == NULL)
    return (NULL);
  ts_memcpy(data, rtn, 4);
  return (rtn);
}
