/*
** print_ptr.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Nov 15 20:30:50 2016 Benjamin Viguier
** Last update Sun Nov 20 15:18:28 2016 Benjamin Viguier
*/

#include "my.h"

t_stack		*is_null(int *stack_size)
{
  t_stack	*stack;
  const char	tmp[] = "(nil)";
  int		i;

  stack = NULL;
  i = 4;
  while (i >= 0)
    {
      *stack_size += 1;
      stack = stack_push(stack, tmp[i]);
      i -= 1;
    }
  return (stack);
}

t_stack		*en_print_ptr(long long ptr, int *stack_size)
{
  t_stack	*res;
  const char	patern[] = "0123456789abcdef";

  res = NULL;
  while (ptr != 0)
    {
      res = stack_push(res, patern[ptr & 0xF]);
      ptr = ptr >> 4;
      *stack_size += 1;
    }
  return (res);
}

char		*print_ptr(t_param *par, va_list ap)
{
  t_stack	*res;
  void		*ptr;
  int		stack_size;
  t_flag_parm	*fp;

  stack_size = 0;
  ptr = va_arg(ap, void *);
  fp = init_t_flag_p(PTR_IDENT, "", '\0');
  if (ptr == NULL)
    res = is_null(&stack_size);
  else
    {
      free(fp);
      par->flag->d_f = 1;
      fp = init_t_flag_p(PTR_IDENT, "0x", '\0');
      res = en_print_ptr((long long) ptr, &stack_size);
    }
  res = exec_flag(par, res, &stack_size, fp);
  free(fp);
  return (stack_to_str(res, stack_size));
}
