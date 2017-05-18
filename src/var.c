/*
** var.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:01:10 2017 Alexandre Chamard-bois
** Last update Thu May 18 13:50:34 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include "mysh.h"
#include "var.h"

static inline int recup_info(t_var_elm *var, char **tab, int type)
{
  char *name;
  char *str;

  if (!(str = my_strdup(tab[3])) || !(name = my_strdup(tab[1])))
    return (my_putstr("error malloc\n"), 1);
  if (var->value.ptr)
    free(var->value.ptr);
  var->value.ptr = str;
  var->name = name;
  var->value.type = type;
  return (0);
}

int find_type(char *str)
{
  if (my_isnum(str))
    return (T_INT);
  if (my_isfloat(str))
    return (T_FLOAT);
  return (T_STR);
}

int error_set(char *str)
{
  my_putstr(str);
  return (1);
}

int my_set(char **tab, t_mysh *sh)
{
  int ret;
  t_var *elm;
  t_var_elm *new_var;

  elm = sh->var;
  if (my_nbline(tab) != 4)
    return (error_set("invalid nb arg\n"));
  if (!is_alph_num(tab[1]))
    return (error_set("invalid name\n"));
  while (elm && my_strcmp(NAME(elm), tab[1]))
    elm = CLIST_NEXT(sh->var, elm);
  if (!elm)
  {
    if (!(new_var = malloc(sizeof(t_var_elm))))
      return (error_set("error malloc\n"));
    my_memset(new_var, 0, sizeof(t_var_elm));
    ret = recup_info(new_var, tab, find_type(tab[3]));
    sh->var = clist_push(sh->var, new_var);
  }
  else
    ret = recup_info(elm->ptr, tab, find_type(tab[3]));
  return (ret);
}
