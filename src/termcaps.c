/*
** termcaps.c for termcaps in /home/augustin/Bureau/augustin/projets_groupes/42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon May 15 13:43:04 2017 augustin leconte
** Last update Sat May 20 20:12:21 2017 augustin leconte
*/

#include "termcaps.h"
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

t_term_tab g_key[6] = {
  {127, 0, back_space},
  {27, 68, left_arrow},
  {27, 67, right_arrow},
  {27, 65, up_arrow},
  {27, 66, down_arrow},
  {-1, -1, NULL}
};

char     *termcaps(t_clist *list)
{
  char     buffer[3];
  char     *str;
  int      cursor;
  int      i;

  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  str[0] = '\0';
  clist_push(list, str);
  cursor = 0;
  while (1)
  {
    read(0, buffer, 3);
    i = 0;
    while (g_key[i].param1 != -1 && g_key[i].param1 != buffer[0])
      i++;
    if (g_key[i].param1 == 27)
      {
        while (g_key[i].param2 != -1 && g_key[i].param2 != buffer[2])
          i++;
      }
    else if (g_key[i].param1 != -1)
      list->ptr = g_key[i].term(buffer[0], &cursor, list);
    else
      {
        cursor++;
        list->ptr = add_ch(list->ptr, buffer[0], &cursor);
        write(1, &buffer[0], 1);
      }
  }
  str = list->ptr;
  return (str);
}

char              *termcap(t_mysh *sh)
{
  char           *str;
  struct termios term;
  struct termios save;
  t_clist *list_save;

  list_save = sh->hist;
  tcgetattr(0, &term);
  save = term;
  term.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(0, TCSANOW, &term);
  str = termcaps(list);
  tcsetattr(0, TCSANOW, &save);
  return (str);
}
