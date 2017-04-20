/*
** my_fread.c for libmy.c in /home/benji_epitech/System_Unix/PSU_2016_bstetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 21 09:59:48 2017 Benjamin Viguier
** Last update Fri Mar 17 11:22:49 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

static char	*__libmy_cat_buf(char *inp, size_t cur_size,
				 char *buf, size_t b_len)
{
  char		*res;
  t_uint	i;

  res = malloc(sizeof(char) * (b_len + cur_size + 1));
  if (!res)
    return (NULL);
  i = 0;
  my_strncpy(res, inp, cur_size);
  while (i < b_len)
    {
      res[i + cur_size] = buf[i];
      i += 1;
    }
  if (inp)
    free(inp);
  return (res);
}

static void	__libmy_flush_fd(t_my_fd *pack, char *buffer,
				 size_t *idx, size_t size)
{
  while (pack->rest != pack->len && *idx < size)
    {
      buffer[*idx] = pack->buf[pack->rest];
      (pack->rest)++;
      (*idx)++;
    }
  if (pack->rest == pack->len)
    {
      pack->len = 0;
      pack->rest = 0;
    }
}

ssize_t		my_fread(t_my_fd *pack, char *buffer, size_t size)
{
  size_t	idx;

  idx = 0;
  if (pack->rest != pack->len)
    __libmy_flush_fd(pack, buffer, &idx, size);
  while (idx < size)
    {
      pack->len = read(pack->fd, pack->buf, MY_FD_BUFF_LEN);
      if (pack->len == 0)
	return ((ssize_t) idx);
      else if (pack->len < 0)
	return (-1);
      __libmy_flush_fd(pack, buffer, &idx, size);
    }
  return ((ssize_t) idx);
}

int		my_fread_to_end(t_my_fd *fd, char **res)
{
  char		buffer[MY_FD_BUFF_LEN];
  ssize_t	len;
  size_t	cur_len;

  cur_len = 0;
  *res = NULL;
  len = my_fread(fd, buffer, MY_FD_BUFF_LEN);
  while (len)
    {
      *res = __libmy_cat_buf(*res, cur_len, buffer, (size_t) len);
      if (!(*res))
	return (-1);
      cur_len += (size_t) len;
      len = my_fread(fd, buffer, MY_FD_BUFF_LEN);
    }
  if (cur_len == 0)
    return (0);
  (*res)[cur_len] = '\0';
  return (cur_len);
}
