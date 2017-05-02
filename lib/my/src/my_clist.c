/*
** clist.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Nov 23 17:41:40 2016 Benjamin Viguier
** Last update Mon Feb 27 15:30:52 2017 Benjamin Viguier
*/

#include "my.h"
#include "libmy.h"

t_clist		*clist_push(t_clist *first, void *ptr)
{
  t_clist_elm	*n_elm;
  t_clist_elm	*last;

  n_elm = malloc(sizeof(t_clist_elm));
  if (n_elm == NULL)
    return (NULL);
  n_elm->ptr = ptr;
  if (first)
    {
      last = first->prev;
      last->next = n_elm;
      first->prev = n_elm;
      n_elm->next = first;
      n_elm->prev = last;
    }
  else
    {
      n_elm->prev = n_elm;
      n_elm->next = n_elm;
      return (n_elm);
    }
  return (first);
}

void	clist_swap_val(t_clist_elm *elm1, t_clist_elm *elm2)
{
  void	*tmp;

  tmp = elm1->ptr;
  elm1->ptr = elm2->ptr;
  elm2->ptr = tmp;
}

t_clist_elm	*clist_at(t_clist *list, int at)
{
  t_clist_elm	*res;

  res = list;
  while (at)
    {
      res = res->next;
      at--;
    }
  return (res);
}
