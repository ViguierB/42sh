/*
** history.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Thu May 18 20:54:01 2017 Guilhem Fulcrand
** Last update Mon May 29 16:43:21 2017 Alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mysh.h"

t_clist *init_hist()
{
  t_clist *hist;
  char *str;
  t_my_fd *fd;

  hist = NULL;
  if (!(fd = my_fopen(".history", O_RDONLY)))
    return (NULL);
  while ((str = my_getline(fd)))
    hist = clist_push(hist, str);
  my_fclose(fd);
  return (hist);
}

t_clist     *push_in_hist(t_clist *hist, char *cmd)
{
  if (!hist || my_strcmp((char *)hist->ptr, cmd) != 0)
    hist = clist_push(hist, cmd);
  return (hist);
}

void            print_hist(t_clist *hist)
{
  t_clist	*tmp;

  tmp = hist;
  while (tmp)
    {
      printf("%s\n", (char *)tmp->ptr);
      tmp = CLIST_NEXT(hist, tmp);
    }
}

void save_hist(t_clist *hist)
{
  t_clist *list;
  int fd;

  if ((fd = open(".history", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
    return ;
  list = hist;
  while (list)
  {
    dprintf(fd, "%s\n", (char*)list->ptr);
    list = CLIST_NEXT(hist, list);
  }
  close(fd);
}
