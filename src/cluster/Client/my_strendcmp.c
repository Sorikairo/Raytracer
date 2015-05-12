/*
** my_strendcmp.c for my_strendcmp in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Mon May 19 13:59:00 2014 Barneaud Viveka
** Last update Wed Jun  4 12:11:48 2014 Barneaud Viveka
*/

#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>
#include	"clustering.h"

int		my_strendcmp(char *s1, char *s2)
{
  int		i;
  int		j;

  if (s1 == NULL || s2 == NULL || s1[0] == 0)
    return (1);
  if (my_strlen(s2) < my_strlen(s1))
    return (1);
  i = 0;
  j = my_strlen(s2) - my_strlen(s1);
  while (s2[j] != 0 && s1[i] != 0)
    {
      if (s1[i] != s2[j])
	return (1);
      j++;
      i++;
    }
  return (0);
}
