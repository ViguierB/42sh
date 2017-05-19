/*
** if.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May  7 20:17:55 2017 Alexandre Chamard-bois
** Last update Fri May 19 21:56:31 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "script.h"

char *conc_with_free(char *str1, char *str2)
{
  char *tmp;

  tmp = my_strconca(str1, str2);
  free(str1);
  return (tmp);
}

char *concatene_cond(char **cond)
{
  int i;
  char *str;
  char *tmp;

  i = 0;
  str = my_strdup("[ ");
  while (cond[i])
  {
    if (!my_strcmp(cond[i], "&&") || !my_strcmp(cond[i], "||"))
    {
      str = conc_with_free(str, "] ");
      str = conc_with_free(str, cond[i]);
      str = conc_with_free(str, " [ ");
    }
    else
    {
      tmp = str_conca(3, str, cond[i], " ");
      free(str);
      str = tmp;
    }
    i++;
  }
  str = conc_with_free(str, "]");
  return (str);
}

t_clist *recup_if(int last_ret)
{
  t_clist *list;
  int then;
  t_my_fd *fd;
  char *str;

  if (!(fd = my_fd_from_fd(0)))
    return (NULL);
  then = 0;
  list = NULL;
  while (then != 2 && !my_printf("if? ") && (str = my_getline(fd)))
  {
    if (!my_strcmp(str, "else"))
      then = 1;
    else if (!my_strcmp(str, "endif"))
      then = 2;
    if (last_ret == then)
      list = clist_push(list, str);
  }
  my_fclose(fd);
  if (!str)
    return (NULL);
  return (list);
}

int exec_if(t_mysh *sh, int last_ret)
{
  t_clist *list;
  t_clist *next;

  if (!(list = recup_if(last_ret)))
  {
    my_printf("Empty if.\n");
    return (1);
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
  int last_ret;

  i = 3;
  (void) sh;
  if (!(cond = recup_parentheses(tab + 1, &i)))
    return (1);
  str = concatene_cond(cond);
  do_cmd(sh, str);
  if ((last_ret = sh->last_exit) == 2)
    return (2);
  free(cond);
  free(str);
  if (!(str = wordtab_to_str(tab + i)))
    my_printf("Empty if.\n");
  else if (my_strcmp(str, "then"))
    do_cmd(sh, str);
  else
    exec_if(sh, last_ret);
  free(str);
  return (last_ret);
}
