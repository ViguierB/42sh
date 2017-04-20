/*
** my_printf_extend.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Nov 15 18:18:24 2016 Benjamin Viguier
** Last update Sun Nov 20 15:18:29 2016 Benjamin Viguier
*/

#include "my.h"

void		on_mod(char **format, va_list ap, int *n_count, int can)
{
  t_param	*parm;
  char		*to_print;
  int		*ptr_n;
  int		tmp;

  parm = get_param(format, ap);
  if (parm != NULL)
    {
      if (parm->c == 'n')
	{
	  ptr_n = va_arg(ap, int *);
	  *ptr_n = *n_count;
	}
      else
	{
	  tmp = *n_count;
	  to_print = exec_param(parm, ap, n_count);
	  if (to_print != NULL)
	    write(can, to_print, (*n_count) - tmp);
	  free(to_print);
	}
      free_param(parm);
    }
}

void	check_buffer(int fb, char *buffer, int *i)
{
  *i += 1;
  if (*i >= BUFF_LEN - 1)
    {
      write(fb, buffer, *i);
      *i = 0;
    }
}

void		printf_b(int out, char *format, va_list ap, int *n_count)
{
  int		i;
  char		buffer[BUFF_LEN];

  i = 0;
  while (*format)
    {
      if (*format == '%')
	{
	  write(out, buffer, i);
	  on_mod(&format, ap, n_count, out);
	  i = 0;
	}
      else
	{
	  buffer[i] = *format;
	  *n_count += 1;
	  check_buffer(out, buffer, &i);
	}
      format += 1;
    }
  if (i > 0)
    write(1, buffer, i);
}
