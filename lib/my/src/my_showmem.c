/*
** my_showmem.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:00:55 2017 Benjamin Viguier
** Last update Thu Jan 19 14:01:17 2017 Benjamin Viguier
*/

#include "libmy.h"

static void aff_text(char *str, int to);
static void aff_hexa(char *str, int to, char *patern);
static void aff_dec(int val);

int	my_showmem(char *str, int size)
{
  int	i;
  char	cont;
  int	aff_size;

  cont = 1;
  i = 16;
  while (cont)
    {
      if (i > size)
	aff_size = 16 - (i - size);
      else
	aff_size = 16;
      aff_dec(((i - 16) / 16) * 10);
      aff_hexa(str, aff_size, "0123456789ABCDEF");
      aff_text(str, aff_size);
      cont = (i < size);
      i += 16;
      str += 16;
    }
  return (0);
}

static	void aff_text(char *str, int to)
{
  int	i;

  i = 0;
  my_putchar(' ');
  while (i < 16)
    {
      if (i < to)
	{
	  if ((str[i]) < 32 || (str[i] == 127))
	    my_putchar('.');
	  else
	    my_putchar(str[i]);
	}
      else
	my_putchar('.');
      i += 1;
    }
  my_putchar('\n');
}

/*
** patern = "0123456789ABCDEF"
*/

static	void aff_hexa(char *str, int to, char *patern)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if (i % 2 == 0)
	my_putchar(' ');
      if (i < to)
	{
          my_putchar(patern[((unsigned) (*(str + i)) / 16) % 16]);
          my_putchar(patern[(unsigned) (*(str + i)) % 16]);
	}
      else
	{
	  my_putchar(' ');
	  my_putchar(' ');
	}
      i += 1;
    }
}

static	void aff_dec(int val)
{
  int	tmp;

  tmp = 10000000;
  while (val < tmp)
    {
      my_putchar('0');
      tmp /= 10;
    }
  if (val != 0)
    my_putnbr_base(val, "0123456789");
}
