/*
** script.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 20 11:41:16 2017 Alexandre Chamard-bois
** Last update Sun May 21 21:09:12 2017 alexandre Chamard-bois
*/

#include <fcntl.h>
#include "mysh.h"
#include "42shrc.h"
#include "my_env.h"

int end_script_main(t_mysh *sh)
{
  free_env(sh->env);
  clist_free_data(sh->hist, free);
  clist_free_data(sh->alias, free_alias);
  free(sh->in);
  return (sh->last_exit);
}

int	init_script(t_mysh *sh, int ac, char **av)
{
  char	*bla[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  int	i;

  if (!(sh->in = my_fopen(av[1], O_RDONLY)))
    {
      sh->last_exit = 1;
      return (1);
    }
  i = 1;
  while (i < ac - 1 && i < 10)
    {
      if (var_set(sh, bla[i - 1], av[i]))
	{
	  sh->last_exit = 1;
	  return (1);
	}
      i++;
    }
  return (0);
}

int	main_script(int ac, char **av, t_mysh *sh)
{
  char	*cmd;

  if (init_script(sh, ac, av))
    exit(end_script_main(sh));
  while (!sh->exit && (cmd = my_getline(sh->in)))
    {
      cmd = clean_line(cmd);
      if (*cmd && *cmd != COMMENT_CHAR)
	do_cmd(sh, cmd);
      free(cmd);
    }
  exit(end_script_main(sh));
}
