/*
** var_last_ret.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Wed May 17 11:28:08 2017 Alexandre Chamard-bois
** Last update Sun May 21 21:13:19 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include "libmy.h"
#include "mysh.h"

char	*cpy_ret(int ret)
{
  char	*nb;
  int	i;
  int	decal;

  decal = 10;
  while (ret / decal)
    decal *= 10;
  nb = malloc(sizeof(char) * 10);
  my_memset(nb, 0, 10);
  i = 0;
  while (decal != 1)
    {
      decal /= 10;
      nb[i] = ret % 10 + '0';
      i++;
    }
  return (nb);
}

void	print_var(t_mysh *mysh)
{
  t_var *elm;

  elm = mysh->var;
  while (elm)
    {
      my_printf("%s\t%s\n", NAME(elm), VALUE(elm));
      elm = CLIST_NEXT(mysh->var, elm);
    }
}

void	var_last_ret(t_mysh *mysh)
{
  char	*tab[5];

  tab[0] = "set";
  tab[1] = "?";
  tab[2] = "=";
  tab[3] = cpy_ret(mysh->last_exit);
  tab[4] = NULL;
  if (tab[3])
    {
      my_set(tab, mysh);
      free(tab[3]);
    }
}

int	var_set(t_mysh *mysh, char *key, char *value)
{
  char	*tab[5];

  tab[0] = "set";
  tab[1] = key;
  tab[2] = "=";
  tab[3] = value;
  tab[4] = NULL;
  return (my_set(tab, mysh));
}

void	var_set_env(t_mysh *mysh, char *key, char *value)
{
  char	*tab[4];

  tab[0] = "setenv";
  tab[1] = key;
  tab[2] = value;
  tab[3] = NULL;
  my_ssetenv(tab, mysh);
}
