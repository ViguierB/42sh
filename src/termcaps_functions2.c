/*
** termcaps_functions2.c for 42sh in /home/byliarus/work/PSU_2016_42sh/src/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Fri May 19 19:08:51 2017 Pierre Narcisi
** Last update Sat May 20 20:22:38 2017 augustin leconte
*/

#include "termcaps.h"
#include <unistd.h>
#include <stdio.h>

t_clist *up_arrow(char c, int *cursor, t_clist *list)
{
  int i;

  i = 0;
  (void)c;
  while (i < *cursor)
  {
    write(1, "\10\33[1P", 5);
    i++;
  }
  *cursor = 0;
  list = list->prev;
  my_printf("%s", list->ptr);
  return (list);
}

t_clist *down_arrow(char c, int *cursor, t_clist *list)
{
  int i;

  i = 0;
  (void)c;
  while (i < *cursor)
  {
    write(1, "\10\33[1P", 5);
    i++;
  }
  *cursor = 0;
  list = list->next;
  my_printf("%s", list->ptr);
  return (list);
}
