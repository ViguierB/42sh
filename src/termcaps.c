/*
** termcaps.c for termcaps in /home/augustin/Bureau/augustin/projets_groupes/42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon May 15 13:43:04 2017 augustin leconte
** Last update Sun May 21 21:09:57 2017 alexandre Chamard-bois
*/

#include "termcaps.h"
#include "mysh.h"
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

t_clist     *termcaps(t_clist *list)
{
  char     buffer[3];
  char     *str;
  int      cursor;
  int      i;

  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  str[0] = '\0';
  list = clist_push(list, str);
  cursor = 0;
  my_memset(buffer, 0, 3);
  while (1)
    {
      my_memset(buffer, 0, 3);
      read(0, buffer, 3);
      if (*buffer == '\n' || *buffer == 3 ||
	  (*buffer == 4 && my_strlen(list->ptr)))
	return (list);
      if (*buffer == 4)
	return (NULL);
      i = 0;
      while (g_key[i].param1 != -1 && (g_key[i].param1 != buffer[0] ||
				       g_key[i].param2 != buffer[2]))
	i++;
      if (g_key[i].param1 != -1)
	list = g_key[i].term(&cursor, list);
      else
	{
	  list->ptr = add_ch(buffer[0], &cursor, list->ptr);
	  printf("\033[%dD%s%s\033[%dD\033[1C", cursor,
		 (!cursor ? "\033[1C" : ""),
		 (char*)list->ptr, my_strlen(list->ptr) - cursor);
	  cursor++;
	}
      fflush(stdout);
    }
  return (list);
}

char			*termcap(t_mysh *sh)
{
  t_clist		*list;
  struct termios	term;
  struct termios	save;

  tcgetattr(0, &term);
  save = term;
  term.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(0, TCSANOW, &term);
  list = termcaps(sh->hist);
  tcsetattr(0, TCSANOW, &save);
  printf("\n");
  if (!list)
    return (NULL);
  if (sh->hist)
    sh->hist = sh->hist->prev;
  else
    sh->hist = list;
  return (sh->hist->ptr);
}
