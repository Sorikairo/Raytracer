/*
** main.c for client in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Wed May 28 10:44:43 2014 Barneaud Viveka
** Last update Sun Jun  8 23:14:53 2014 Laurent Fourrier
*/

#include		<sys/types.h>
#include		<stdio.h>
#include		<errno.h>
#include		<string.h>
#include		<stdlib.h>
#include		<netdb.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<unistd.h>
#include		<strings.h>
#include		<fcntl.h>
#include		<sys/stat.h>
#include		<unistd.h>
#include		<tio.h>
#include		"clustering.h"

int			connect_to_server(int protonum, char *ip, int port)
{
  struct sockaddr_in	*srv_addr;
  int			sockfd;

  sockfd = xsocket(AF_INET, SOCK_STREAM, protonum);
  srv_addr = xmalloc_and_set(NULL, sizeof(*srv_addr));
  srv_addr->sin_family = AF_INET;
  srv_addr->sin_addr.s_addr = inet_addr(ip);
  srv_addr->sin_port = htons(port);
  xconnect(sockfd, (struct sockaddr *)srv_addr, sizeof(*srv_addr));
  free(srv_addr);
  return (sockfd);
}

int			read_srvsocket(const int sockfd, t_img_buff *cli_img)
{
  char			*buffer;
  char			*line;
  int			fd;

  buffer = xmalloc_and_set(NULL, sizeof(*buffer) * 4096);
  line = get_next_line(sockfd);
  cli_img->cli_num = atoi(line);
  while ((line = get_next_line(sockfd)) != NULL)
    {
      buffer = realloc_and_concat(buffer, line);
      buffer = realloc_and_concat(buffer, "\n");
    }
  if ((fd = open("config.tds", O_TRUNC | O_RDWR)) < 0)
    {
      if ((fd = open("config.tds", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR |
		     S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
	exit(EXIT_FAILURE);
    }
  buffer[strlen(buffer) - 4] = 0;
  if (write(fd, buffer, strlen(buffer)) < 0)
    exit(EXIT_FAILURE);
  fprintf(stdout, "File successfully created\n");
  if (close(fd) < 0)
    exit(EXIT_FAILURE);
  return (SUCCESS);
}

int			write_on_socket(const int sockfd, t_img_buff *cli_img)
{
  usleep(10000 * cli_img->cli_num);
  write(sockfd, cli_img->img, cli_img->size * sizeof(int));
  printf("\nDone\n");
  return (SUCCESS);
}

int			main(int argc, char **argv)
{
  int			protonum;
  int			sockfd;
  int			port;
  t_img_buff		cli_img;

  open_fstd();
  if (argc <= 3)
    return (fprintf(stderr, "Usage : ./client protocol_number IP port\n"));
  protonum = atoi(argv[1]);
  port = atoi(argv[3]);
  sockfd = connect_to_server(protonum, argv[2], port);
  read_srvsocket(sockfd, &cli_img);
  parse_file(sockfd, "config.tds", &cli_img);
  write_on_socket(sockfd, &cli_img);
  close_fstd();
  return (SUCCESS);
}
