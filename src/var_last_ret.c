/*
** var_last_ret.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Wed May 17 11:28:08 2017 Alexandre Chamard-bois
** Last update Wed May 17 11:31:26 2017 Alexandre Chamard-bois
*/

#include <stdlib.h>
#include "libmy.h"
#include "mysh.h"

char *cpy_ret(int ret)
{
  char *nb;
  int i;
  int decal;

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

void var_last_ret(t_mysh *mysh)
{
  char *tab[4];

  tab[0] = "set";
  tab[1] = "?";
  tab[2] = cpy_ret(mysh->last_exit);
  tab[3] = NULL;
  if (tab[2])
  {
    my_set(tab, mysh);
    free(tab[2]);
  }
}
