/*
** my_clist_rem.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Feb 27 15:02:58 2017 Benjamin Viguier
** Last update Thu May 11 13:03:24 2017 Alexandre Chamard-bois
*/

#include "libmy.h"

t_clist		*clist_remove(t_clist *list, t_clist_elm *elm)
{
  t_clist	*next;
  t_clist	*prev;

  next = elm->next;
  prev = elm->prev;

  if (next == elm || prev == elm)
    {
      free(elm);
      return (NULL);
    }
  prev->next = next;
  next->prev = prev;
  if (elm == list)
    {
      my_printf("test2\n");
      free(elm);
      return (next);
    }
  free(elm);
  return (list);
}

t_clist		*clist_rem_fdata(t_clist *list, t_clist_elm *elm,
				 void (*my_free)(void*))
{
  my_printf("test3\n");
  my_free(elm->ptr);
  list = clist_remove(list, elm);
  return (list);
}

void		clist_free_data(t_clist *l, void (*myfree)(void*))
{
  t_clist_elm	*elm;
  int		cont;

  elm = l;
  cont = 1;
  l->prev->next = l->prev;
  while (elm && l && cont)
    {
      l = l->next;
      if (elm == l)
	cont  = 0;
      if (elm)
	{
	  myfree(elm->ptr);
	  free(elm);
	}
      elm = l;
    }
}

void		clist_free(t_clist *l)
{
  t_clist_elm	*elm;
  int		cont;

  elm = l;
  cont = 1;
  l->prev->next = l->prev;
  while (elm && l && cont)
    {
      l = l->next;
      if (elm == l)
	cont  = 0;
      free(elm);
      elm = l;
    }
}
