/*
** print_char.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Nov 14 17:20:21 2016 Benjamin Viguier
** Last update Wed Nov 16 10:15:47 2016 Benjamin Viguier
*/

#include "my.h"

char		*print_char(t_param *par, va_list ap)
{
  char		c;
  t_stack	*res;
  int		stack_size;
  t_flag_parm	*fp;

  c = (char) va_arg(ap, int);
  res = NULL;
  res = stack_push(res, c);
  stack_size = 1;
  fp = init_t_flag_p(CHA_IDENT, "", '\0');
  res = exec_flag(par, res, &stack_size, fp);
  return (stack_to_str(res, stack_size));
}

t_stack	*rev_print_str(t_stack *res, unsigned char *str,
		       int *stack_size, int b)
{
  int	j;

  if (*str)
    {
      res = rev_print_str(res, str + 1, stack_size, b);
      if (IS_PRINTABLE(*str) || b == 0)
	{
	  res = stack_push(res, *str);
	  *stack_size += 1;
	}
      else if (b)
	{
	  j = 0;
	  while (j < 3)
	    {
	      res = stack_push(res, (*str & 0x7) + '0');
	      *str = *str >> 3;
	      j += 1;
	    }
	  res = stack_push(res, '\\');
	  *stack_size += 4;
	}
    }
  return (res);
}

char		*c_print_str(t_param *par, va_list ap, int b)
{
  unsigned char	*str;
  t_stack	*res;
  int		stack_size;
  t_flag_parm	*fp;

  str = va_arg(ap, unsigned char *);
  if (str == NULL)
    return (my_strdup(""));
  res = NULL;
  stack_size = 0;
  res = rev_print_str(res, str, &stack_size, b);
  fp = init_t_flag_p(STR_IDENT, "", '\0');
  res = exec_flag(par, res, &stack_size, fp);
  free(fp);
  return (stack_to_str(res, stack_size));
}

char	*print_str(t_param *par, va_list ap)
{
  return (c_print_str(par, ap, 0));
}

char	*print_bstr(t_param *par, va_list ap)
{
  return (c_print_str(par, ap, 1));
}
