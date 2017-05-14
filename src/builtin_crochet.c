/*
** builtin_crochet.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 11:15:04 2017 Alexandre Chamard-bois
** Last update Sat May 13 14:50:56 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include "mysh.h"
#include "crochet.h"

const t_pars_crochet g_croc[] =
{
  {"-n", 0, _flag_n},
  {"-z", 0, _flag_z},
  {"=", 1, _flag_eg},
  {"==", 1, _flag_eg},
  {"!=", 1, _flag_dif},
  {"-eq", 1, _flag_num},
  {"-ge", 1, _flag_num},
  {"-gt", 1, _flag_num},
  {"-lt", 1, _flag_num},
  {"-le", 1, _flag_num},
  {"-ne", 1, _flag_num},
  {"-d", 0, _flag_d},
  {"-e", 0, _flag_e},
  {"-f", 0, _flag_f},
  {NULL, 0, NULL},
};

static int _pars(char **tab, char *to_pars[4], int i)
{
  int j;

  j = 0;
  my_memset(to_pars, 0, sizeof(char *) * 4);
  if (!my_strcmp(tab[i], "]"))
    return (0);
  i++;
  if (!my_strcmp(tab[i], "!"))
    to_pars[3] = tab[i++];
  while (my_strcmp(tab[i + j], "-a") && my_strcmp(tab[i + j], "-o") &&
          my_strcmp(tab[i + j], "]") && j < 3)
  {
    to_pars[j] = tab[i + j];
    j++;
  }
  if (my_strcmp(tab[i + j], "-a") && my_strcmp(tab[i + j], "-o") &&
          my_strcmp(tab[i + j], "]"))
  {
    dprintf(2, "too many arguments\n");
    return (-1);
  }
  return (i + j);
}

int pars_croc(char *to_pars[4])
{
  int i;

  i = 0;
  while (g_croc[i].flag && my_strcmp(to_pars[g_croc[i].pos], g_croc[i].flag))
    i++;
  if (!g_croc[i].flag)
  {
    if (to_pars[1])
      return (2);
    if (!to_pars[0])
      return ((to_pars[3] ? 0 : 1));
    return ((to_pars[3] ? 1 : 0));
  }
  return (g_croc[i].func(to_pars));
}

int _verif_opt(char **tab, int before, int *res)
{
  static int last = 0;

  if (!my_strcmp(tab[before], "-a") && (last || *res))
  {
    *res = 1;
    return (1);
  }
  if (!my_strcmp(tab[before], "-o") && (!last || !*res))
  {
    *res = 0;
    return (1);
  }
  last = *res;
  return (0);
}

t_mysh builtin_crochet(char **tab, t_mysh sh)
{
  int i;
  char *to_pars[4];
  int before;
  int res;

  res = 1;
  before = 0;
  i = 0;
  if (my_strcmp(tab[my_nbline(tab) - 1], "]"))
    return (dprintf(2, "missing `]'\n"), (t_mysh){sh.env, sh.var, 2});
  while ((i = _pars(tab, to_pars, i)) > 0)
  {
    res = pars_croc(to_pars);
    if (res == 2 || _verif_opt(tab, before, &res))
      break;
    before = i;
  }
  if (i == -1)
    return ((t_mysh){sh.env, sh.var, 2});
  return ((t_mysh){sh.env, sh.var, res});
}
