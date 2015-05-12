/*
** in_line.c for tstdio in /home/fourri_l/Projects/lib/tstdio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Jan  3 14:21:49 2014 Laurent Fourrier
** Last update Fri Jan  3 18:31:16 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tstdio.h"

char	*enlarge_buffer(char *old, int size, int new_size)
{
  char	*rtn;
  int	it;

  it = 0;
  if ((rtn = malloc(new_size)) == NULL)
    return (NULL);
  while (it < size)
    {
      rtn[it] = old[it];
      it++;
    }
  free(old);
  return (rtn);
}

char	*in_line(int fd)
{
  char	*rtn;
  char	cur;
  int	it;

  it = 0;
  cur = in_char(fd);
  if ((rtn = malloc(TSTDIO_BUFSIZE)) == NULL)
    return (NULL);
  while (cur != -1 && cur != '\n')
    {
      rtn[it++] = cur;
      if ((it % TSTDIO_BUFSIZE == 0) &&
	  ((rtn = enlarge_buffer(rtn, it, it + TSTDIO_BUFSIZE)) == NULL))
	return (NULL);
      cur = in_char(fd);
    }
  rtn[it] = '\0';
  return (rtn);
}
