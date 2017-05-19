/*
** recup_parentheses.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 11:32:35 2017 Alexandre Chamard-bois
** Last update Fri May 19 18:41:46 2017 Alexandre Chamard-bois
*/

#include "libmy.h"

char **recup_parentheses(char **tab, int *pos)
{
  int nb;
  int i;
  char **new_tab;

  if (my_strcmp(*tab, "("))
    return (NULL);
  nb = 1;
  while (tab[nb] && my_strcmp(tab[nb], ")"))
    nb++;
  if (!tab[nb])
    return (NULL);
  if (!(new_tab = malloc(sizeof(char *) * nb)))
    return (NULL);
  i = 0;
  while (i < nb - 1)
  {
    new_tab[i] = tab[i + 1];
    i++;
  }
  *pos += i;
  new_tab[i] = NULL;
  return (new_tab);
}
