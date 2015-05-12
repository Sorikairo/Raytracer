/*
** window.h for rt in /home/deffon_k/repo-raytracer
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Jun  6 14:58:45 2014 deffontaine kevin
** Last update Sun Jun  8 16:16:17 2014 deffontaine kevin
*/

#ifndef		WINDOW_H_
# define	WINDOW_H_

# include	<gtk/gtk.h>

typedef struct	s_actif
{
  gchar		*path;
  gboolean	save;
  GtkTextView	*text_view;
}		t_actif;

typedef struct	s_docs
{
  GList		*all;
  t_actif	*actif;
}		t_docs;

extern t_docs	docs;

typedef struct	s_menu
{
  GtkWidget	*menu;
  GtkWidget	*menu_item;
  GtkWidget	*menu_bar;
  GtkWidget	*open;
  GtkWidget	*save_as;
  GtkWidget	*server;
  GtkWidget	*run;
}		t_menu;

typedef	struct	s_notebook
{
  GdkImage	*image;
  GtkWidget	*notebook;
  GtkWidget	*tablabel;
  GtkWidget	*scene;
  GtkWidget	*table;
  GtkWidget	*label;
  GtkWidget	*scroll;
  GtkWidget	*text_view;
  GtkTextBuffer	*text_buffer;
}		t_notebook;

typedef struct	s_prog_bar
{
  GtkWidget	*bar;
  GtkAdjustment	*adj;
  GtkWidget	*align;
}		t_prog_bar;

typedef struct	s_init
{
  GtkWidget	*window;
  GtkWidget	*vbox;
}		t_init;

typedef struct	s_launch_infos
{
  GtkWidget	*hbox;
  char		*path;
  t_notebook	*notebook;
  t_prog_bar	*prog_bar;
}		t_launch_infos;

int	mainwindow_main(int argc, char **argv);
void	init_window(int argc, char **argv, t_init *init, t_launch_infos *infos);
void	creat_menu(t_menu *menu, t_init *init);
void	creat_notebook(t_init *init, t_menu *menu, t_launch_infos *infos);
void	creat_prog_bar(t_init *init, t_launch_infos *infos);
gint	prog_timeout(gpointer data);
void	open_gfile(const gchar *file_name, GtkTextView *text_view);
void	open_func(GtkWidget *widgetn, gpointer user_data);
void	save_as_func(GtkWidget *widget, gpointer user_data);
void	launch_rt(GtkWidget *widget, t_launch_infos *infos);
void	render_scene_serv(t_launch_infos *infos, int *nbr);
void	bind_server(t_launch_infos *info, t_menu *menu);

#endif /* WINDOW_H */
