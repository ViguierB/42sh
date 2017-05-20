/*
** termcaps_functions.c for 42sh in /home/byliarus/work/PSU_2016_42sh/src/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Thu May 18 15:31:03 2017 Pierre Narcisi
** Last update Sat May 20 20:06:56 2017 Pierre Narcisi
*/

#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

char	*rm_ch(char *str, int cursor)
{
  char	*new;
  int	len;
  int	i;
  int j;

  len = strlen(str);
  if ((new = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] != '\0' && i < cursor)
    {
      new[i] = str[i];
      i++;
    }
    j = i;
    i++;
  while (str[i] != '\0')
    {
      new[j] = str[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

char	*add_ch(char *str, char c, int *cursor)
{
  char	*new;
  int	len;
  int	i;

  len = strlen(str);
  if ((new = malloc(sizeof(char) * len + 2)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0' && i < *cursor)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = c;
  while (str[i] != '\0')
    {
      i++;
      new[i] = str[i - 1];
    }
  new[i + 1] = '\0';
  return (new);
}

char *back_space(char c, int *cursor, t_clist *list)
{
  if (*cursor > 0)
    {
      *cursor -= 1;
       write(1, "\10\33[1P", 5);
      list->ptr = rm_ch(list->ptr, *cursor);
    }
  return (list);
}

char *right_arrow(char c, int *cursor, t_clist *list)
{
  (void)list;
  (void)c;
  if (*cursor < strlen (str))
  {
    *cursor += 1;
    printf("\033[1C");
    fflush(stdout);
  }
  return (list);
}

char *left_arrow(char c, int *cursor, t_clist *list)
{
  (void)list;
  (void)c;
  if (*cursor > 0)
    {
      *cursor -= 1;
      printf("\033[1D");
      fflush(stdout);
    }
  return (list);
}
