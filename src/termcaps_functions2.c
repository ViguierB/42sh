/*
** termcaps_functions2.c for 42sh in /home/byliarus/work/PSU_2016_42sh/src/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Fri May 19 19:08:51 2017 Pierre Narcisi
** Last update Sat May 20 22:27:19 2017 Alexandre Chamard-bois
*/

#include "termcaps.h"
#include <unistd.h>
#include <stdio.h>

t_clist *up_arrow(int *cursor, t_clist *list)
{
  int i;

  i = 0;
  while (i < *cursor)
  {
    write(1, "\10\33[1P", 5);
    i++;
  }
  *cursor = 0;
  list = list->prev;
  printf("%s", (char*)list->ptr);
  return (list);
}

t_clist *down_arrow(int *cursor, t_clist *list)
{
  int i;

  i = 0;
  while (i < *cursor)
  {
    write(1, "\10\33[1P", 5);
    i++;
  }
  *cursor = 0;
  list = list->next;
  printf("%s", (char*)list->ptr);
  return (list);
}
