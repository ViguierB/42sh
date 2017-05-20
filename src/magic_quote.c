/*
** magic_quote.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 20 14:23:32 2017 Alexandre Chamard-bois
** Last update Sat May 20 17:11:48 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libmy.h"
#include "mysh.h"

char *recup_magic(char *cmd, int i, int *size)
{
  int j;

  j = i + 1;
  while (cmd[j] && cmd[j] != '`')
    j++;
  *size = j - i;
  return (my_strndup(cmd + i + 1, *size - 1));
}

char *recup_file()
{
  t_my_fd *fd;
  char *str;

  if (!(fd = my_fopen(". ", O_RDONLY)))
    return (NULL);
  str = NULL;
  my_fread_to_end(fd, &str);
  my_fclose(fd);
  remove(". ");
  return (str);
}

char *magic_quote(t_mysh *sh, char *cmd, int i)
{
  int save;
  int fd;
  int size;
  char *recup;
  char *new_cmd;

  save = dup(1);
  if ((fd = open(". ", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
    return (cmd);
  dup2(fd, 1);
  new_cmd = recup_magic(cmd, i, &size);
  do_cmd(sh, new_cmd);
  close(fd);
  recup = recup_file();
  new_cmd = substr(cmd, recup, i, size + 1);
  free(cmd);
  dup2(save, 1);
  close(save);
  return (new_cmd);
}
