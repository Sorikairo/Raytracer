/*
** init_struct.c for raytracer in /home/fouhet_k/Perso/raytracer/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun Jun  1 16:00:09 2014 Kevin Fouhety
** Last update Sat Jun  7 22:30:32 2014 Kevin Fouhety
*/

#include "obj_parsing.h"

void	init_list_obj(t_obj_list **list)
{
  if ((*list = malloc (sizeof (t_obj_list))) == NULL)
    {
      write(1, "Error, malloc list_obj\n", 24);
      exit(0);
    }
  (*list)->text = NULL;
  (*list)->vect = NULL;
  (*list)->i = 1;
  (*list)->n = 1;
}

void	init_elem_poly(t_poly **elem)
{
  if ((*elem = malloc (sizeof (t_poly))) == NULL)
    {
      write(1, "Error, malloc elem_obj\n", 24);
      exit(0);
    }
}
