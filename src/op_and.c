/*
** op_and.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Fri Apr  7 11:43:08 2017 Benjamin Viguier
** Last update Sat May 13 14:51:47 2017 Alexandre Chamard-bois
*/

#include "parser.h"
#include "mysh.h"

int	op_or(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  my_memset(opts, 0, sizeof(*opts));
  if (execute_tree(sh, node->l, opts) < 0)
    return (-1);
  if (opts->exit_code)
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
  if (!opts->exit_code)
    {
      my_memset(opts, 0, sizeof(*opts));
      if (execute_tree(sh, node->r, opts) < 0)
	return (-1);
    }
  return (0);
}

int		op_pipe(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  t_exec_opts	opts2;

  //  my_memset(opts, 0, sizeof(
  opts->ascyn = 1;
  if (execute_tree(sh, node->l, opts) < 0)
    return (-1);
  //  opts
}

int	op_next(t_mysh *sh, t_tree *node, t_exec_opts *opts)
{
  my_memset(opts, 0, sizeof(*opts));
  if (execute_tree(sh, node->l, opts) < 0)
    return (-1);
  my_memset(opts, 0, sizeof(*opts));
  if (execute_tree(sh, node->r, opts) < 0)
    return (-1);
  return (0);
}
