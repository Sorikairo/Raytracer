/*
** xfunct.c for xfunct in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Wed May 28 11:39:05 2014 Barneaud Viveka
** Last update Thu Jun  5 11:19:32 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<string.h>
#include	<errno.h>

void		*xmalloc_and_set(void *ptr, size_t size)
{
  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Error in malloc\n");
      exit(EXIT_FAILURE);
    }
  ptr = memset(ptr, 0, size);
  return (ptr);
}

int		xsocket(const int family, const int type, const int protonum)
{
  int		sockfd;

  if ((sockfd = socket(family, type, protonum)) < 0)
    {
      perror("Socket");
      exit(EXIT_FAILURE);
    }
  return (sockfd);
}

void		xbind(const int sockfd, struct sockaddr *srv, size_t len)
{
  if (bind(sockfd, srv, len) == -1)
    {
      perror("Bind");
      free(srv);
      exit(EXIT_FAILURE);
    }
}

void		xconnect(const int sockfd, struct sockaddr *srv, size_t len)
{
  if (connect(sockfd, srv, len) < 0)
    {
      free(srv);
      perror("Connect");
      exit(EXIT_FAILURE);
    }
}

int		xaccept(const int sockfd, struct sockaddr *client, socklen_t *len)
{
  int		connfd;

  if ((connfd = accept(sockfd, client, len)) < 0)
    {
      perror("Accept");
      exit(EXIT_FAILURE);
    }
  return (connfd);
}
