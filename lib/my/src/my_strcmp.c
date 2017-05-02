/*
** my_strcmp.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:01:49 2017 Benjamin Viguier
** Last update Thu Jan 19 14:01:50 2017 Benjamin Viguier
*/

#include <unistd.h>

int	check_nil(char *s1, char *s2, int *res)
{
  if (s1 == NULL && s2 == NULL)
    {
      *res = 0;
      return (1);
    }
  else if (s1 != NULL && s2 == NULL)
    {
      *res = 1;
      return (1);
    }
  else if (s1 == NULL && s2 != NULL)
    {
      *res = -1;
      return (1);
    }
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	p_res;

  if (check_nil(s1, s2, &p_res))
    return (p_res);
  while ((*s1 != '\0') && (*s1 == *s2))
    {
      s1 += 1;
      s2 += 1;
    }
  if (*((unsigned char*) s1) < *((unsigned char*) s2))
    return (-1);
  else if (*((unsigned char*) s1) > *((unsigned char*) s2))
    return (1);
  else
    return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	p_res;

  if (check_nil(s1, s2, &p_res))
    return (p_res);
  i = 0;
  while ((*s1 != '\0') && (*s1 == *s2) && (i < n))
    {
      s1 += 1;
      s2 += 1;
      i += 1;
    }
  if (i == n)
    return (0);
  else if (*((unsigned char*) s1) < *((unsigned char*) s2))
    return (-1);
  else if (*((unsigned char*) s1) > *((unsigned char*) s2))
    return (1);
  else
    return (0);
}
