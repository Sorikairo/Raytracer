/*
** clustering.h for clustering in /home/barnea_v/cluster
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Wed May 28 11:20:22 2014 Barneaud Viveka
** Last update Sun Jun  8 23:39:45 2014 Laurent Fourrier
*/

#ifndef			CLUSTERING_H_
# define		CLUSTERING_H_

# define		SUCCESS	0
# define		FAILURE	1

# include		<sys/socket.h>
# include		<sys/types.h>
# include		<sys/select.h>
# include		<sys/time.h>
# include		"window.h"
# include		"scene.h"

typedef struct		s_client
{
  int			clifd;
  int			clinb;
  int			*buffer;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct		s_img_buff
{
  int			cli_num;
  volatile int		cli_max;
  int			*img;
  size_t		size;
} t_img_buff;

void		*xmalloc_and_set(void *ptr, int size);
int		xsocket(const int family, const int type, const int protonum);
void		xbind(const int sockfd, struct sockaddr *srv, size_t len);
void		xconnect(const int sockfd, struct sockaddr *srv, size_t len);
int		xaccept(const int sfd, struct sockaddr *cli, socklen_t *len);
char		*realloc_and_concat(char *s1, char *s2);
void		xselect(const int sockfd, fd_set *readfds, fd_set *writefds,
			fd_set *exceptfds, struct timeval *tv);
void		clear_fds(int *newfd, fd_set *readfds, int size);
void		recieve_call(const int sockfd, const char *filename,
			     const int cli_max, t_launch_infos *infos);
void		remove_client(t_client **cli, int pos);
void		put_client_in_list(t_client **cli, const int sockfd,
				   const char *filename);
int		count_client(t_client *cli);
void		reinit_fds(t_client **cli);
void		show_clients(t_client *cli);
int		my_strendcmp(char *s1, char *s2);
size_t		my_strlen(char *str);
char		*get_next_line(const int fd);
char		*read_file(const char *filename);
int		main_srv(const int port, t_launch_infos *infos);
void		parse_file(const int sfd, const char *fname, t_img_buff *cl);
void		read_all_clifd(t_client *cli, t_launch_infos *infos);
void		launch_calc(t_client *cli, t_launch_infos *infos);
int		*read_socket(const int sockfd);
char		**my_str_to_wtab(char *str, char *sep);
int		highest_fd(const int sockfd, t_client *cli);
void		read_and_clear_fd(t_client *cli, fd_set *readfds);
void		set_all_fds(t_client *cli, fd_set *readfds);
void		init_scene_client(t_scene *scene);
void		free_clients(t_client *cli);

#endif			/* CLUSTERING_H_ */
