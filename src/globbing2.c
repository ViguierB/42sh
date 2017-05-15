/*
** globbing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:12:44 2017 Alexandre Chamard-bois
** Last update Fri May 12 08:45:29 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "glob.h"

static int _size(char **cmd, t_clist *add)
{
  t_clist *list;
  int i;

  i = 0;
  while (cmd[i])
    i++;
  list = add;
  while (list)
  {
    list = CLIST_NEXT(add, list);
    i++;
  }
  return (i);
}

int _add_list(t_clist *add, char **new_cmd, char *cut)
{
  t_clist *list;
  int i;

  i = 0;
  list = add;
  while (list)
  {
    new_cmd[i] = list->ptr + (*(char*)add->ptr == '.' && *cut != '.' ? 2 : 0);
    list = CLIST_NEXT(add, list);
    i++;
  }
  return (i);
}

int cmp_add(void *s1, void *s2)
{
  char c1;
  char c2;

  c1 = *(char*)s1;
  c2 = *(char*)s2;
  while (*(char*)s1 || *(char*)s2)
  {
    c1 = *(char*)s1;
    if (c1 >= 'A' && c1 <= 'Z')
      c1 += 32;
    c2 = *(char*)s2;
    if (c2 >= 'A' && c2 <= 'Z')
      c2 += 32;
    if (c1 != c2)
      break;
    s1++;
    s2++;
  }
  return (c1 - c2);
}

char **_remplace_cmd(char **cmd, int unused, t_clist *add, char *cut)
{
  char **new_cmd;
  int i;
  int j;
  int len;

  clist_qsort(add, cmp_add);
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

t_clist *_new_path(t_clist *list, char *path)
{
  list = clist_push(list, path);
  return (list);
}
