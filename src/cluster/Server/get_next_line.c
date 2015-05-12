/*
** get_next_line.c for get_next_line_c in /home/barnea_v/rendu/get_next_line
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sun Nov 17 06:20:01 2013 Barneaud Viveka
** Last update Sun Jun  8 23:38:31 2014 Laurent Fourrier
*/

#include	<stdlib.h>
#include	<strings.h>
#include	<unistd.h>
#include	"clustering.h"

int		my_count(char *str, int i)
{
  int		j;

  j = 0;
  while (str[i] != '\n' && str[i] != '\0')
    {
      j = j + 1;
      i = i + 1;
    }
  return (j);
}

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;
  static int	dest_len;

  i = 0;
  j = dest_len;
  while (src[i] != '\0')
    {
      dest[j++] = src[i++];
      dest_len++;
    }
  dest[j] = '\0';
  return (dest);
}

char		*my_realloc(char *str, int size)
{
  int		i;
  int		j;
  char		*tmp;
  static int	flag;

  i = 0;
  j = 0;
  tmp = xmalloc_and_set(NULL, sizeof(tmp) * size);
  if (flag != 0)
    {
      while (str[i] != '\0')
        {
          tmp[j] = str[i];
          i = i + 1;
          j = j + 1;
        }
    }
  free(str);
  tmp[j] = '\0';
  flag = flag + 1;
  return (tmp);
}

char		*my_new_buffer(const int fd)
{
  int		ret;
  static char	*tmp;
  char		buffer[4096];
  static int	count;
  static int	flag;

  ret = 1;
  if (fd == -1)
    return (NULL);
  if (flag == 0)
    tmp = xmalloc_and_set(NULL, sizeof(tmp) * 4096);
  bzero(buffer, 4096);
  while (ret != 0 && my_strendcmp("EOF\n", buffer) != 0)
    {
      ret = read(fd, buffer, 4096);
      if (ret == -1)
	return (NULL);
      count = count + ret;
      buffer[ret] = '\0';
      tmp = my_realloc(tmp, count + 1);
      tmp = my_strcat(tmp, buffer);
    }
  flag = 1;
  return (tmp);
}

char		*get_next_line(const int fd)
{
  char		*line;
  static int	i;
  int		l;
  static char	*tmp;
  static int	flag;

  if (flag == 0)
    tmp = my_new_buffer(fd);
  if (tmp == NULL)
    return (NULL);
  line = xmalloc_and_set(NULL, sizeof(line) + my_count(tmp, i));
  l = 0;
  while (tmp[i] != '\n' && tmp[i] != '\0')
    line[l++] = tmp[i++];
  line[l] = '\0';
  if (tmp[i] == '\n')
    i = i + 1;
  else if (tmp[i] == '\0')
    {
      free(tmp);
      free(line);
      return (NULL);
    }
  flag++;
  return (line);
}
