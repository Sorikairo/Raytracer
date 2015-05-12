/*
** get_type.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 16:58:43 2014 Laurent Fourrier
** Last update Thu Mar 13 16:06:15 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "tds.h"

t_tds_type	g_tds_type[] =
  {
    {TDS_TYPE_INT8, "INT8", 1,
     &tds_type_int8, &tcs_type_int8, &tcs_wtype_int8},
    {TDS_TYPE_INT16, "INT16", 2,
     &tds_type_int16, &tcs_type_int16, &tcs_wtype_int16},
    {TDS_TYPE_INT32, "INT32", 4,
     &tds_type_int32, &tcs_type_int32, &tcs_wtype_int32},
    {TDS_TYPE_STR, "STR", TDS_SIZE_UNKWN,
     &tds_type_ascii, &tcs_type_ascii, &tcs_wtype_ascii},
    {TDS_TYPE_FLT32, "FLT32", 4,
     &tds_type_float32, &tcs_type_float32, &tcs_wtype_float32},
    {TDS_TYPE_FLT64, "FLT64", 8,
     &tds_type_float64, &tcs_type_float64, &tcs_wtype_float64},
    {TDS_TYPE_UNKWN, NULL, TDS_SIZE_UNKWN, NULL, NULL, NULL}
  };

t_tds_type	tds_get_type_from_bytecode(char bytecode)
{
  int		it;

  it = 0;
  while (g_tds_type[it].bytecode != TDS_TYPE_UNKWN)
    {
      if (g_tds_type[it].bytecode == bytecode)
	return (g_tds_type[it]);
      it++;
    }
  return (g_tds_type[it]);
}

t_tds_type	tds_get_type_from_name(char *name)
{
  int		it;

  it = 0;
  while (g_tds_type[it].bytecode != TDS_TYPE_UNKWN)
    {
      if (utl_strcmp(name, g_tds_type[it].name) == 0)
	return (g_tds_type[it]);
      it++;
    }
  return (g_tds_type[it]);
}
