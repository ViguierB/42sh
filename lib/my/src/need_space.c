/*
** need_space.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Nov 15 19:49:22 2016 Benjamin Viguier
** Last update Thu Nov 24 18:14:34 2016 Benjamin Viguier
*/

#include "my.h"

t_stack		*ew_np(t_param *par, t_stack *stack,
		       char *is_s, char *to_print)
{
  t_stack	*elm;

  elm = NULL;
  *to_print = ' ';
  if (allowed_flag(par, '-') && (par->flag->m_f))
    {
      *is_s = 1;
      elm = stack;
      while (elm && elm->next)
	elm = elm->next;
    }
  else if (allowed_flag(par, '0') && (par->flag->z_f) &&
	   (*(par->width) > *(par->preci)))
      *to_print = '0';
  return (elm);
}

void	*modif_hh(va_list ap)
{
  t_ull	*res;

  res = malloc(sizeof(t_ull));
  if (res == NULL)
    return (NULL);
  *res = (t_ull) ((char) va_arg(ap, int));
  return ((void*) res);
}

void		*modif_l(va_list ap)
{
  intmax_t	*res;

  res = malloc(sizeof(intmax_t));
  if (res == NULL)
    return (NULL);
  *res = (intmax_t) va_arg(ap, long);
  return ((void*) res);
}

char	*print_mod(t_param *par, va_list ap)
{
  int	tmp;

  tmp = ap->gp_offset;
  par->c = (char) tmp;
  return (my_strdup("%"));
}

char	*print_unknow(t_param *par, va_list ap)
{
  t_stack	*res;
  int		i;
  int		count;

  ap += 1;
  res = NULL;
  count = 2;
  res = stack_push(res, par->c);
  i = my_strlen(par->flag->patern) - 1;
  res = verif_wap(par, res, &count);
  while (i >= 0)
    {
      if (*(par->flag->ptr_list[i]) == 1 && par->flag->patern[i] != ' ')
	{
	  res = stack_push(res, par->flag->patern[i]);
	  count += 1;
	}
      i -= 1;
    }
  res = stack_push(res, '%');
  ap = (void *) 0;
  return (stack_to_str(res, count));
}
