/*
** flag_format.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Nov 15 12:38:09 2016 Benjamin Viguier
** Last update Tue Nov 15 14:11:26 2016 Benjamin Viguier
*/

#include "my.h"

t_flag		*init_flag(void)
{
  t_flag	*res;

  res = malloc(sizeof(t_flag));
  if (res == NULL)
    return (NULL);
  res->patern = my_strdup("#-+ 0'");
  if (res->patern == NULL)
    return (NULL);
  res->d_f = 0;
  res->m_f = 0;
  res->p_f = 0;
  res->s_f = 0;
  res->z_f = 0;
  res->a_f = 0;
  get_flag_blist(res);
  return (res);
}

char		**get_flag_blist(t_flag *f)
{
  char		**list;

  list = malloc(sizeof(char *) * 7);
  if (list == NULL || (f == NULL))
    return (NULL);
  list[0] = &(f->d_f);
  list[1] = &(f->m_f);
  list[2] = &(f->p_f);
  list[3] = &(f->s_f);
  list[4] = &(f->z_f);
  list[5] = &(f->a_f);
  list[6] = NULL;
  f->ptr_list = list;
  return (list);
}

void	free_flag(t_flag *f)
{
  if (f)
    {
      if (f->patern)
	free(f->patern);
      if (f->ptr_list)
	free(f->ptr_list);
      free(f);
    }
}

int	get_flag_pos(t_flag *f, char c)
{
  int	i;

  i = 0;
  while (f->patern[i] != '\0')
    {
      if (f->patern[i] == c)
	return (i);
      i += 1;
    }
  return (-1);
}

int	search_flags(t_param *par, char **format, char **flag_list)
{
  char	match;
  char	one_match;
  int	i;

  one_match = 0;
  match = 1;
  while (match)
    {
      match = 0;
      i = 0;
      while (par->flag->patern[i] != '\0' && !match)
	{
	  if (par->flag->patern[i] == **format)
	    {
	      *(flag_list[i]) = 1;
	      *format += 1;
	      match = 1;
	      one_match = 1;
	    }
	  i += 1;
	}
    }
  return (one_match);
}
