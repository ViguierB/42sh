/*
** need_space_bis.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Nov 16 18:36:04 2016 Benjamin Viguier
** Last update Wed Nov 30 21:53:01 2016 Benjamin Viguier
*/

#include "my.h"

t_stack_pair	*creat_pair(t_stack *a, t_stack *b)
{
  t_stack_pair	*res;

  res = malloc(sizeof(t_stack_pair));
  if (res == NULL)
    return (NULL);
  res->stack = a;
  res->prev = b;
  return (res);
}

t_stack	*exec_int_preci(t_param *par, t_stack_pair *pair, int *s)
{
  if (*(par->preci) != 0)
    {
      while (*s < *(par->preci))
	{
	  if (allowed_flag(par, '0'))
	    pair->stack = stack_push(pair->stack, '0');
	  else
	    pair->stack = stack_push(pair->stack, ' ');
	  *s += 1;
	}
      if (par->flag->z_f)
	par->flag->z_f = 0;
    }
  return (pair->stack);
}

t_stack	*exec_str_preci(t_param *par, t_stack_pair *pair, int *s)
{
  t_stack	*elm;
  char		tmp;
  int		i;

  elm = pair->stack;
  if (*(par->preci) != 0)
    {
      i = 0;
      while (i < *(par->preci))
	{
	  if (elm)
	    elm = elm->next;
	  i += 1;
	}
      while (elm)
	{
	  elm = stack_peek(elm, &tmp);
	}
      *s = *(par->preci);
      if (allowed_flag(par, '-') && par->flag->m_f)
	*s -= i;
    }
  elm = pair->stack;
  free(pair);
  return (elm);
}

void   r_push_stack(t_stack **stack, int *s, t_flag_parm *flag)
{
  *stack = stack_push(*stack, flag->p);
  *s += 1;
}
