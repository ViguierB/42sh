/*
** param_t_val.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 10 11:49:28 2016 Benjamin Viguier
** Last update Thu Nov 24 18:18:10 2016 Benjamin Viguier
*/

#include "my.h"

int	get_t_val(t_param *par, va_list ap)
{
  if (par->modif.melm != NULL)
    par->modif.data = (par->modif.melm->fct)(ap);
  else
    par->modif.data = modif_i(ap);
  if (par->modif.data == NULL)
    return (-1);
  return (0);
}

int	allowed_flag(t_param *par, char c)
{
  int	i;

  i = 0;
  while (par->allowed[i] != '\0')
    {
      if (par->allowed[i] == c)
	return (1);
      i += 1;
    }
  return (0);
}

/*
** Memo : need_space.c
*/

t_stack	*exec_width(t_param *par, t_stack *stack,
		    t_stack *prev, int *cur_size)
{
  char		to_print;
  char		is_s;
  int		w;
  t_stack	*elm;

  is_s = 0;
  w = *(par->width);
  elm = ew_np(par, stack, &is_s, &to_print);
  w -= *cur_size;
  while (w > 0)
    {
      if (is_s)
	elm = stack_insert(elm, to_print);
      else
	stack = stack_insert_bef(prev, stack, to_print);
      w -= 1;
      *cur_size += 1;
    }
  return (stack);
}

char	*exec_param(t_param *parm, va_list ap, int *n_count)
{
  char	*res;
  int	len;

  if (parm->type != NULL)
    {
      res = (parm->type)(parm, ap);
      len = my_strlen(res);
      *n_count += len;
      return (res);
    }
  else
    {
      res = print_unknow(parm, ap);
      len = my_strlen(res);
      *n_count += len;
      return (res);
		   }
  return (NULL);
}
