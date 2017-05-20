/*
** foreach.c for o in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 20 11:11:48 2017 Alexandre Chamard-bois
** Last update Sat May 20 11:28:24 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include "libmy.h"
#include "mysh.h"
#include "script.h"

int print_foreach()
{
  if (isatty(0))
    my_printf("foreach? ");
  return (1);
}

t_clist *recup_foreach(t_mysh *sh)
{
  t_clist *list;
  int then;
  char *str;

  then = 0;
  list = NULL;
  while (!then && print_foreach() && (str = my_getline(sh->in)))
  {
    if (my_strcmp(str, "end"))
      list = clist_push(list, str);
    else
      then = 1;
  }
  if (!str)
    return (NULL);
  return (list);
}

int exec_foreach(t_mysh *sh, t_clist *list)
{
  t_clist *tmp;

  tmp = list;
  while (tmp)
  {
    do_cmd(sh, tmp->ptr);
    tmp = CLIST_NEXT(list, tmp);
  }
  return (0);
}

int my_foreach(char **tab, t_mysh *sh)
{
  t_clist *list;
  char **to_set;
  int nb;
  int i;

  nb = 4;
  if (my_nbline(tab) < 4)
    return (1);
  if (!(to_set = recup_parentheses(tab + 2, &nb)))
    return (1);
  if (tab[nb])
  {
    my_printf("foreach: Words not parenthesized.\n");
    return (1);
  }
  list = recup_foreach(sh);
  i = 0;
  while (to_set[i])
  {
    if (var_set(sh, tab[1], to_set[i]))
      return (1);
    exec_foreach(sh, list);
    i++;
  }
  return (0);
}
