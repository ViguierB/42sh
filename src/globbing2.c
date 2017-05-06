/*
** globbing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:12:44 2017 Alexandre Chamard-bois
** Last update Sat May  6 23:42:34 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "glob.h"

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

static int _count_folder(char *cmd)
{
  int i;
  int nb;

  i = 0;
  nb = 0;
  while (cmd[i])
  {
    if (cmd[i] == '/')
      nb++;
    i++;
  }
  return (nb + 1);
}

char **_cut_word(char *cmd)
{
  char **tab;
  int nb_folder;
  int i;
  int start;
  int end;

  nb_folder = _count_folder(cmd);
  if (!(tab = malloc(sizeof(char *) * (nb_folder + 1))))
    return (NULL);
  i = 0;
  start = 0;
  while (cmd[start] && i < nb_folder)
  {
    end = start + 1;
    while (cmd[end] && cmd[end] != '/')
      end++;
    if (!(tab[i] = my_strndup(cmd + start, end - start)))
      return (NULL);
    start = end;
    while (cmd[start] == '/')
      start++;
    i++;
  }
  tab[i] = NULL;
  return (tab);
}
