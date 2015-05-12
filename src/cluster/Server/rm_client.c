/*
** rm_client.c for rm_client in /home/barnea_v/cluster/multicli
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sat May 31 14:12:00 2014 Barneaud Viveka
** Last update Fri Jun  6 12:09:06 2014 Barneaud Viveka
*/

#include		<netdb.h>
#include		<stdio.h>
#include		<errno.h>
#include		<string.h>
#include		<netinet/in.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		"clustering.h"

void			show_clients(t_client *cli)
{
  int			i;
  t_client		*tmp;

  tmp = cli;
  i = 1;
  while (tmp != NULL)
    {
      printf("client no %d : %d\n", i, tmp->clifd);
      i++;
      tmp = tmp->next;
    }
}

void			remove_client(t_client **cli, int delfd)
{
  if (*cli == NULL)
    return;
  while (*cli != NULL && (*cli)->clifd != delfd)
    *cli = (*cli)->next;
  if (*cli == NULL)
    return;
  (*cli)->clifd = -1;
}

int			count_client(t_client *cli)
{
  t_client		*tmp;
  int			count;

  tmp = cli;
  count = 0;
  while (tmp != NULL)
    {
      if (tmp->clifd != -1)
	count++;
      tmp = tmp->next;
    }
  return (count);
}

void			reinit_fds(t_client **cli)
{
  while ((*cli)->prev != NULL)
    *cli = (*cli)->prev;
}
