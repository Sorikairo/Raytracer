/*
** ascii.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 15:04:17 2014 Laurent Fourrier
** Last update Wed Mar 12 15:10:49 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>

char	*tcs_wtype_ascii(void *data)
{
  char	*str;
  char	*rtn;
  int	size;

  str = data;
  size = utl_strlen(data) - 1;
  if ((rtn = ts_malloc(size + 4)) == NULL)
    return (NULL);
  ts_memcpy(&size, rtn, 4);
  ts_memcpy(str, rtn, size);
  return (rtn);
}
