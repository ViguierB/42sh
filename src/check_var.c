/*
** check_var.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Tue May 16 19:03:13 2017 Guilhem Fulcrand
** Last update Sun May 21 20:19:32 2017 alexandre Chamard-bois
*/

#include "var.h"
#include "my_env.h"
#include "mysh.h"

char		*find_var(t_clist *var, t_clist *env, char *cmd)
{
  t_clist	*tmp;

  tmp = var;
  while (tmp)
    {
      if (my_strcmp(NAME(tmp), cmd) == 0)
	return (my_strdup(VALUE(tmp)));
      tmp = CLIST_NEXT(var, tmp);
    }
  tmp = env;
  while (tmp)
    {
      if (my_strcmp(GET_KEY(tmp), cmd) == 0)
	return (my_strdup(GET_VALUE(tmp)));
      tmp = CLIST_NEXT(env, tmp);
    }
  return (NULL);
}
