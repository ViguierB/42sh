/*
** modif_spe_funt.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 10 16:13:27 2016 Benjamin Viguier
** Last update Wed Nov 16 11:42:52 2016 Benjamin Viguier
*/

#include "my.h"

void	*modif_i(va_list ap)
{
  t_ull	*res;

  res = malloc(sizeof(t_ull));
  if (res == NULL)
    return (NULL);
  *res = (t_ull) va_arg(ap, int);
  return ((void*) res);
}

void		*modif_ll(va_list ap)
{
  intmax_t	*res;

  res = malloc(sizeof(intmax_t));
  if (res == NULL)
    return (NULL);
  *res =  (intmax_t) va_arg(ap, long long int);
  return ((void*) res);
}

void		*modif_z(va_list ap)
{
  size_t	*res;

  res = malloc(sizeof(intmax_t));
  if (res == NULL)
    return (NULL);
  *res = (intmax_t) va_arg(ap, size_t);
  return ((void*) res);
}

void		*modif_j(va_list ap)
{
  intmax_t	*res;

  res = malloc(sizeof(intmax_t));
  if (res == NULL)
    return (NULL);
  *res = va_arg(ap, intmax_t);
  return ((void*) res);
}
