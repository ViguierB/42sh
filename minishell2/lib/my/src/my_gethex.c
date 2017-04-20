/*
** my_gethex.c for libmy.h in /home/benji_epitech/workdir/perso/libmy/tmp/test/mygethex
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Thu Mar 30 16:39:42 2017 Benjamin Viguier
** Last update Mon Apr  3 18:33:51 2017 Benjamin Viguier
*/

#include <unistd.h>

int		get_one_number(char c)
{
  const char	pat[] = "abcdefABCDEF";
  const int	len = (sizeof(pat) - 1) / 2;
  char		*cur;
  int		i;

  if (c >= '0' && c <= '9')
    return (c - '0');
  cur = (char*) pat;
  i = 0;
  while (cur[i])
    {
      if (cur[i] == c)
	return (10 + (i % len));
      i++;
    }
  return (-1);
}

int	my_gethex(char *hex, int *res)
{
  int	err;

  *res = 0;
  err = 0;
  if (hex[0] && hex[1] && hex[0] == '0' &&
      (hex[1] == 'x' || hex[1] == 'X'))
    hex += 2;
  while (*hex)
    {
      err = get_one_number(*(hex++));
      if (err < 0)
	return (-1);
      *res = (*res << 4) | err;
    }
  return (0);
}
