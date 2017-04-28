/*
** my_strconca.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 24 15:24:14 2016 Benjamin Viguier
** Last update Fri Jan 13 10:20:01 2017 Benjamin Viguier
*/

#include "my.h"

char	*my_strconca(char *str1, char *str2)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  if (res == NULL)
    return (NULL);
  while (str1[i])
    {
      res[i] = str1[i];
      i += 1;
    }
  while (str2[j])
    {
      res[i] = str2[j];
      i += 1;
      j += 1;
    }
  res[i] = '\0';
  return (res);
}

static char	*str_conca_s(char **list, char size)
{
  char		*res;
  int		i;
  int		j;

  res = malloc(sizeof(char) * (size - 1));
  if (res == NULL)
    return (NULL);
  if (*list)
    {
      i = 0;
      while (*list)
	{
	  j = 0;
	  while ((*list)[j])
	    {
	      res[i] = (*list)[j];
	      i += 1;
	      j += 1;
	    }
	  list += 1;
	}
    }
  return (res);
}

char		*str_conca(int n, ...)
{
  va_list	ap;
  char		**list;
  int		i;
  int		size;

  va_start(ap, n);
  list = malloc(sizeof(char *) * n);
  if (list == NULL)
    return (NULL);
  i = 0;
  size = 0;
  while (n > 0)
    {
      list[i] = va_arg(ap, char *);
      if (list[i])
	{
	  size += my_strlen(list[i]);
	  i += 1;
	}
      n -= 1;
    }
  list[i] = NULL;
  return (str_conca_s(list, size));
}
