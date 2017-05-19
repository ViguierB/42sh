/*
** wordtab_to_str.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 21:36:01 2017 Alexandre Chamard-bois
** Last update Fri May 19 21:45:18 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

char *wordtab_to_str(char **tab)
{
  int i;
  char *str;
  char *tmp;

  if (!tab)
    return (NULL);
  i = 0;
  str = NULL;
  while (tab[i])
  {
    if (!str)
      str = my_strdup(tab[i]);
    else
    {
      tmp = str_conca(3, str, " ", tab[i]);
      free(str);
      str = tmp;
    }
    i++;
  }
  return (str);
}
