/*
** termcaps.c for termcaps in /home/augustin/Bureau/augustin/projets_groupes/42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon May 15 13:43:04 2017 augustin leconte
** Last update Wed May 17 11:00:44 2017 augustin leconte
*/

#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

char	*rm_ch(char *str)
{
  char	*new;
  int	len;
  int	i;

  len = strlen(str);
  if ((new = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] != '\0')
    new[i] = str[i];
  new[i - 2] = '\0';
  return (new);
}

char	*add_ch(char *str, char c)
{
  char	*new;
  int	len;
  int	i;

  len = strlen(str);
  if ((new = malloc(sizeof(char) * len + 2)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] != '\0')
    new[i] = str[i];
  new[i] = c;
  new[i + 1] = '\0';
  return (new);
}

char     *termcaps()
{
  char     buffer[3];
  char     *str;
  int cursor;

  cursor = 0;
  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 4 || buffer[0] == 3)
      return (NULL);
    else if (buffer[0] == 27 && buffer[3] == 67)
      cursor += 1;
    else if (buffer[0] == 27 && buffer[3] == 68)
      cursor -= 1;
    else
    {
      str = add_ch(str, buffer[0]);
      write(1, str, strlen(str));
    }
    if (buffer[0] == 127)
    {
      rm_ch(str);
      write(1, str, strlen(str));
    }
    // printf("buffer[0] = %d, buffer[1] = %d, buffer[2] = %d\n", buffer[0], buffer[1], buffer[2]);
  }
  return (str);
}

int              main(int ac, char **av, char **env)
{
  char *str;
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
