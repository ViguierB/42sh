/*
** var.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:01:10 2017 Alexandre Chamard-bois
** Last update Sun May 21 21:15:00 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include "mysh.h"
#include "var.h"

int	error_set(char *str)
{
  if (!str || *str == '?')
    return (0);
  if (!ALPHA(*str))
    {
      my_printf("set: Variable name must begin with a letter.\n");
      return (1);
    }
  while (*str)
    {
      if (!ALPHNUM(*str))
	{
	  my_printf("set: Variable name must contain alphanumeric "
		    "characters.\n");
	  return (1);
	}
      str++;
    }
  return (0);
}

static inline int	change_info(t_var_elm *var, char **tab, int i)
{
  char			*egal;

  egal = NULL;
  if (var->value.ptr)
    free(var->value.ptr);
  if (tab[1] && !my_strcmp(tab[1], "=") && tab[2])
    egal = my_strdup(tab[2]);
  var->value.ptr = egal;
  if (my_strcmp(tab[1], "="))
    return (2);
  return (MIN(i, 3));
}

static int	recup_info(t_mysh *mysh, t_var_elm *var, char **tab, int i)
{
  char			*name;
  char			*egal;

  egal = NULL;
  if (!(name = my_strdup(*tab)))
    return (84);
  if (tab[1] && !my_strcmp(tab[1], "=") && tab[2])
    egal = my_strdup(tab[2]);
  var->value.ptr = egal;
  var->name = name;
  mysh->var = clist_push(mysh->var, var);
  if (i >= 3 && my_strcmp(tab[1], "="))
    return (2);
  return (MIN(i, 3));
}

int		new_var(t_mysh *mysh, char **tab, int i)
{
  t_var_elm	*new_var;

  if (!(new_var = malloc(sizeof(t_var_elm))))
    return (1);
  my_memset(new_var, 0, sizeof(t_var_elm));
  return (recup_info(mysh, new_var, tab, i));
}

int	my_set(char **tab, t_mysh *mysh)
{
  int	i;
  int	nb_line;
  t_var *elm;

  nb_line = my_nbline(tab);
  i = 1;
  if (nb_line == 1)
    print_var(mysh);
  while (i < nb_line)
    {
      elm = mysh->var;
      while (elm && my_strcmp(NAME(elm), tab[i]))
	elm = CLIST_NEXT(mysh->var, elm);
      if (!elm)
	{
	  if (error_set(tab[i]))
	    return (1);
	  i += new_var(mysh, tab + i, nb_line - i);
	}
      else
	i += change_info(elm->ptr, tab + i, nb_line - i);
    }
  return (0);
}
