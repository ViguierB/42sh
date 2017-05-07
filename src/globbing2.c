/*
** globbing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:12:44 2017 Alexandre Chamard-bois
** Last update Sun May  7 11:20:16 2017 Alexandre Chamard-bois
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

char **_remplace_cmd(char **cmd, int unused, t_glob *add)
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
      while (add)
      {
        new_cmd[j++] = add->str;
        add = add->next;
      }
    i++;
  }
  new_cmd[len] = NULL;
  return (new_cmd);
}

void _print_add(t_glob *add)
{
  while (add)
  {
    my_printf("%s\n", add->str);
    add = add->next;
  }
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
