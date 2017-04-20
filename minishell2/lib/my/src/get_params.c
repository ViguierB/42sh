/*
** get_params.c for my_printf in /home/benji_epitech/System_Unix/my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Nov  9 13:42:37 2016 Benjamin Viguier
** Last update Wed Nov 16 19:51:11 2016 Benjamin Viguier
*/

#include "my.h"

t_param		*get_param(char **format, va_list ap)
{
  t_param	*res;
  int		tmp_res;

  if (init_param(&res) == -1)
    return (NULL);
  while (!res->type && !res->ismod)
    {
      if (res->preci)
	{
	  tmp_res = get_type_or_modif(res, format);
	  if (tmp_res == -1)
	    res->ismod = 1;
	}
      else if ((res->flag == NULL) && !get_param_flag(res, format))
	  return (NULL);
      else if (((!res->width && res->flag) &&
		!get_param_width(res, format, ap)) ||
	       ((!res->preci && res->width) && !get_param_preci(res, format, ap)))
	return (NULL);
    }
  return (res);
}

int	get_param_flag(t_param *par, char **format)
{
  char	**flag_list;

  par->flag = init_flag();
  flag_list = get_flag_blist(par->flag);
  if (par->flag == NULL || (flag_list == NULL))
    return (0);
  if (**format == '%')
    *format += 1;
  search_flags(par, format, flag_list);
  return (1);
}

int		get_param_width(t_param *par, char **format, va_list ap)
{
  par->width = malloc(sizeof(int));
  if (par->width == NULL)
    return (0);
  *(par->width) = 0;
  if (IS_NUM(**format))
    {
      *format = my_get_u_nbr(*format, (t_uint*) par->width);
      *format += 1;
    }
  else if (**format == '*')
    {
      *(par->width) = va_arg(ap, int);
      *format += 1;
    }
  return (1);
}

int		get_param_preci(t_param *par, char **format, va_list ap)
{
  par->preci = malloc(sizeof(int));
  if (par->width == NULL)
    return (0);
  *(par->preci) = 0;
  if (**format == '.')
    {
      *format += 1;
      if (IS_NUM(**format))
	{
	  *format = my_get_u_nbr(*format, (t_uint*) par->preci);
	  *format += 1;
	}
      else if (**format == '*')
	{
	  *(par->preci) = va_arg(ap, int);
	  *format += 1;
	}
    }
  return (1);
}

int	get_type_or_modif(t_param *par, char **format)
{
  int		i;

  i = 0;
  if (par->modif.data == NULL)
      get_modif(par, format);
  par->c = **format;
  while (g_tab_tfct[i].fct != NULL)
    {
      if (g_tab_tfct[i].type == **format)
	{
	  par->type = g_tab_tfct[i].fct;
	  par->allowed = g_tab_tfct[i].allowed_flag;
	  par->preci_type = g_tab_tfct[i].preci_type;
	  return (1);
	}
      i += 1;
    }
  i = 0;
  par->ismod = 1;
  return (-1);
}
