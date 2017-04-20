/*
** my_put.c for my_put in /home/benji_epitech/C_Prog_Elem/PSU_2016_my_printf_bootstrap
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.net>
** 
** Started on  Tue Nov  8 18:51:57 2016 Benjamin Viguier
** Last update Thu Nov 24 18:17:28 2016 Benjamin Viguier
*/

#include "my.h"

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

void	my_put_nbr_rec(int nbr)
{
  if (nbr > -10 && nbr < 10)
    my_putchar(POS(nbr) + '0');
  else
    {
      my_put_nbr_rec(nbr / 10);
      my_putchar(POS(nbr % 10) + '0');
    }
}

int	my_put_nbr(int nbr)
{
  if (nbr < 0)
    my_putchar('-');
  my_put_nbr_rec(nbr);
  return (0);
}
