/*
** free_tab.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 14:40:38 2017 Alexandre Chamard-bois
** Last update Thu May 11 14:57:54 2017 Alexandre Chamard-bois
*/

#include <stdlib.h>

void free_tab(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
  {
    free(tab[i]);
    i++;
  }
  free(tab);
}
