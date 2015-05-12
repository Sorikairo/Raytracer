/*
** tstdio.h for tstdio in /home/fourri_l/Projects/lib/tstdio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 14:00:28 2013 Laurent Fourrier
** Last update Fri Jan  3 14:31:01 2014 Laurent Fourrier
*/

#ifndef TSTDIO_H_
# define TSTDIO_H_

# define T_STDIN	0
# define T_STDOUT	1
# define T_STDERR	2

# define TSTDIO_BUFSIZE	1024

/*
** Writing
*/
void	out_char(int fd, char c);
void	out_str(int fd, char *str);

/*
** Reading
*/
char	in_char(int fd);
char	*in_line(int fd);

#endif
