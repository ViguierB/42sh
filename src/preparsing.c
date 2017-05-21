/*
** preparsing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 13 15:09:25 2017 Alexandre Chamard-bois
** Last update Sun May 21 21:07:41 2017 alexandre Chamard-bois
*/

#include "42shrc.h"
#include "mysh.h"

static int	_size(char **cmd, char **var)
{
  int		i;
  int		j;

  i = 0;
  while (cmd[i])
    i++;
  j = 0;
  if (var)
    {
      while (var[j])
        j++;
    }
  return (i + j);
}

int	_add_tab(char **add, char **new_cmd)
{
  int	i;

  if (!add)
    return (0);
  i = 0;
  while (add[i])
    {
      new_cmd[i] = add[i];
      i++;
    }
  return (i);
}

char	**_replace_in_tab(char **cmd, int unused, char **add)
{
  char	**new_cmd;
  int	i;
  int	j;
  int	len;

  len = _size(cmd, add) - 1;
  if (!(new_cmd = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (cmd[i])
    {
      if (i != unused)
	new_cmd[j++] = cmd[i];
      else
	j += _add_tab(add, new_cmd + j);
      i++;
    }
  new_cmd[len] = NULL;
  free(cmd[unused]);
  free(cmd);
  if (add)
    free(add);
  return (new_cmd);
}

int     preparsing_env(t_mysh *mysh, char ***cmd)
{
  char  *var_env;
  int   i;

  i = 0;
  while ((*cmd)[i])
    {
      while ((*cmd)[i] && (*cmd)[i][0] == '$')
        {
	  if ((var_env = find_var(mysh->var, mysh->env, (*cmd)[i] + 1)))
            {
	      if (!(*cmd =
                    _replace_in_tab(*cmd, i, my_split(var_env, ' ', NULL))))
		return (1);
	      free(var_env);
            }
	  else
            if (!(*cmd = _replace_in_tab(*cmd, i, NULL)))
	      return (1);
        }
      if (!(*cmd)[i])
	break;
      i++;
    }
  return (0);
}

int	preparsing(t_mysh *mysh, char ***cmd)
{
  char	*alias;

  if ((alias = find_alias(mysh->alias, (*cmd)[0])))
    {
      if (!(*cmd = _replace_in_tab(*cmd, 0, my_split(alias, ' ', NULL))))
	return (1);
      free(alias);
    }
  return (preparsing_env(mysh, cmd));
}
