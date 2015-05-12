/*
** reset_eye.c for reset_eye in /home/barnea_v/rendu/MUL_2013_raytracer
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Fri Jun  6 15:21:21 2014 Barneaud Viveka
** Last update Sun Jun  8 01:24:59 2014 deffontaine kevin
*/

#include <stdlib.h>
#include <mlx.h>
#include <tio.h>
#include <stdio.h>
#include "parsing.h"
#include "scene.h"
#include "clustering.h"

void		reset_eye(t_scene *scene, double x, double y)
{
  scene->eye->intersection.exist = 0;
  scene->eye->intersection.color.value = 0x00000000;
  scene->eye->intersection.dist = 10000000000000000.0;
  scene->eye->vec.x = 1000.0;
  scene->eye->vec.y = 800.0 / 2.0 - x;
  scene->eye->vec.z = 600.0 / 2.0 - y;
  scene->eye->temp_vec.x = scene->eye->vec.x;
  scene->eye->temp_vec.y = scene->eye->vec.y;
  scene->eye->temp_vec.z = scene->eye->vec.z;
}
