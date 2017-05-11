/*
** globbing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:12:44 2017 Alexandre Chamard-bois
** Last update Thu May 11 15:47:10 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "glob.h"

static int _size(char **cmd, t_glob *add)
{
  int i;

  i = 0;
  while (cmd[i])
    i++;
  while (add)
  {
    add = add->next;
    i++;
  }
  return (i);
}

int _add_list(t_glob *add, char **new_cmd, char *cut)
{
  t_glob *next;
  int i;

  i = 0;
  while (add)
  {
    next = add->next;
    new_cmd[i] = add->str + (*add->str == '.' && *cut != '.' ? 2 : 0);
    free(add);
    add = next;
    i++;
  }
  return (i);
}

char **_remplace_cmd(char **cmd, int unused, t_glob *add, char *cut)
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
      j += _add_list(add, new_cmd + j, cut);
    i++;
  }
  new_cmd[len] = NULL;
  free(cmd[unused]);
  free(cmd);
  return (new_cmd);
}

t_glob *_new_path(t_glob *list, char *path)
{
  t_glob *new;

  if (!(new = malloc(sizeof(t_glob))))
    return (list);
  new->str = path;
  new->next = list;
  return (new);
}
