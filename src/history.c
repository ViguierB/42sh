/*
** history.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Thu May 18 20:54:01 2017 Guilhem Fulcrand
** Last update Sun May 21 20:27:17 2017 alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mysh.h"

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
