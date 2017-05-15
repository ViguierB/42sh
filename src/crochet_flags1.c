/*
** crochet_flags1.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 13 10:37:05 2017 Alexandre Chamard-bois
** Last update Sat May 13 15:03:49 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include "libmy.h"
#include "crochet.h"

int _flag_n(char *to_pars[4])
{
  if (to_pars[2])
  {
    dprintf(2, "binary operator expected\n");
    return (2);
  }
  if (!to_pars[1])
    return (REV(0));
  if (!*to_pars)
    return (REV(1));
  return (REV(0));
}

int _flag_z(char *to_pars[4])
{
  if (to_pars[2])
  {
    dprintf(2, "binary operator expected\n");
    return (2);
  }
  if (!to_pars[1])
    return (REV(0));
  if (*to_pars)
    return (REV(1));
  return (REV(0));
}

int _flag_eg(char *to_pars[4])
{
  int ret;

  ret = my_strcmp(to_pars[0], to_pars[2]);
  if (ret == -1)
    ret = 1;
  return (REV(ret));
}

int _flag_dif(char *to_pars[4])
{
  int ret;

  ret = my_strcmp(to_pars[0], to_pars[2]);
  if (ret == 0)
    ret = 1;
  else
    ret = 0;
  return (REV(ret));
}

int _flag_num(char *to_pars[4])
{
  if (!my_isfloat(to_pars[0]) || !my_isfloat(to_pars[2]))
  {
    dprintf(2, "integer expression expected\n");
    return (2);
  }
  if (!my_strcmp(to_pars[1], "-eq") &&
      my_atof(to_pars[0]) == my_atof(to_pars[0]))
    return (REV(0));
  if (!my_strcmp(to_pars[1], "-ne") &&
      my_atof(to_pars[0]) != my_atof(to_pars[0]))
    return (REV(0));
  if (!my_strcmp(to_pars[1], "-ge") &&
      my_atof(to_pars[0]) >= my_atof(to_pars[0]))
    return (REV(0));
  if (!my_strcmp(to_pars[1], "-gt") &&
      my_atof(to_pars[0]) > my_atof(to_pars[0]))
    return (REV(0));
  if (!my_strcmp(to_pars[1], "-le") &&
      my_atof(to_pars[0]) <= my_atof(to_pars[0]))
    return (REV(0));
  if (!my_strcmp(to_pars[1], "-lt") &&
      my_atof(to_pars[0]) < my_atof(to_pars[0]))
    return (REV(0));
  return (REV(1));
}
