/*
** utils.c for minishell in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr 11 21:31:06 2017 Benjamin Viguier
** Last update Sun May 21 21:11:38 2017 alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
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

int		is_file(char *name)
{
  struct stat	stats;

  if (!stat(name, &stats))
    return (1);
  if (!S_ISDIR(stats.st_mode))
    return (1);
  return (0);
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
	printf("Floating exception");
      else if (WTERMSIG(status) == SIGSEGV)
	printf("Segmentation fault");
      else if (WTERMSIG(status) == SIGBUS)
	printf("Bus error");
#ifdef WCOREDUMP
      printf("%s", ((WCOREDUMP(status)) ? " (core dumped)" : ""));
#endif
      printf("\n");
      sh->last_exit = (unsigned char) WTERMSIG(status) + 128;
    }
  else
    sh->last_exit = (unsigned char) WEXITSTATUS(status);
}

char	*substr(char *str, char *substr, int start, int len)
{
  char	*new_str;
  int	len_add;

  len_add = 0;
  if (substr)
    len_add = my_strlen(substr);
  if (!str || start > my_strlen(str) || start + len > my_strlen(str) ||
      start < 0 || len < 0)
    return (str);
  new_str = NULL;
  if (!(new_str = malloc(sizeof(char) *
			 (my_strlen(str) + len_add - len + 2))))
    return (NULL);
  my_memset(new_str, 0, my_strlen(str) + len_add - len + 2);
  my_strncpy(new_str, str, start);
  if (substr)
    my_strcpy(new_str + start, substr);
  my_strcpy(new_str + start + len_add, str + start + len);
  new_str[my_strlen(str) + len_add - len] = 0;
  return (new_str);
}
