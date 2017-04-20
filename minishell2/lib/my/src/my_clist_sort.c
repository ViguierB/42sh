/*
** my_clist_sort.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 28 13:31:22 2017 Benjamin Viguier
** Last update Wed Mar  1 16:01:02 2017 Benjamin Viguier
*/

#include "libmy.h"

t_clist_elm	*easy_sort_get_min(t_clist_elm *list, t_clist_elm *e1,
				   t_elm_cmp cmp_fct)
{
  t_clist_elm	*min;

  min = e1;
  e1 = e1->next;
  while (e1 != list)
    {
      if (cmp_fct(e1->ptr, min->ptr) == -1)
	{
	  min = e1;
	}
      e1 = e1->next;
    }
  return (min);
}

void		easy_sort(t_clist *list, t_elm_cmp cmp_fct)
{
  t_clist_elm	*e1;
  t_clist_elm	*min;
  void		*tmp;

  e1 = list;
  while (e1)
    {
      min = easy_sort_get_min(list, e1, cmp_fct);
      if (min != e1)
	{
	  tmp = min->ptr;
	  min->ptr = e1->ptr;
	  e1->ptr = tmp;
	}
      e1 = e1->next;
      if (e1->next == list)
	e1 = NULL;
    }
}

void	clist_sort(t_clist *list, t_elm_cmp cmp_fct)
{
  if (list)
    easy_sort(list, cmp_fct);
}
