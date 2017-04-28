/*
** modif_spe_funt_bis.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun Nov 13 15:57:20 2016 Benjamin Viguier
** Last update Wed Nov 16 13:57:20 2016 Benjamin Viguier
*/

#include "my.h"

void	*modif_h(va_list ap)
{
  t_ull	*res;

  res = malloc(sizeof(t_ull));
  if (res == NULL)
    return (NULL);
  *res = (t_ull) ((short) va_arg(ap, int));
  return ((void*) res);
}

int	get_modif(t_param *par, char **format)
{
  int	i;
  int	cont;

  i = 0;
  cont = 1;
  while (cont && g_tab_mfct[i].modif != NULL)
    {
      if (g_tab_mfct[i].modif[0] == **format)
	{
	  par->modif.melm = &(g_tab_mfct[i]);
	  *format += 1;
	  cont = 0;
	}
      i += 1;
    }
  get_fct(par, format);
  if (par->modif.melm == NULL)
    par->modif.melm = &(g_tab_mfct[i - 1]);
  return (0);
}

int	get_fct(t_param *par, char **format)
{
  int	i;
  int	cont;

  i = 0;
  cont = 1;
  while (cont && g_tab_mfct[i].modif != NULL)
    {
      if (g_tab_mfct[i].modif[0] == *(*format - 1) &&
	  (g_tab_mfct[i].modif[1] == **format))
	{
	  par->modif.melm = &(g_tab_mfct[i]);
	  *format += 1;
	  cont = 0;
	}
      i += 1;
    }
  return (0);
}

int	init_param(t_param **res)
{
  *res = malloc(sizeof(t_param));
  if (*res == NULL)
    return (-1);
  (*res)->modif.data = NULL;
  (*res)->modif.melm = NULL;
  (*res)->type = NULL;
  (*res)->preci = NULL;
  (*res)->width = NULL;
  (*res)->flag = NULL;
  (*res)->ismod = 0;
  (*res)->c = '\0';
  return (0);
}

int	free_param(t_param *to_free)
{
  if (to_free)
    {
      if (to_free->preci != NULL)
	free(to_free->preci);
      if (to_free->width != NULL)
	free(to_free->width);
      if (to_free->flag != NULL)
	free_flag(to_free->flag);
      if (to_free->modif.data != NULL)
	free(to_free->modif.data);
      free(to_free);
    }
  return (0);
}
