/*
** my_putnbr_base.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:00:05 2017 Benjamin Viguier
** Last update Thu Jan 19 14:00:07 2017 Benjamin Viguier
*/

#include "my.h"

static void rec_putnbr_base(unsigned nb, char *base, int lbase);

int	my_putnbr_base(int nb, char *base)
{
  int	lbase;

  lbase = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      rec_putnbr_base(- (unsigned) nb, base, lbase);
    }
  else
    {
      rec_putnbr_base((unsigned) nb, base, lbase);
    }
  return (0);
}

static void	rec_putnbr_base(unsigned nb, char *base, int lbase)
{
  if (nb < (unsigned) lbase)
    my_putchar(base[nb]);
  else
    {
      rec_putnbr_base(nb / lbase, base, lbase);
      my_putchar(base[nb % lbase]);
    }
}
