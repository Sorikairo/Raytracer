/*
** in_char.c for tstdio in /home/fourri_l/Projects/lib/tstdio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Jan  3 14:28:53 2014 Laurent Fourrier
** Last update Fri Jan  3 17:50:48 2014 Laurent Fourrier
*/

#include <unistd.h>
#include "tstdio.h"

char		in_char(int fd)
{
  static char	buf[TSTDIO_BUFSIZE];
  static int	bytes_read = 0;
  static int	buf_it = 0;

  if (buf_it == bytes_read)
    {
      bytes_read = read(fd, buf, TSTDIO_BUFSIZE);
      buf_it = 0;
    }
  if (bytes_read < 1)
    return (-1);
  return (buf[buf_it++]);
}
