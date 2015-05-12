/*
** manage_client.c for manage_client in /home/barnea_v/rendu/PSU_2013_42sh/src/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue Jun  3 15:40:48 2014 Barneaud Viveka
** Last update Sun Jun  8 15:18:18 2014 Barneaud Viveka
*/

#include		<netdb.h>
#include		<stdio.h>
#include		<errno.h>
#include		<string.h>
#include		<netinet/in.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		"clustering.h"

char			*read_file(const char *filename)
{
  char			*buffer;
  char			*line;
  int			fd;

  if ((fd = open(filename, O_RDONLY)) < 0)
    {
      fprintf(stderr, "%s : no such file or directory\n", filename);
      exit(EXIT_FAILURE);
    }
  buffer = xmalloc_and_set(NULL, sizeof(*buffer) * 4096);
  while ((line = get_next_line(fd)) != NULL)
    {
      buffer = realloc_and_concat(buffer, line);
      buffer = realloc_and_concat(buffer, "\n");
    }
  buffer = realloc_and_concat(buffer, "EOF\n");
  if (close(fd) < 0)
    exit(EXIT_FAILURE);
  return (buffer);
}

void			put_client_in_list(t_client **cli, const int sockfd,
					   const char *buffer)
{
  struct sockaddr_in	cli_addr;
  static int		cli_num;
  socklen_t		cli_len;
  t_client		*elem;

  elem = xmalloc_and_set(NULL, sizeof(*elem));
  elem->next = *cli;
  elem->prev = NULL;
  if (elem->next != NULL)
    elem->next->prev = elem;
  *cli = elem;
  cli_len = sizeof(cli_addr);
  elem->clifd = xaccept(sockfd, (struct sockaddr *)(&cli_addr), &cli_len);
  elem->clinb = cli_num;
  printf("Connexion du client %d\n", elem->clifd);
  dprintf(elem->clifd, "%d\n", cli_num);
  dprintf(elem->clifd, "%s", buffer);
  cli_num++;
}

void			free_clients(t_client *cli)
{
  t_client		*tmp;

  tmp = cli;
  while (tmp != NULL)
    {
      tmp = cli->next;
      free(cli->buffer);
      free(cli);
      cli = tmp;
    }
}
