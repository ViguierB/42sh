/*
** termcaps.c for termcaps in /home/augustin/Bureau/augustin/projets_groupes/42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon May 15 13:43:04 2017 augustin leconte
** Last update Thu May 18 20:38:14 2017 Pierre Narcisi
*/

#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

t_term_tab tab[] = {
  {127, 0, back_space},
  {27, 68, left_arrow},
  {27, 67, right_arrow},
  {-1, -1, NULL}
};

char     *termcaps()
{
  char     buffer[3];
  char     *str;
  int cursor;
  int i;

  cursor = 0;
  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (1)
  {
    read(0, buffer, 3);
    i = 0;
    while (tab[i]->param1 != -1 && tab[i]->param1 != buffer[0])
      i++;
    if (tab[i]->param1 == 27)
      {
        i = 0;
        while (tab[i]->param2 != -1 && tab[i]->param2 != buffer[0])
          i++;
      }
    if (tab[i]->param1 != -1)
      str = tab[i]->term(str, buffer[0], &cursor);
    else
      {
        cursor++;
        str = add_ch(str, buffer[0], cursor);
      }
      write(1, str, strlen(str));
  }
  return (str);
}

int              main(int ac, char **av, char **env)
{
  char           *str;
  char           *name_term;
  struct termios term;

  if ((name_term = getenv("TERM")) == NULL)
    return (-1);
  if (tgetent(NULL, name_term) == -1)
    return (-1);
  if (tcgetattr(0, &term) == -1)
    return (-1);
  term.c_lflag &= ~(ICANON);
  term.c_lflag &= ~(ECHO);
  if (tcsetattr(0, TCSADRAIN, &term) == -1)
    return (-1);
  if ((str = termcaps()) != NULL)
    printf("%s\n", str);
  if (tcgetattr(0, &term) == -1)
   return (-1);
  term.c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, &term) == -1)
   return (-1);
  return (0);
}
