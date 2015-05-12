/*
** color.h for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 02:27:47 2014 Laurent Fourrier
** Last update Wed Jun  4 02:29:08 2014 Laurent Fourrier
*/

#ifndef COLOR_H_
# define COLOR_H_

typedef union	u_color
{
  int		value;
  unsigned char	array[3];
}		t_color;

#endif
