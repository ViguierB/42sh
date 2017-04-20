/*
** print_uint.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Nov 14 11:50:38 2016 Benjamin Viguier
** Last update Wed Nov 16 16:20:36 2016 Benjamin Viguier
*/

#include "my.h"

t_stack	*rec_print_uint(t_val val2, t_stack *res, int *i)
{
  t_ull	val;

  val = *((t_ull *) val2.data);
  if (val == 0)
    {
      res = stack_push(res, '0');
      *i += 1;
      return (res);
    }
  while (val != 0)
    {
      res = stack_push(res, val % 10 + '0');
      val = val / 10;
      *i += 1;
    }
  return (res);
}

char	*print_uint(t_param *par, va_list ap)
{
  t_stack	*res;
  t_flag_parm	*fp;
  int		stack_size;

  stack_size = 0;
  res = NULL;
  get_t_val(par, ap);
  fp = init_t_flag_p(INT_IDENT, "", '+');
  res = rec_print_uint(par->modif, res, &stack_size);
  res = exec_flag(par, res, &stack_size, fp);
  return (stack_to_str(res, stack_size));
}
