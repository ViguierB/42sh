/*
** verif_wap.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Nov 18 09:13:03 2016 Benjamin Viguier
** Last update Fri Nov 18 09:16:40 2016 Benjamin Viguier
*/

#include "my.h"

t_stack	*verif_wap(t_param *par, t_stack *res, int *count)
{
  if (par->preci && (*(par->preci) != 0))
    {
      while (*(par->preci))
	{
	  res = stack_push(res, (*(par->preci) % 10) + '0');
	  *(par->preci) /= 10;
	  *count += 1;
	}
      res = stack_push(res, '.');
      *count += 1;
    }
  if (par->width && (*(par->width) != 0))
    {
      while (*(par->width))
	{
	  res = stack_push(res, (*(par->width) % 10) + '0');
	  *(par->width) /= 10;
	  *count += 1;
	}
    }
  return (res);
}
