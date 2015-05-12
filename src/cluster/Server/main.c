/*
** main.c for server in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Wed May 28 10:39:07 2014 Barneaud Viveka
** Last update Sun Jun  8 18:39:40 2014 Barneaud Viveka
*/

#include		<netdb.h>
#include		<stdio.h>
#include		<errno.h>
#include		<string.h>
#include		<netinet/in.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<tio.h>
#include		"scene.h"
#include		"parsing.h"
#include		"clustering.h"
#include		"window.h"

int			getprotonum()
{
  struct protoent	*ptc;

  ptc = getprotobyname("tcp");
  if (ptc == NULL)
    exit(EXIT_FAILURE);
  return (ptc->p_proto);
}

int			create_socket(int protonum, int port)
{
  struct sockaddr_in	*srv_addr;
  int			sockfd;

  srv_addr = xmalloc_and_set(NULL, sizeof(*srv_addr));
  srv_addr->sin_family = AF_INET;
  srv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
  srv_addr->sin_port = htons(port);
  sockfd = xsocket(AF_INET, SOCK_STREAM, protonum);
  xbind(sockfd, (struct sockaddr *)srv_addr, sizeof(*srv_addr));
  if (listen(sockfd, SOMAXCONN) == -1)
    exit(EXIT_FAILURE);
  free(srv_addr);
  return (sockfd);
}

static int		tds_is_valid(char *path)
{
  t_file		*file;
  t_scene		scene;

  file = open_file(path, FILE_R);
  init_scene_client(&scene);
  return (parse_scene(&scene, file));
}

int			main_srv(const int port, t_launch_infos *infos)
{
  int			protonum;
  int			sockfd;
  char			*buffer;

  protonum = getprotonum();
  fprintf(stdout, "Protocol number : %d\n", protonum);
  sockfd = create_socket(protonum, port);
  if (!tds_is_valid(infos->path))
    exit(0);
  buffer = read_file(infos->path);
  recieve_call(sockfd, buffer, 4, infos);
  free(buffer);
  perror("Server");
  return (SUCCESS);
}
