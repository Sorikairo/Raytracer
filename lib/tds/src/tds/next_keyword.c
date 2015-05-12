/*
** next_keyword.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 16:05:10 2014 Laurent Fourrier
** Last update Wed Mar 12 16:49:52 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tio.h>
#include "tds.h"

char	g_separators[] = 
  {
    ' ', '\t', '\n', 0
  };

int	tds_is_separator(char c)
{
  int	it;

  it = 0;
  while (g_separators[it] != 0)
    {
      if (g_separators[it] == c)
	return (1);
      it++;
    }
  return (0);
}

char	*tds_next_keyword(t_file *file)
{
  char	cur;
  char	*rtn;
  int	it;

  cur = read_char(file);
  while (cur != '\0' && tds_is_separator(cur))
    cur = read_char(file);
  it = 0;
  rtn = NULL;
  while (cur != '\0' && !tds_is_separator(cur))
    {
      if (it % TDS_KEYWORD_BUFFER == 0)
	{
	  if ((rtn = ts_realloc(rtn, it, it + TDS_KEYWORD_BUFFER + 1)) == NULL)
	    return (NULL);
	}
      rtn[it++] = cur;
      cur = read_char(file);
    }
  if (rtn != NULL)
    rtn[it] = '\0';
  return (rtn);
}
