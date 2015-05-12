/*
** compile.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 15:15:45 2014 Laurent Fourrier
** Last update Wed Mar 12 15:16:53 2014 Laurent Fourrier
*/

#include <tio.h>
#include "tds.h"

/*
** Kinda stupid but fuck that I'm doing it anyway
*/
int	tcs_compile(t_file *file, t_tds *tds)
{
  return (tcs_write_magic(file, tds));
}
