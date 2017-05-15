/*
** preparsing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 13 15:09:25 2017 Alexandre Chamard-bois
** Last update Sat May 13 17:23:45 2017 Alexandre Chamard-bois
*/

#include "mysh.h"

static int _size(char **cmd, char **var)
{
  int i;
  int j;

  i = 0;
  while (cmd[i])
    i++;
  j = 0;
  while (var[j])
    j++;
  return (i + j);
}

int _add_list(char **add, char **new_cmd)
{
  int i;

  i = 0;
  while (add[i])
  {
    new_cmd[i] = add[i];
    i++;
  }
  return (i);
}

char **_replace_in_tab(char **cmd, int unused, char **add)
{
  char **new_cmd;
  int i;
  int j;
  int len;

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
      j += _add_list(add, new_cmd + j);
    i++;
  }
  new_cmd[len] = NULL;
  free(cmd[unused]);
  free(cmd);
  free(add);
  return (new_cmd);
}

int preparsing(t_mysh *mysh, char ***cmd)
{
  t_var *var;
  int i;

  i = 0;
  while ((*cmd)[i])
  {
    if ((*cmd)[i][0] == '$')
    {
      var = mysh->var;
      while (var)
      {
        if (!my_strcmp((*cmd)[i] + 1, NAME(var)))
          *cmd = _replace_in_tab(*cmd, i, my_split(VALUE(var), ' ', NULL));
        var = CLIST_NEXT(mysh->var, var);
      }
    }
    i++;
  }
  return (0);
}
