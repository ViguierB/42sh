/*
** op_and.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Fri Apr  7 11:43:08 2017 Benjamin Viguier
** Last update Wed May 17 15:26:17 2017 Benjamin Viguier
*/

#include "parser.h"
#include "mysh.h"

int	op_or(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  my_memset(opts, 0, sizeof(*opts));
  if (execute_tree(sh, node->l, opts) < 0)
    return (-1);
  if (sh->last_exit)
    {
      my_memset(opts, 0, sizeof(*opts));
      if (execute_tree(sh, node->r, opts) < 0)
	return (-1);
    }
  return (0);
}

int	op_and(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  my_memset(opts, 0, sizeof(*opts));
  if (execute_tree(sh, node->l, opts) < 0)
    return (-1);
  if (!sh->last_exit)
    {
      my_memset(opts, 0, sizeof(*opts));
      if (execute_tree(sh, node->r, opts) < 0)
	return (-1);
    }
  return (0);
}

int		op_pipe(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  t_exec_opts	opts1;
  t_exec_opts	opts2;
  int		fds[4];
  
  my_memset(&opts1, 0, sizeof(opts1));
  if (pipe(opts1.pipe_out) < 0 || pipe(opts1.pipe_in) < 0)
    return (-1);
  opts->ascyn = 1;
  close(opts1.pipe_out[0]);
  dup2(opts1.pipe_out[1], 1);
  close(opts1.pipe_out[1]);
  if (execute_tree(sh, node->l, opts) < 0)
    return (-1);
  
  my_memset(&opts2, 0, sizeof(opts2));
  if (execute_tree(sh, node->r, &opts2) < 0)
    return (-1);
  
}

int	op_next(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  my_memset(opts, 0, sizeof(*opts));
  if (node->l && node->l->value.token.value.cmd)
    execute_tree(sh, node->l, opts);
  my_memset(opts, 0, sizeof(*opts));
  if (node->r && node->r->value.token.value.cmd)
    execute_tree(sh, node->r, opts);
  return (0);
}
