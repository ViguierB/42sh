/*
** my_trim.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 24 14:03:37 2016 Benjamin Viguier
** Last update Tue Apr  4 11:33:18 2017 Benjamin Viguier
*/

#include "libmy.h"

char	*my_ftrim(char *str)
{
  char	*new_str;

  if (!str)
    return (str);
  new_str = my_trim(str);
  if (!new_str)
    return (NULL);
  free(str);
  return (new_str);
}

char	*my_trim(char *str)
{
  char	*res;
  int	first;
  int	last;
  int	i;

  first = 0;
  last = my_strlen(str) - 1;
  while (str[first] == ' ')
    first += 1;
  while (last >= 0 && str[last] == ' ')
    last -= 1;
  if (last < 0)
    return (my_strdup(""));
  res = malloc(sizeof(char) * (last - first + 2));
  if (res == NULL)
    return (NULL);
  i = 0;
  while (first <= last)
    {
      res[i] = str[first];
      i += 1;
      first += 1;
    }
  res[i] = '\0';
  return (res);
}
