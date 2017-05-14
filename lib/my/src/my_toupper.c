/*
** my_toupper.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my/src
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Feb 28 13:44:07 2017 Benjamin Viguier
** Last update Sun May  7 18:33:37 2017 Alexandre Chamard-bois
*/

#include "macro.h"

void	my_upper(char *str)
{
  while (*str)
    {
      if (*str >= 'a' && *str <= 'z')
	*str += 'a' - 'A';
      str++;
    }
}

void	my_lower(char *str)
{
  while (*str)
    {
      if (*str >= 'A' && *str <= 'Z')
	*str -= 'a' - 'A';
      str++;
    }
}

int	is_alph_num(char *str)
{
  while (*str)
    {
      if (!NUM(*str) || !LOWER(*str) || !UPPER(*str) || *str != '_')
	       return (1);
      str++;
    }
  return (0);
}
