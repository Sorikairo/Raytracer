/*
** matrice_calcul.c<2> for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 03:01:11 2014 
** Last update Fri Jun  6 15:11:58 2014 
*/

#include <math.h>
#include <tmath.h>
#include <stdio.h>
#include <stdlib.h>

void	init(double *matrice)
{
  int	i;

  i = 0;
  while (i < 9)
    matrice[i++] = 0.00;
  matrice[0] = 1.00;
  matrice[4] = 1.00;
  matrice[8] = 1.00;
}

double	*rotation_z(double angle)
{
  double	*matrice;

  angle = M_PI * angle / 180.00;
  if ((matrice = malloc(9 * sizeof(double))) == NULL)
    exit(0);
  init(matrice);
  matrice[0] = cos(angle);
  matrice[1] = sin(angle);
  matrice[3] = -sin(angle);
  matrice[4] = cos(angle);
  return (matrice);
}

double	*rotation_y(double angle)
{
  double	*matrice;

  angle = M_PI * angle / 180.00;
  if ((matrice = malloc(9 * sizeof(double))) == NULL)
    exit(0);
  init(matrice);
  matrice[0] = cos(angle);
  matrice[6] = sin(angle);
  matrice[2] = -sin(angle);
  matrice[8] = cos(angle);
  return (matrice);
}

double	*rotation_x(double angle)
{
  double	*matrice;

  angle = M_PI * angle / 180.00;
  if ((matrice = malloc(9 * sizeof(double))) == NULL)
    exit(0);
  init(matrice);
  matrice[4] = cos(angle);
  matrice[5] = sin(angle);
  matrice[7] = -sin(angle);
  matrice[8] = cos(angle);
  return (matrice);
}

double	*multiplication(double *matrice1, double *matrice2)
{
  double	*result;

  result = malloc(9 * sizeof(double));
  result[0] = matrice1[0] * matrice2[0] + matrice1[3] * matrice2[1]
    + matrice1[6] * matrice2[2];
  result[1] = matrice1[1] * matrice2[0] + matrice1[4] * matrice2[1]
    + matrice1[7] * matrice2[2];
  result[2] = matrice1[2] * matrice2[0] + matrice1[5] * matrice2[1]
    + matrice1[8] * matrice2[2];
  result[3] = matrice1[0] * matrice2[3] + matrice1[3] * matrice2[4]
    + matrice1[6] * matrice2[5];
  result[4] = matrice1[1] * matrice2[3] + matrice1[4] * matrice2[4]
    + matrice1[7] * matrice2[5];
  result[5] = matrice1[2] * matrice2[3] + matrice1[5] * matrice2[4]
    + matrice1[8] * matrice2[5];
  result[6] = matrice1[0] * matrice2[6] + matrice1[3] * matrice2[7]
    + matrice1[6] * matrice2[8];
  result[7] = matrice1[1] * matrice2[6] + matrice1[4] * matrice2[7]
    + matrice1[7] * matrice2[8];
  result[8] = matrice1[2] * matrice2[6] + matrice1[5] * matrice2[7]
    + matrice1[8] * matrice2[8];
  return (result);
}
