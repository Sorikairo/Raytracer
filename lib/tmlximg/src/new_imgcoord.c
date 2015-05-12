/*
** new_imgcoord.c for tmlximg in /home/fourri_l/Projects/lib/tmlximg
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb  3 11:51:28 2014 Laurent Fourrier
** Last update Mon Feb  3 11:52:00 2014 Laurent Fourrier
*/

#include "tmlximg.h"

t_imgcoord	new_imgcoord(int x, int y)
{
  t_imgcoord	rtn;

  rtn.x = x;
  rtn.y = y;
  return (rtn);
}
