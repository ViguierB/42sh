/*
** execute.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Thu Apr  6 18:14:46 2017 Benjamin Viguier
** Last update Thu May 18 10:16:55 2017 Alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "mysh.h"
#include "parser.h"
#include "my_env.h"

int	redir_ff(t_mysh_fd *fd, int mpp[2])
{
  int	file_fd;

  (void) mpp;
  if (fd->filename)
    {
      file_fd = open(fd->filename, fd->flags, fd->right);
      if (file_fd < 0)
	return (my_pwarning(fd->filename));
      dup2(file_fd, fd->fd);
      fd->fd = file_fd;
    }
  return (0);
}

int	execute_cmd(t_mysh *sh, t_process *proc, t_exec_opts *opts)
{
  if (opts->need_redir - 1 == 0 && proc->in.filename)
    return (my_warning(proc->name, "Ambiguous input redirect"));
  if (opts->need_redir - 1 == 1 && proc->out.filename)
    return (my_warning(proc->name, "Ambiguous output redirect"));
  if (opts->need_redir - 1 == 2 && proc->err.filename)
    return (my_warning(proc->name, "Ambiguous error output redirect"));
  if (!(proc->name = get_real_cmd(sh, proc)))
    return (my_pcustomwarning("%s: Command not found.\n", proc->args[0]));
  if (!proc->builtin)
    {
      // if (is_file(proc->name))
      //   return (my_pcustomwarning("%s: Permission denied.\n", proc->args[0]));
      if ((proc->pid = fork()) < 0)
	return (my_perror("fork()"));
      if (proc->pid == 0)
	{
	  if (redir_ff(&(proc->in), opts->pipe_in) < 0 ||
	      redir_ff(&(proc->out), opts->pipe_out) < 0 ||
	      redir_ff(&(proc->err), opts->pipe_err) < 0)
	    return (-1);
	  execve(proc->name, proc->args, my_env(sh->env));
    exit(1);
	}
      else if (!opts->ascyn)
	wait_child(sh, proc);
  free(proc->name);
    }
  else
    exec_builtin(sh, proc, opts);
  return (0);
}

int	execute_tree(t_mysh *sh, t_tree *tree, t_exec_opts *opts)
{
  if (!tree)
    return (-1);
  if (tree->type == NODE_SEP)
    {
      if (CAST_OPFCT(tree->value.token.value.info.fct)(sh, tree, opts) < 0)
	return (-1);
    }
  else if (tree->type == NODE_CMD)
    {
      if (execute_cmd(sh, &(tree->value.proc), opts))
      {
        sh->last_exit = 1;
        var_last_ret(sh);
        return (-1);
      }
      var_last_ret(sh);
    }
  return (0);
}
