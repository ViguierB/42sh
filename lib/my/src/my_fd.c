/*
** my_fd.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 16:23:15 2016 Benjamin Viguier
** Last update Fri Mar  3 10:12:22 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libmy.h"

#ifdef ALLOW_OPEN
t_my_fd		*my_fopen(char *path, int flags)
{
  t_my_fd	*res;
  int		i;

  res = malloc(sizeof(t_my_fd));
  if (!res)
    return (NULL);
  res->len = 0;
  res->rest = 0;
  res->fd = open(path, flags);
  if (res->fd < 0)
    return (NULL);
  i = 0;
  while (i < MY_FD_BUFF_LEN)
    {
      res->buf[i] = 0;
      i += 1;
    }
  return (res);
}
#endif /* !ALLOW_OPEN */

t_my_fd		*my_fd_from_fd(const int fd)
{
  t_my_fd	*res;
  int		i;

  res = malloc(sizeof(t_my_fd));
  if (!res)
    return (NULL);
  res->len = 0;
  res->rest = 0;
  res->fd = fd;
  if (res->fd < 0)
    return (NULL);
  i = 0;
  while (i < MY_FD_BUFF_LEN)
    {
      res->buf[i] = 0;
      i += 1;
    }
  return (res);
}

#ifdef ALLOW_OPEN
void	my_fclose(t_my_fd *to_free)
{
  if (to_free)
    {
      close(to_free->fd);
      free(to_free);
    }
}
#endif /* !ALLOW_OPEN */
