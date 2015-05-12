/*
** read_ascii.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar 10 16:29:42 2014 Laurent Fourrier
** Last update Wed Mar 12 15:20:28 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tio.h>

char	*tcs_read_ascii(t_file *file)
{
  short	size;
  int	it;
  char	*rtn;

  size = 0;
  read_data(file, &size, 2);
  if ((rtn = ts_malloc(size + 1)) == NULL)
    return (NULL);
  it = 0;
  while (it < size)
    rtn[it++] = read_char(file);
  rtn[it] = '\0';
  return (rtn);
}
