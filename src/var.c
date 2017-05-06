/*
** var.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:01:10 2017 Alexandre Chamard-bois
** Last update Sat May  6 14:32:49 2017 Alexandre Chamard-bois
*/

#include "mysh.h"
#include "var.h"

t_var *var = NULL;

static inline int recup_int(t_var_elm *var, char **tab, int type)
{
  char *name;
  int *nb;

  if (!(nb = malloc(sizeof(int))) || !(name = my_strdup(tab[1])))
    return (my_putstr("error malloc\n"), 1);
  *nb = my_atoi(tab[2]);
  if (var->ptr)
    free(var->ptr);
  var->ptr = nb;
  var->name = name;
  var->type = type;
  return (0);
}

static inline int recup_float(t_var_elm *var, char **tab, int type)
{
  char *name;
  float *nb_float;

  if (!(nb_float = malloc(sizeof(float))) || !(name = my_strdup(tab[1])))
    return (my_putstr("error malloc\n"), 1);
  *nb_float = my_atof(tab[2]);
  if (var->ptr)
    free(var->ptr);
  var->ptr = nb_float;
  var->name = name;
  var->type = type;
  return (0);
}

static inline int recup_str(t_var_elm *var, char **tab, int type)
{
  char *name;
  char *str;

  if (!(str = my_strdup(tab[2])) || !(name = my_strdup(tab[1])))
    return (my_putstr("error malloc\n"), 1);
  if (var->ptr)
    free(var->ptr);
  var->ptr = str;
  var->name = name;
  var->type = type;
  return (0);
}

int pars_type(char **tab, t_var_elm *var)
{
  if (my_isnum(tab[2]))
  {
    if (my_isfloat(tab[2]))
      return (recup_float(var, tab, T_FLOAT));
    return (recup_int(var, tab, T_INT));
  }
  return (recup_str(var, tab, T_STR));
}

t_mysh built_set(char **tab, t_mysh sh)
{
  t_var *elm;
  t_var_elm *new_var;

  elm = var;
  if (my_nbline(tab) != 3)
    return (my_putstr("invalid nb arg\n"), (t_mysh){sh.env, 1});
  while (elm && my_strcmp(((t_var_elm *) elm->ptr)->name, tab[1]))
    elm = CLIST_NEXT(var, elm);
  if (!elm)
  {
    if (!(new_var = malloc(sizeof(t_var_elm))))
      return (my_putstr("error malloc\n"), (t_mysh){sh.env, 1});
    new_var->ptr = NULL;
    sh.last_exit = pars_type(tab, new_var);
  }
  else
    sh.last_exit = pars_type(tab, elm->ptr);
  return (sh);
}
