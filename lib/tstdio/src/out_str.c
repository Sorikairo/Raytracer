/*
** out_str.c for tstdio in /home/fourri_l/Projects/lib/tstdio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 14:04:24 2013 Laurent Fourrier
** Last update Sat Dec 28 14:04:52 2013 Laurent Fourrier
*/

#include "tstdio.h"

void	out_str(int fd, char *str)
{
  while (*str != '\0')
    out_char(fd, *str++);
}
