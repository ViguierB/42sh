/*
** my_getline.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 12:46:31 2016 Benjamin Viguier
** Last update Mon Jan 16 10:20:41 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

int	init_values(t_my_fd *pack, int *on_nl)
{
  int	i;

  i = pack->rest;
  while (pack->buf[i] != '\n' && i < pack->len)
    i += 1;
  if (pack->buf[i] == '\n')
    {
      *on_nl = 1;
      i += 1;
    }
  return (i);
}

char	*copy_now(t_my_fd *pack, int cur_len,
		 char *res, int new_len)
{
  int	j;
  int	k;
  char	*new_str;

  new_str = malloc(sizeof(char) * (new_len));
  if (!new_str)
    return (NULL);
  j = 0;
  k = pack->rest;
  while (j < new_len - 1)
    {
      if (j < cur_len)
	new_str[j] = res[j];
      else
	{
	  new_str[j] = pack->buf[k];
	  k += 1;
	}
      j += 1;
    }
  new_str[j] = '\0';
  return (new_str);
}

int	cpy_to_nl(char **res, t_my_fd *pack,
		  int *cur_len, int *on_nl)
{
  char	*new_str;
  int	new_len;
  int	i;

  i = init_values(pack, on_nl);
  new_len = *cur_len + (i - pack->rest) + 1 - *on_nl;
  new_str = copy_now(pack, *cur_len, *res, new_len);
  if (!new_str)
    return (-1);
  pack->rest = i;
  if (*res)
    free(*res);
  *cur_len = new_len - 1;
  *res = new_str;
  if (i == pack->len)
    {
      pack->len = 0;
      pack->rest = 0;
    }
  return (0);
}

char	*my_getline(t_my_fd *pack)
{
  char	*res;
  int	cur_len;
  int	on_nl;

  res = NULL;
  on_nl = 0;
  cur_len = 0;
  if (pack->rest != pack->len)
    if (cpy_to_nl(&res, pack, &cur_len, &on_nl) < 0)
      return (NULL);
  while (!on_nl)
    {
      pack->len = read(pack->fd, pack->buf, MY_FD_BUFF_LEN);
      if (pack->len == 0)
	return (res);
      else if (pack->len < 0)
	return (NULL);
      if (cpy_to_nl(&res, pack, &cur_len, &on_nl) < 0)
	return (NULL);
    }
  return (res);
}
