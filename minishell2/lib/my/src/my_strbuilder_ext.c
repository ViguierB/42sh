/*
** my_strbuilder_ext.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Thu Feb 23 14:58:19 2017 Benjamin Viguier
** Last update Wed Apr  5 17:12:06 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "internal.h"

int	__libmy_sb_flush(t_strbuilder *sb)
{
  char		*res;
  size_t	i;
  size_t	j;

  res = malloc(sizeof(char) * (sb->res_len + sb->len + 1));
  if (!res)
    return (-1);
  my_memcpy(res, sb->res, sb->pos);
  i = sb->pos;
  j = 0;
  while (j < sb->len)
    {
      res[i] = sb->buf[j];
      j++;
      i++;
    }
  my_memcpy(res + i - 1, sb->res + sb->pos, sb->res_len - sb->pos);
  sb->res_len = sb->res_len + sb->len;
  sb->pos += j;
  sb->len = 0;
  res[sb->res_len + sb->len] = '\0';
  free(sb->res);
  sb->res = res;
  return (0);
}

int	__libmy_sb_need_flush(t_strbuilder *sb)
{
  if (!(sb->len < MY_FD_BUFF_LEN))
    {
      return (__libmy_sb_flush(sb));
    }
  return (0);
}

int	my_sb_ecrase(t_strbuilder *sb, size_t len)
{
  char	*res;

  if (sb->len)
    while (sb->len && len)
      {
	(sb->len)--;
	len--;
      }
  if (len)
    {
      if (sb->pos - len)
	sb->pos = MAX(sb->pos - len, 0);
      if (!(res = malloc(sizeof(char) * (sb->res_len - len + 1))))
	return (-1);
      my_memcpy(res, sb->res, sb->pos);
      my_memcpy(res, sb->res + sb->pos + len, sb->res_len - sb->pos - len);
      free(sb->res);
      sb->res = res;
      return (0);
    }
  return (0);
}

void	my_sb_destroy(t_strbuilder *sb)
{
  free(sb->res);
  free(sb);
}
