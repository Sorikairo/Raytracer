/*
** read_inf.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 31 16:53:46 2014 Kevin Fouhety
** Last update Thu Jun  5 12:03:41 2014 Kevin Fouhety
*/

# include "obj_parsing.h"
# include <fcntl.h>

int     my_strlen_obj(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char    *my_strcat_obj(char *str, char *buffer)
{
  char  *ret;
  int   i;
  int   n;

  i = 0;
  n = 0;
  ret = x_malloc(my_strlen_obj(str) + my_strlen_obj(buffer) + 1);
  while (str[i] != '\0')
    {
      ret[i] = str[i];
      i++;
    }
  while (buffer[n] != '\0')
    {
      ret[i + n] = buffer[n];
      n++;
    }
  ret[i + n] = '\0';
  free(str);
  return (ret);
}

char    *read_inf(char *path)
{
  char  *str;
  char  buffer[65536];
  int   ret;
  int   fd;

  if ((str = x_malloc(1)) == NULL)
    exit(0);
  str[0] = '\0';
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      write(1, "Error in open\n", 14);
      return (NULL);
    }
  while ((ret = read(fd, buffer, 65535)))
    {
      buffer[ret] = '\0';
      str = my_strcat_obj(str, buffer);
    }
  close(fd);
  return (str);
}
