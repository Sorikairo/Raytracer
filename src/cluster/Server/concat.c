/*
** concat.c for concat in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Wed May 28 13:29:14 2014 Barneaud Viveka
** Last update Thu Jun  5 11:20:29 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	"clustering.h"

size_t		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char		*xstrdup(char *str)
{
  char		*ret;
  int		i;

  ret = xmalloc_and_set(NULL, sizeof(*ret) * (my_strlen(str) + 1));
  i = 0;
  while (str[i] != 0)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char		*realloc_and_concat(char *s1, char *s2)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  if (s1 == NULL)
    s1 = xmalloc_and_set(NULL, sizeof(*s1) * (my_strlen(s2) + 1));
  j = my_strlen(s1);
  tmp = xmalloc_and_set(NULL, sizeof(*tmp) * (j + my_strlen(s2) + 1));
  while (s1[i] != '\0')
    {
      tmp[i] = s1[i];
      i++;
    }
  i = 0;
  while (s2[i] != '\0')
    tmp[j++] = s2[i++];
  tmp[j] = '\0';
  s1 = xstrdup(tmp);
  free(tmp);
  return (s1);
}
