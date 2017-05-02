/*
** print_int.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 10 11:31:27 2016 Benjamin Viguier
** Last update Wed Nov 16 16:20:25 2016 Benjamin Viguier
*/

#include "my.h"

t_stack	*rec_print_int(long long val, t_stack *res, int *i)
{
  if (val == (long long) 0)
    {
      res = stack_push(res, '0');
      *i += 1;
    }
  else
    {
      while (val != (long long) 0)
	{
	  res = stack_push(res, POS(val % 10) + '0');
	  val /= 10;
	  *i += 1;
	}
    }
  return (res);
}

char	*print_int(t_param *par, va_list ap)
{
  t_stack	*res;
  int		stack_size;
  t_flag_parm	*fp;

  stack_size = 0;
  res = NULL;
  get_t_val(par, ap);
  if (*((long long *) par->modif.data) < 0)
    fp = init_t_flag_p(INT_IDENT, "", '-');
  else
    fp = init_t_flag_p(INT_IDENT, "", '+');
  res = rec_print_int(*((long long *) par->modif.data), res, &stack_size);
  res = exec_flag(par, res, &stack_size, fp);
  free(fp);
  return (stack_to_str(res, stack_size));
}
