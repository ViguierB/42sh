/*
** op_pipe.c for 42sh in /home/ben/epitech/PSU_2016_42sh
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Sat May 20 13:52:00 2017 Benjamin Viguier
** Last update Sun May 21 21:00:21 2017 alexandre Chamard-bois
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

int exec_child(t_mysh *sh, t_tree *node, int fds[2], t_exec_opts	*opts2)
{
  close(fds[1]);
  dup2(fds[0], 0);
  if (execute_tree(sh, node->r, opts2) < 0)
    return (1);
  return (0);
}

int		wait_pipe(t_mysh *sh, pid_t cpid)
{
  t_process	tmp;

  memset(&tmp, 0, sizeof(tmp));
  tmp.pid = cpid;
  wait_child(sh, &tmp);
  return (0);
}

int	init_opts(t_exec_opts *opts1, t_exec_opts *opts2, int fds[2])
{
  pid_t cpid;

  memset(opts1, 0, sizeof(t_exec_opts));
  memset(opts2, 0, sizeof(t_exec_opts));
  opts2->pipe_child = 1;
  opts1->pipe_child = 1;
  if (pipe(fds) < 0)
    return (-1);
  if ((cpid = fork()) < 0)
    return (-1);
  return (cpid);
}

int		op_pipe(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  t_exec_opts	opts1;
  t_exec_opts	opts2;
  int		fds[2];
  pid_t		cpid;

  if ((cpid = init_opts(&opts1, &opts2, fds)) == -1)
    return (pipe_error(opts));
  if (cpid == 0)
    {
      if (exec_child(sh, node, fds, &opts2))
	return (pipe_error(opts));
      exit(sh->last_exit);
    }
  if (opts->pipe_child == 0)
    cpid = fork();
  if (opts->pipe_child == 1 || ((opts->pipe_child == 0) && cpid == 0))
    {
      close(fds[0]);
      dup2(fds[1], 1);
      if (execute_tree(sh, node->l, &opts1) < 0)
	return (pipe_error(opts));
    }
  else
    return (wait_pipe(sh, cpid));
  exit(sh->last_exit);
}
