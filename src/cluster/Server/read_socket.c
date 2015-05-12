/*
** read_socket.c for read_socket in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Fri May 30 17:28:18 2014 Barneaud Viveka
** Last update Sun Jun  8 22:53:16 2014 Laurent Fourrier
*/

#include		<netdb.h>
#include		<stdio.h>
#include		<errno.h>
#include		<string.h>
#include		<netinet/in.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		"clustering.h"
#include		"window.h"

int			highest_fd(const int sockfd, t_client *cli)
{
  t_client		*tmp;
  int			max;

  if (cli == NULL)
    return (sockfd);
  tmp = cli;
  max = tmp->clifd;
  while (tmp != NULL)
    {
      if (tmp->clifd > max)
	max = tmp->clifd;
      tmp = tmp->next;
    }
  if (sockfd > max)
    return (sockfd);
  return (max);
}

int			*read_socket(const int sockfd)
{
  int			*img;
  int			bytes_count;

  img = xmalloc_and_set(NULL, sizeof(int) * 600 * 200);
  if ((bytes_count = read(sockfd, img, sizeof(int) * 600 * 200)) < 0)
    {
      perror("Read");
      exit(EXIT_FAILURE);
    }
  else if (bytes_count == 0)
    return (NULL);
  return (img);
}

void			read_and_clear_fd(t_client *cli, fd_set *readfds)
{
  int			*buf;
  t_client		*tmp;

  tmp = cli;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->clifd, readfds))
	{
	  if ((buf = read_socket(tmp->clifd)) == NULL)
	    {
	      remove_client(&cli, tmp->clifd);
	      FD_CLR(tmp->clifd, readfds);
	      return;
	    }
	  else
	    tmp->buffer = buf;
	}
      tmp = tmp->next;
    }
}

void			set_all_fds(t_client *cli, fd_set *readfds)
{
  t_client		*tmp;

  tmp = cli;
  while (tmp != NULL)
    {
      if (tmp->clifd != -1)
	FD_SET(tmp->clifd, readfds);
      tmp = tmp->next;
    }
}

void			recieve_call(const int sockfd, const char *buffer,
				     const int cli_max, t_launch_infos *infos)
{
  fd_set		readfds;
  int			maxfd;
  struct timeval	*tv;
  t_client		*cli;

  xmalloc_and_set(NULL, sizeof(*cli));
  cli = NULL;
  tv = NULL;
  while ("queue")
    {
      FD_ZERO(&readfds);
      FD_SET(sockfd, &readfds);
      set_all_fds(cli, &readfds);
      maxfd = highest_fd(sockfd, cli);
      xselect(maxfd + 1, &readfds, NULL, NULL, tv);
      if (FD_ISSET(sockfd, &readfds))
	put_client_in_list(&cli, sockfd, buffer);
      if (count_client(cli) == cli_max)
	{
	  launch_calc(cli, infos);
	  break;
	}
    }
}
