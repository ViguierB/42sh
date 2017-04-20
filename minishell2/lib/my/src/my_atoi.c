/*
** my_atoi.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 20 15:49:46 2017 Benjamin Viguier
** Last update Mon Apr  3 18:55:16 2017 Benjamin Viguier
*/

#include "libmy.h"

unsigned	my_atoui(char *str)
{
  unsigned	res;

  res = 0;
  while ((*str >= '0') && (*str <= '9'))
    {
      res *= 10;
      res += *str - '0';
      str++;
    }
  return (res);
}

int	my_atoi(char *str)
{
  int	neg;

  neg = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	neg = !neg;
      str++;
    }
  if (neg)
    return (-((int) my_atoui(str)));
  else
    return ((int) my_atoui(str));
}

int	my_strtol(char *str, long *res)
{
  int	neg;

  neg = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	neg = !neg;
      str++;
    }
  *res = 0;
  while ((*str >= '0') && (*str <= '9'))
    {
      *res *= 10;
      *res += *str - '0';
      str++;
    }
  if (!(*str == '\0'))
    return (-1);
  if (neg)
    *res = -(*res);
  return (0);
}
