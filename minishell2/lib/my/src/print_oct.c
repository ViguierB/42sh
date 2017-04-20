/*
** print_oct.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Nov 15 20:00:14 2016 Benjamin Viguier
** Last update Fri Nov 18 09:05:42 2016 Benjamin Viguier
*/

#include "my.h"

t_stack		*rev_print_oct(t_val val, t_stack *stack, int *i)
{
  char		*patern;
  int		end;
  int		j;
  intmax_t	tmpval;

  patern = my_strdup("01234567");
  j = 0;
  end = ((int) (((float) val.melm->len) * (4.0/3.0)) + 1);
  tmpval = *((t_ull *) val.data);
  while (j < end && tmpval != 0)
    {
      if (!((j + 1 < end)))
	stack = stack_push(stack, patern[(int) (tmpval & (0x7 / (end % 3)))]);
      else
	stack = stack_push(stack, patern[(int) (tmpval & 0x7)]);
      tmpval = tmpval >> 3;
      j += 1;
      *i += 1;
    }
  free(patern);
  return (stack);
}

char	*print_oct(t_param *par, va_list ap)
{
  t_stack	*res;
  int		stack_size;
  t_flag_parm	*fp;

  stack_size = 0;
  res = NULL;
  get_t_val(par, ap);
  fp = init_t_flag_p(OCT_IDENT, "0", '\0');
  if (*((t_ull *) par->modif.data) == 0)
    {
      free(fp);
      fp = init_t_flag_p(OCT_IDENT, "", '\0');
      res = stack_push(res, '0');
      stack_size += 1;
    }
  else
    res = rev_print_oct(par->modif, res, &stack_size);
  res = exec_flag(par, res, &stack_size, fp);
  free(fp);
  return (stack_to_str(res, stack_size));
}
