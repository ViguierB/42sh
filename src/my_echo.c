/*
** my_echo.c for 42sh in /home/arthur/Modules/PSU/PSU_2016_42sh/src/
**
** Made by Arthur Devreker
** Login   <arthur.devreker@epitech.eu>
**
** Started on  Sun May 14 17:44:37 2017 Arthur Devreker
** Last update Sun May 21 21:03:39 2017 alexandre Chamard-bois
*/

#include "mysh.h"

int		stock_args(int i, char **av)
{
  static int	n = 0;
  static int	e = 0;
  int		tmp;

  tmp = 1;
  while (av[i][tmp])
    {
      if (av[i][tmp] != 'e' && av[i][tmp] != 'n')
	break;
      if (av[i][tmp] == 'e')
	e = 1;
      if (av[i][tmp] == 'n')
	n = 1;
      tmp++;
    }
  if (e == 1 && n == 1)
    return (1);
  if (e == 1 && n == 0)
    return (2);
  if (e == 0 && n == 1)
    return (3);
  return (0);
}

void	my_disp_echo(char **av, int ac, int i)
{
  my_printf("%s", av[i]);
  if ((i + 1) < ac)
    my_printf(" ");
}

int	my_echo(char **av, t_mysh *sh)
{
  int	i;
  int	j;
  int	ac;

  i = 1;
  j = 0;
  ac = my_nbline(av);
  (void)sh;
  if (ac > 1)
    {
      while ((av[i]) && (!my_strcmp(av[i], "-n")))
	{
	  j = stock_args(i, av);
	  i++;
	}
      if (av[i] != NULL)
	{
	  i--;
	  while (i++ < ac)
	    my_disp_echo(av, ac, i);
	}
    }
  if (j != 1 && j != 3)
    my_printf("\n");
  return (0);
}
