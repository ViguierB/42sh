/*
** op_pipe.c for 42sh in /home/ben/epitech/PSU_2016_42sh
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 13:52:00 2017 Benjamin Viguier
** Last update Sat May 20 14:11:26 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <string.h>
#include "parser.h"
#include "mysh.h"

int	pipe_error(t_exec_opts *opts)
{
  if (opts->pipe_child)
    exit(1);
  else
    return (-1);
  return (0);
}

int		op_pipe(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  t_exec_opts	opts1;
  t_exec_opts	opts2;
  int		fds[2];
  pid_t		cpid;

  memset(&opts1, 0, sizeof(opts1));
  memset(&opts2, 0, sizeof(opts2));
  opts2.pipe_child = 1;
  opts1.pipe_child = 1;
  if (pipe(fds) < 0)
    return (pipe_error(opts));
  if ((cpid = fork()) < 0)
    return (pipe_error(opts));
  if (cpid == 0)
    {
      close(fds[1]);
      dup2(fds[0], 0);
      close(fds[0]);
      if (execute_tree(sh, node->r, &opts2) < 0)
	return (pipe_error(opts));
    }
  else
    {
      close(fds[0]);
      dup2(fds[1], 1);
      close(fds[1]);
      if (execute_tree(sh, node->l, &opts1) < 0)
	return (pipe_error(opts));
    }
  if (opts->pipe_child)
    exit (sh->last_exit);
  else
    return (0);
}
