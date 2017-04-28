/*
** utils.c for minishell in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr 11 21:31:06 2017 Benjamin Viguier
** Last update Fri Apr 28 13:15:34 2017 Alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include "mysh.h"

int		fexists(char *name)
{
  struct stat	buf;

  if (stat(name, &buf) < 0)
    {
      return (0);
    }
  else
    return (1);
}

int	is_local_cmd(char *name)
{
  if (!name)
    return (0);
  if (!my_strncmp(name, "./", 2) ||
      !my_strncmp(name, "../", 3) ||
      !my_strncmp(name, "/", 1))
    return (1);
  while (*name)
    if (*(name++) == '/')
      return (1);
  return (0);
}

void	wait_child(t_mysh *sh, t_process *proc)
{
  int	status;

  waitpid(proc->pid, &status, 0);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGFPE)
	my_printf("Floating exception (core dumped)\n");
      else if (WTERMSIG(status) == SIGSEGV)
	my_printf("Segmentation fault (core dumped)\n");
      else if (WTERMSIG(status) == SIGBUS)
	my_printf("Bus error (core dumped)\n");
    }
  sh->last_exit = WIFCONTINUED(&status);
}
