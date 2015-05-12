/*
** out_char.c for tstdio in /home/fourri_l/Projects/lib/tstdio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 14:03:35 2013 Laurent Fourrier
** Last update Sat Dec 28 14:04:16 2013 Laurent Fourrier
*/

#include <unistd.h>

void	out_char(int fd, char c)
{
  write(fd, &c, 1);
}
