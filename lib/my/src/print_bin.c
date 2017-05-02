/*
** print_bin.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Nov 16 11:47:16 2016 Benjamin Viguier
** Last update Wed Nov 16 16:21:51 2016 Benjamin Viguier
*/

#include "my.h"

t_stack		*rev_print_bin(t_val val, t_stack *stack, int *i)
{
  char		*patern;
  short		cur;
  int		j;
  intmax_t	tmpval;

  patern = my_strdup("01");
  j = 0;
  tmpval = *((t_ull *) val.data);
  while ((j < (val.melm->len * 4)) && tmpval != 0)
    {
      cur = tmpval & 0x1;
      stack = stack_push(stack, patern[(int) cur]);
      tmpval = tmpval >> 1;
      j += 1;
      *i += 1;
    }
  free(patern);
  return (stack);
}

char		*print_bin(t_param *par, va_list ap)
{
  t_stack	*res;
  int		stack_size;
  t_flag_parm	*fp;

  stack_size = 0;
  get_t_val(par, ap);
  res = NULL;
  fp = init_t_flag_p(BIN_IDENT, "0b", '\0');
  if (*((t_ull *) par->modif.data) == 0)
    {
      free(fp);
      fp = init_t_flag_p(BIN_IDENT, "", '\0');
      res = stack_push(res, '0');
      stack_size += 1;
    }
  else
    res = rev_print_bin(par->modif, res, &stack_size);
  res = exec_flag(par, res, &stack_size, fp);
  free(fp);
  return (stack_to_str(res, stack_size));
}
