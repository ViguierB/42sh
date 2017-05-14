/*
** my_hash_table.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Fri Mar 24 19:49:07 2017 Benjamin Viguier
** Last update Sun Mar 26 22:53:34 2017 Benjamin Viguier
*/

#include "hash_table.h"
#include "libmy.h"

t_ht_elm	*get_ht_value(t_ht *ht, void *key)
{
  int		idx;

  idx = ht->hash_fct(key) % ht->len;
  return (ht->buffer + idx);
}

t_ht_error	remove_ht_value(t_ht *ht, void *value, void *key)
{
  t_ht_elm	*ht_val;
  t_clist_elm	*elm;
  void		*tmp;

  ht_val = get_ht_value(ht, key);
  if (ht_val->islist)
    {
      elm = ht_val->value;
      while (elm && (elm->ptr != value))
	elm = CLIST_NEXT(ht_val->value, elm);
      if (!elm)
	return (INVALIDPTR);
      ht_val->value = clist_remove(ht_val->value, elm);
      if (((t_clist*) ht_val->value)->next == ht_val->value)
	{
	  tmp = ((t_clist*) ht_val->value)->ptr;
	  free(ht_val->value);
	  ht_val->value = tmp;
	  ht_val->islist = 0;
	}
    }
  else
    ht_val->value = NULL;
  return (SUCCESS);
}

t_ht_error	set_ht_value(t_ht *ht, void *value, void *key)
{
  int		idx;
  t_clist	*list;

  idx = ht->hash_fct(key) % ht->len;
  if (!(ht->buffer[idx].islist) && ht->buffer[idx].value)
    {
      list = NULL;
      list = clist_push(list, ht->buffer[idx].value);
      list = clist_push(list, value);
      ht->buffer[idx].value = list;
      ht->buffer[idx].islist = 1;
    }
  else if (ht->buffer[idx].islist)
    ht->buffer[idx].value = clist_push(ht->buffer[idx].value, value);
  else
    ht->buffer[idx].value = value;
  return (SUCCESS);
}

t_ht	*init_ht(size_t len, t_hash_fct hash_fct)
{
  t_ht	*res;

  res = malloc(sizeof(t_ht));
  if (!res)
    return (NULL);
  if (init_allowed_ht(res, len, hash_fct) < 0)
    {
      free(res);
      return (NULL);
    }
  return (res);
}

int		init_allowed_ht(t_ht *ht, size_t len, t_hash_fct hash_fct)
{
  t_ht_elm	*buffer;

  buffer = malloc(sizeof(t_ht_elm) * len);
  ht->len = len;
  if (!(buffer))
    return (-1);
  my_memset(buffer, 0, sizeof(t_ht_elm) * len);
  ht->buffer = buffer;
  if (hash_fct)
    ht->hash_fct = hash_fct;
  else
    ht->hash_fct = &jenkins_hash_ptr;
  return (0);
}
