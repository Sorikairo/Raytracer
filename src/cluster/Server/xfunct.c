/*
** xfunct.c for xfunct_srv in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Fri May 30 12:05:32 2014 Barneaud Viveka
** Last update Sat May 31 10:19:22 2014 Barneaud Viveka
*/

#include	<sys/select.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>

void		xselect(const int sockfd, fd_set *readfds, fd_set *writefds,
			fd_set *exceptfds, struct timeval *tv)
{
  if (select(sockfd, readfds, writefds, exceptfds, tv) == -1)
    {
      perror("Select");
      exit(EXIT_FAILURE);
    }
}
