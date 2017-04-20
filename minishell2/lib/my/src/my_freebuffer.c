/*
** my_freebuffer.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell2
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Mar 20 11:22:24 2017 Benjamin Viguier
** Last update Mon Mar 20 17:59:53 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "libmy.h"

int	my_sfree(t_clist *list)
{
  clist_free_data(list, &free);
  return (0);
}

int		my_singlefree(t_clist **list, void *tofree)
{
  t_clist_elm	*cur;

  cur = *list;
  while (cur)
    {
      if (tofree == cur->ptr)
	{
	  *list = clist_remove(*list, cur);
	  return (0);
	}
      cur = CLIST_NEXT(*list, cur);
    }
  return (-1);
}

t_clist	*my_smalloc(t_clist *list, void **ptr, size_t len)
{
  *ptr = malloc(len);
  if (!(*ptr))
    return (NULL);
  list = clist_push(list, *ptr);
  return (list);
}
