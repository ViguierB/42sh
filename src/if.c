/*
** if.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May  7 20:17:55 2017 Alexandre Chamard-bois
** Last update Sat May 20 11:04:10 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include "libmy.h"
#include "mysh.h"
#include "script.h"

int print_if()
{
  if (isatty(0))
    my_printf("if? ");
  return (1);
}

t_clist *recup_if(t_mysh *sh, int last_ret)
{
  t_clist *list;
  int then;
  char *str;

  then = 0;
  list = NULL;
  while (then != 2 && print_if() && (str = my_getline(sh->in)))
  {
    if (!my_strcmp(str, "else"))
      then = 1;
    else if (!my_strcmp(str, "endif"))
      then = 2;
    if (last_ret == then)
      list = clist_push(list, str);
  }
  if (!str)
    return (NULL);
  return (list);
}

int exec_if(t_mysh *sh)
{
  t_clist *list;
  t_clist *next;

  if (!(list = recup_if(sh, sh->last_exit)))
  {
    if (!sh->last_exit)
    {
      if (isatty(0))
      my_printf("Empty if.\n");
      return (1);
    }
    return (0);
  }
  list->prev->next = NULL;
  while (list)
  {
    do_cmd(sh, list->ptr);
    next = list->next;
    free(list->ptr);
    free(list);
    list = next;
  }
  return (0);
}

int my_if(char **tab, t_mysh *sh)
{
  char **cond;
  char *str;
  int i;

  i = 3;
  if (!(cond = recup_parentheses(tab + 1, &i)))
    return (1);
  str = concatene_cond(cond);
  do_cmd(sh, str);
  if (sh->last_exit == 2)
    return (2);
  free(cond);
  free(str);
  if (!(str = wordtab_to_str(tab + i)))
  {
    if (isatty(0))
      my_printf("Empty if.\n");
  }
  else if (my_strcmp(str, "then"))
    do_cmd(sh, str);
  else
    exec_if(sh);
  free(str);
  return (0);
}
