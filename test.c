/*
** test.c for  in /home/augustin/Bureau/augustin/projets_groupes/42sh/PSU_2016_42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri May 19 10:35:22 2017 augustin leconte
** Last update Sat May 20 22:25:10 2017 Pierre Narcisi
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

t_clist *last_key(int *cursor, t_clist *list)
{
  while (*cursor > 0)
    {
      list = right_arrow(int *cursor, t_clist *list)
    }
  return (list);
}

t_clist *last_key(int *cursor, t_clist *list)
{
  int len;

  len = strlen (list->ptr);
  while (*cursor < len)
    {
      list = left_arrow(int *cursor, t_clist *list)
    }
  return (list);
}

t_clist *supr_key(int *cursor, t_clist *list)
{
  if (*cursor < strlen (list->ptr))
      list->ptr = rm_ch(list->ptr, *cursor + 1);
  return (list);
}

char *complete(int j, char **tab, char *str)
{
  tab[j] = NULL;
  str = wordtab_to_str(tab);
  str = str_conca(str, " ");
  str = str_conca(str, tab[0]);
  return (str);
}

t_clist *tab_key(int *cursor, t_clist *list)
{
  char **tab;
  char **tab2;
  int i;
  int j;

  i = 0;
  tab2 = malloc (sizeof (char*) * 2);
  tab = my_split(list->ptr, ' ', NULL);
  while (tab[i + 1] != NULL)
    i++;
  tab2[0] = str_conca(tab[i], "*");
  j = i;
  globing(&tab2)
  i = -1;
  while (tab[i + 1] != NULL)
    i++;
  if (i == 0)
    list->ptr = complete(j, tab, str);
  else if (i != -1)
    {
      i = 0;
      while (tab[i] != NULL)
        {
          printf("   %s", tab[i]);
          i++;
        }
    }
  return (list);
}
