/*
** my_basic_funct.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Wed Nov  9 16:23:22 2016 Benjamin Viguier
** Last update Mon May 29 18:14:07 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include "my.h"
#include "libmy.h"

char		*my_strdup(char *str)
{
  char		*res;
  t_uint	i;

  if (!str)
    return (NULL);
  res = malloc((my_strlen(str) + 1) * sizeof(char));
  if (res == NULL)
    return (NULL);
  i = 0;
  while (*(str))
    {
      res[i] = *(str++);
      i += 1;
    }
  res[i] = '\0';
  return (res);
}

char	*my_strndup(char *str, int n)
{
  char	*res;
  int i;

  res = malloc(sizeof(char) * (n + 1));
  if (!res)
    return (0);
  my_memset(res, 0, n + 1);
  i = 0;
  while (i < n)
  {
    res[i] = str[i];
    i++;
  }
  return (res);
}

char	*my_get_u_nbr(char *str, t_uint *res)
{
  int	occ;

  *res = 0;
  occ = 0;
  while (IS_NUM(*str))
    {
      occ = 1;
      *res *= 10;
      *res += *str - '0';
      str += 1;
    }
  return (str - occ);
}

int	my_pow(int nbr, int p)
{
  int	res;

  res = 1;
  while (p)
    {
      res *= nbr;
      p -= 1;
    }
  return (res);
}
