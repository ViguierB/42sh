/*
** flag.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Nov 15 14:33:09 2016 Benjamin Viguier
** Last update Fri Nov 18 09:23:59 2016 Benjamin Viguier
*/

#include "my.h"

t_flag_parm	*init_t_flag_p(int ident, char *str, char c)
{
  t_flag_parm	*flag;

  flag = malloc(sizeof(t_flag_parm));
  if (flag == NULL)
    return (NULL);
  flag->pos = ident;
  flag->d = str;
  flag->p = c;
  return (flag);
}

int	verif_p(t_param *par, t_stack **stack,
		 t_stack **prev, t_flag_parm *flag)
{
  int	i;

  i = 0;
  if (allowed_flag(par, '#') && par->flag->d_f)
    while (flag->d[i] != '\0')
      {
	*stack = stack_push(*stack, flag->d[my_strlen(flag->d) - 1 - i]);
	if (i == 0)
	  *prev = *stack;
	i += 1;
      }
  return (i);
}

void	extend_ex_flag(t_param *par, t_stack **stack, t_stack **prev, int *s)
{
  if (allowed_flag(par, ' ') && (par->flag->s_f))
    {
      *stack = stack_push(*stack, ' ');
      *prev = *stack;
      *s += 1;
    }
}

t_stack		*pre_preci(t_param *par, t_stack_pair *pair, int *s)
{
  t_stack	*res;

  if (par->preci_type == 1)
    res = (exec_int_preci(par, pair, s));
  else
    res = (pair->stack);
  free(pair);
  return (res);
}

t_stack		*exec_flag(t_param *par, t_stack *stack,
			   int *s, t_flag_parm *flag)
{
  t_stack	*elm;
  t_stack	*prev;

  elm = stack;
  prev = NULL;
  stack = pre_preci(par, creat_pair(stack, prev), s);
  *s += verif_p(par, &stack, &prev, flag);
  extend_ex_flag(par, &stack, &prev, s);
  if ((allowed_flag(par, '+') && (par->flag->p_f || (flag->p == '-'))))
    {
      if (allowed_flag(par, ' ') && (par->flag->s_f))
	stack->c = flag->p;
      else
	r_push_stack(&stack, s, flag);
      prev = stack;
    }
  if (par->preci_type == 2)
    stack = exec_str_preci(par, creat_pair(stack, prev), s);
  if ((allowed_flag(par, '#') && allowed_flag(par, '0') && par->flag->z_f) ||
      (allowed_flag(par, '+') && allowed_flag(par, '0') && par->flag->z_f))
    exec_width(par, elm, prev, s);
  else
    stack = exec_width(par, stack, NULL, s);
  return (stack);
}
