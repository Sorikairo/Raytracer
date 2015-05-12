/*
** get_nearest.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 04:19:42 2014 
** Last update Wed Jun  4 04:20:17 2014 
*/

double	get_nearest(double distance, double distance2)
{
  if (distance > 0.00 && distance2 > 0.00)
    if (distance < distance2)
      return (distance);
    else
      return (distance2);
  else
    if (distance > 0.00)
      return (distance);
    else if (distance2 > 0.00)
      return (distance2);
    else
      return (-1.00);
}
