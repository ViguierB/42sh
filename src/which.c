/*
** which.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Wed May 17 19:44:28 2017 Guilhem Fulcrand
** Last update Sun May 21 21:13:59 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "libmy.h"
#include "mysh.h"
#include "parser.h"

int		file_exists(char *str)
{
  struct stat	st;

  if (stat(str, &st) < 0)
    return (0);
  return (1);
}

int	my_which(char **av, t_mysh *sh)
{
  int	i;
  char	*path;

  if (!av[1])
    return (-(my_pcustomwarning("%s: Too few arguments.", av[0])));
  i = 0;
  while (av[++i])
    {
      if (!is_builtin(av[i]))
	printf("%s: shell built-in command.\n", av[i]);
      else if (is_local_cmd(av[i]) && fexists(av[i]))
	printf("%s\n", av[i]);
      else if ((path = search_in_path(sh, av[i])))
        {
	  printf("%s\n", path);
	  free(path);
        }
      else
        {
	  printf("%s: Command not found.\n", av[i]);
	  return (1);
        }
    }
  return (0);
}

int	my_where(char **av, t_mysh *sh)
{
  int	i;
  char	*path;
  int	ret;
  int	exist;

  if (!av[1])
    return (-(my_pcustomwarning("%s: Too few arguments.", av[0])));
  i = 0;
  ret = 0;
  while (av[++i])
    {
      exist = 0;
      if (!is_builtin(av[i]) && (exist = 1))
	printf("%s is a shell built-in\n", av[i]);
      if ((path = search_in_all_paths(sh, av[i])))
        {
	  printf("%s", path);
	  free(path);
	  exist = 1;
        }
      if (!exist)
	ret = 1;
    }
  return (ret);
}
