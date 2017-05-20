/*
** termcaps_functions2.c for 42sh in /home/byliarus/work/PSU_2016_42sh/src/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Fri May 19 19:08:51 2017 Pierre Narcisi
** Last update Sat May 20 19:26:46 2017 augustin leconte
*/

#include "termcaps.h"
#include <unistd.h>
#include <stdio.h>

char *up_arrow(char *str, char c, int *cursor, t_clist *list)
{
  int i;

  i = 0;
  while (i < *cursor)
  {
    write(1, "\10\33[1P", 5);
    i++;
  }
  *cursor = 0;
  return ("\0");
}

char *down_arrow(char *str, char c, int *cursor, t_clist *list)
{
  int i;

  i = 0;
  while (i < *cursor)
  {
    write(1, "\10\33[1P", 5);
    i++;
  }
  *cursor = 0;
  return ("\0");
}
