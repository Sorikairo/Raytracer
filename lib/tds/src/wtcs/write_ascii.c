/*
** write_ascii.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 14:57:40 2014 Laurent Fourrier
** Last update Wed Mar 12 14:59:16 2014 Laurent Fourrier
*/

#include <tio.h>
#include <tutils.h>

void	tcs_write_ascii(t_file *file, char *ascii)
{
  short	size;

  size = (short)(utl_strlen(ascii) - 1);
  write_data(file, &size, 2);
  write_data(file, ascii, size);
}
