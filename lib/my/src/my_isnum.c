/*
** my_isnum.c for libmy in /home/benji_epitech/infographie/raytracer1/bonus
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Wed Feb 15 13:28:38 2017 Benjamin Viguier
** Last update Sat May  6 13:46:00 2017 Alexandre Chamard-bois
*/

#include "libmy.h"

int	my_isnum(char *str)
{
  int	i;
  int	strl;

  i = 0;
  if (!str)
    return (0);
  strl = my_strlen(str);
  if (strl == 0)
    return (0);
  while (*str == '-')
    {
      str++;
      strl--;
    }
  if (strl == 0)
    return (0);
  while (i < strl)
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

int my_isfloat(const char *str)
{
	if (*str == '-')
		str++;
	while (NUM(*str))
		str++;
	if (*str == '.')
	{
		str++;
		while (NUM(*str))
			str++;
	}
	if (*str)
		return (1);
	return (0);
}
