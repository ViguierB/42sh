/*
** var.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:01:10 2017 Alexandre Chamard-bois
** Last update Wed May 10 21:48:42 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include "mysh.h"
#include "var.h"

static inline int recup_info(t_var_elm *var, char **tab, int type)
{
  char *name;
  char *str;

  if (!(str = my_strdup(tab[2])) || !(name = my_strdup(tab[1])))
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

t_mysh built_set(char **tab, t_mysh sh)
{
  t_var *elm;
  t_var_elm *new_var;

  elm = sh.var;
  if (my_nbline(tab) != 3)
    return (my_putstr("invalid nb arg\n"), (t_mysh){sh.env, sh.var, 1});
  if (is_alph_num(tab[1]))
    return (my_putstr("invalid name\n"), (t_mysh){sh.env, sh.var, 1});
  while (elm && my_strcmp(NAME(elm), tab[1]))
    elm = CLIST_NEXT(sh.var, elm);
  if (!elm)
  {
    if (!(new_var = malloc(sizeof(t_var_elm))))
      return (my_putstr("error malloc\n"), (t_mysh){sh.env, sh.var, 1});
    my_memset(new_var, 0, sizeof(t_var_elm));
    sh.last_exit = recup_info(new_var, tab, find_type(tab[2]));
    sh.var = clist_push(sh.var, new_var);
  }
  else
    sh.last_exit = recup_info(elm->ptr, tab, find_type(tab[2]));
  return ((t_mysh){sh.env, sh.var, 0});
}

void echo_var(t_mysh sh, char **tab)
{
  t_var *elm;

  elm = sh.var;
  if (my_nbline(tab) != 2 || *(tab[1]) != '$')
  {
    my_printf("%s isn't a varialbe\n", tab[1]);
    return;
  }
  while (elm && my_strcmp(NAME(elm), tab[1] + 1))
  {
    elm = CLIST_NEXT(sh.var, elm);
  }
  if (elm)
  {
    if (INT(elm))
      printf("%s=%d\n", NAME(elm), my_atoi(VALUE(sh.var)));
    if (FLOAT(elm))
      printf("%s=%f\n", NAME(elm), my_atof(VALUE(sh.var)));
    if (STR(elm))
      printf("%s=%s\n", NAME(elm), (char*)VALUE(sh.var));
  }
}

int main()
{
  t_mysh sh;
  char *buff;
  t_my_fd	*in;

  my_memset(&sh, 0, sizeof(t_mysh));
  in = my_fd_from_fd(0);
  while ((buff = my_getline(in)))
  {
    if (!my_strncmp(buff, "set", 3))
      built_set(my_split(buff, ' ', NULL), sh);
    if (!my_strncmp(buff, "echo", 4))
      echo_var(sh, my_split(buff, ' ', NULL));
    free(buff);

  }
  return (0);
}
