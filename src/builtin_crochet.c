/*
** builtin_crochet.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 11:15:04 2017 Alexandre Chamard-bois
** Last update Thu May 11 11:25:20 2017 Alexandre Chamard-bois
*/

#include "mysh.h"

t_mysh bultin_crochet(char **tab, t_mysh sh)
{
  int i;

  if (my_strcmp(tab[my_nbline(tab) - 1], "]"))
    return (my_printf("missing ']'\n"), (t_mysh){sh.env, sh.var, 2});
  i = 1;
  while (tab[i])
  {
    i++;
  }
  return (sh);
}
