/*
** launch.c for launch in /home/barnea_v/rendu/MUL_2013_rt
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sat Jun  7 13:01:07 2014 Barneaud Viveka
** Last update Sun Jun  8 23:07:03 2014 Laurent Fourrier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	<tutils.h>
#include	"clustering.h"
#include	"window.h"

void		launch_calc(t_client *cli, t_launch_infos *infos)
{
  t_client	*tmp;

  tmp = cli;
  usleep(10000);
  while (tmp != NULL)
    {
      if (tmp->clifd != -1)
	dprintf(tmp->clifd, "%d\n", count_client(cli));
      tmp = tmp->next;
    }
  read_all_clifd(cli, infos);
}

int		buff_are_filled(t_client *cli)
{
  t_client	*tmp;

  tmp = cli;
  while (tmp != NULL)
    {
      if (tmp->clifd != -1)
	if (tmp->buffer == NULL || tmp->buffer[0] == 0)
	  return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		*create_master_buffer(t_client *cli)
{
  int		it;
  int		*rtn;

  it = 0;
  rtn = xmalloc_and_set(NULL, sizeof(int) * 600 * 800);
  bzero(rtn, sizeof(int) * 600 * 800);
  while (cli)
    {
      if (cli->buffer)
	{
	  memcpy(rtn + (600 * 200 * it++),
		 cli->buffer, sizeof(int) * 600 * 200);
	}
      cli = cli->next;
    }
  return (rtn);
}

void		read_all_clifd(t_client *cli, t_launch_infos *infos)
{
  fd_set	readfds;
  int		maxfd;
  int		*img;

  while (buff_are_filled(cli) != 0)
    {
      maxfd = highest_fd(0, cli);
      FD_ZERO(&readfds);
      set_all_fds(cli, &readfds);
      xselect(maxfd + 1, &readfds, NULL, NULL, NULL);
      read_and_clear_fd(cli, &readfds);
    }
  img = create_master_buffer(cli);
  render_scene_serv(infos, img);
  free(img);
  free_clients(cli);
}
