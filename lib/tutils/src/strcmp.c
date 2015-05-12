/*
** strcmp.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  9 19:33:17 2013 Laurent Fourrier
** Last update Wed Jun  4 03:32:14 2014 Laurent Fourrier
*/

#include "tutils.h"

int	utl_strcmp(char *first, char *second)
{
  if (!first && !second)
    return (0);
  else if (!first || !second)
    return (0);
  while (*first && *second)
    {
      if (*first != *second)
	return (*first - *second);
      first++;
      second++;
    }
  return (*first - *second);
}

int	utl_strncmp(char *first, char *second, int n)
{
  int	it;

  it = 0;
  while (it < n)
    {
      if (first[it] != second[it])
	return (first[it] - second[it]);
      it++;
    }
  return (0);
}
