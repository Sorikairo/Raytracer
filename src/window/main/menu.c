/*
** menu.c for rt in /home/deffon_k/repo-raytracer
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Jun  6 17:32:08 2014 deffontaine kevin
** Last update Sun Jun  8 12:46:46 2014 Laurent Fourrier
*/

#include "window.h"

void		creat_menu(t_menu *menu, t_init *init)
{
  menu->menu_bar = gtk_menu_bar_new();
  menu->menu = gtk_menu_new();
  menu->menu_item = gtk_menu_item_new_with_mnemonic("File");
  menu->open = gtk_menu_item_new_with_mnemonic("Open");
  gtk_menu_shell_append(GTK_MENU_SHELL(GTK_MENU(menu->menu)), menu->open);
  menu->save_as = gtk_menu_item_new_with_mnemonic("Save as");
  gtk_menu_shell_append(GTK_MENU_SHELL(GTK_MENU(menu->menu)), menu->save_as);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu->menu_item), menu->menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu->menu_bar), menu->menu_item);
  menu->menu = gtk_menu_new();
  menu->menu_item = gtk_menu_item_new_with_mnemonic("Edit");
  menu->server = gtk_menu_item_new_with_mnemonic("Server");
  gtk_menu_shell_append(GTK_MENU_SHELL(GTK_MENU(menu->menu)), menu->server);
  menu->run = gtk_menu_item_new_with_mnemonic("Run");
  gtk_menu_shell_append(GTK_MENU_SHELL(GTK_MENU(menu->menu)), menu->run);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu->menu_item), menu->menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu->menu_bar), menu->menu_item);
  gtk_box_pack_start(GTK_BOX(init->vbox),
		     GTK_WIDGET(GTK_MENU_BAR(menu->menu_bar)), FALSE, FALSE, 0);
}
