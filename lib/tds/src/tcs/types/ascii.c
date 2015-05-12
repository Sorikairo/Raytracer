/*
** ascii.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar 10 16:22:32 2014 Laurent Fourrier
** Last update Wed Mar 12 15:26:40 2014 Laurent Fourrier
*/

#include <tsys.h>

/*
** /!\ this function is using sizeof, data must be malloc'd (should not be a
** problem with tcs reader)
*/
void	*tcs_type_ascii(char *data)
{
  char	*rtn;
  int	size;

  size = sizeof(data);
  if ((rtn = ts_malloc(size + 1)) == NULL)
    return (NULL);
  rtn = ts_memcpy(data, rtn, size);
  rtn[size] = '\0';
  return (rtn);
}
