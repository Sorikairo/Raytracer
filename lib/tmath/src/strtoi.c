/*
** strtoi.c for tmath in /home/fourri_l/Projects/lib/tmath
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec  7 00:16:21 2013 Laurent Fourrier
** Last update Mon Feb  3 11:26:23 2014 Laurent Fourrier
*/

#include "tmath.h"

int	strtoi(char *str)
{
  char	neg;
  int	it;
  int	rtn;
  int	value;

  neg = 0;
  it = 0;
  rtn = 0;
  value = 1;
  while (str[it] != '\0')
    it++;
  while (it >= 0)
    {
      if (str[it] >= '0' && str[it] <= '9')
	{
	  rtn += (str[it] - '0') * value;
	  value++;
	}
      else if (str[it] == '-')
	neg = (neg) ? 0 : 1;
      it--;
    }
  return (rtn * ((neg) ? -1 : 1));
}
