/*
** print_xhex.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Nov 14 11:59:26 2016 Benjamin Viguier
** Last update Wed Nov 16 16:20:49 2016 Benjamin Viguier
*/

#include "my.h"

t_stack		*rev_print_hex(t_val val, t_stack *stack, int *i, int b)
{
  char		*patern;
  short		cur;
  int		j;
  long long	tmpval;

  if (b)
    patern = my_strdup("0123456789ABCDEF");
  else
    patern = my_strdup("0123456789abcdef");
  j = 0;
  tmpval = *((long long *) val.data);
  while (j < val.melm->len && tmpval != 0)
    {
      cur = tmpval & 0xF;
      stack = stack_push(stack, patern[(int) cur]);
      tmpval = tmpval >> 4;
      j += 1;
      *i += 1;
    }
  free(patern);
  return (stack);
}

char	*b_print_hex(t_param *par, t_stack *res, va_list ap, int b)
{
  int		stack_size;
  t_flag_parm	*fp;

  stack_size = 0;
  get_t_val(par, ap);
  if (b)
    fp = init_t_flag_p(HEX_IDENT, "0X", '\0');
  else
    fp = init_t_flag_p(HEX_IDENT, "0x", '\0');
  if (*((long long *) par->modif.data) == 0)
    {
      free(fp);
      fp = init_t_flag_p(HEX_IDENT, "", '\0');
      res = stack_push(res, '0');
      stack_size += 1;
    }
  else
    res = rev_print_hex(par->modif, res, &stack_size, b);
  res = exec_flag(par, res, &stack_size, fp);
  free(fp);
  return (stack_to_str(res, stack_size));
}

char		*print_xhex(t_param *par, va_list ap)
{
  t_stack	*res;

  res = NULL;
  return (b_print_hex(par, res, ap, 0));
}

char	*print_bxhex(t_param *par, va_list ap)
{
  t_stack	*res;

  res = NULL;
  return (b_print_hex(par, res, ap, 1));
}
