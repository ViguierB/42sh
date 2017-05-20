/*
** test.c for  in /home/augustin/Bureau/augustin/projets_groupes/42sh/PSU_2016_42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri May 19 10:35:22 2017 augustin leconte
** Last update Sat May 20 20:07:24 2017 Pierre Narcisi
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

char *tab_key(char *str, char c, int *cursor)
{
  char **tab;
  char **tab2;
  int i;
  int j;

  i = 0;
  tab2 = malloc (sizeof (char*) * 2);
  tab = my_split(str, ' ', NULL);
  while (tab[i + 1] != NULL)
    i++;
  tab2[0] = str_conca(tab[i], "*");
  j = i;
  globing(&tab2)
  i = -1;
  while (tab[i + 1] != NULL)
    i++;
  if (i == -1)
    return (str);
  else if (i == 0)
    {
      tab[j] = NULL;
      str = wordtab_to_str(tab);
      str = str_conca(str, " ");
      str = str_conca(str, tab[0]);
      return (str);
    }
  else
    {
      i = 0;
      while (tab[i] != NULL)
        {
          printf("   %s", tab[i]);
          i++;
        }
      return (str);
    }
  return (str);
}
