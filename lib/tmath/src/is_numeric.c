/*
** is_numeric.c for tmath in /home/fourri_l/Projects/lib/tmath
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec  7 00:13:03 2013 Laurent Fourrier
** Last update Sat Dec  7 00:15:30 2013 Laurent Fourrier
*/

int	is_numeric(char *str)
{
  int	it;

  it = 0;
  while (str[it] != '\0')
    {
      if (str[it] < '0' && str[it] > '9' && str[it] != '-')
	return (0);
      it++;
    }
  return (1);
}
