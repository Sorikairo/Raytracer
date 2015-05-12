/*
** xmalloc.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 09:21:47 2014 Laurent Fourrier
** Last update Wed Jun  4 09:23:13 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>

void	*xmalloc(size_t size)
{
  void	*rtn;

  rtn = malloc(size);
  if (!rtn)
    {
      write_str(g_fstderr, "Error: can't allocate memory\n");
      flush_file(g_fstderr);
      exit(0);
    }
  return (rtn);
}
