/*
** main.c for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Apr  3 15:09:58 2017 Benjamin Viguier
** Last update Tue May 16 23:09:48 2017 Guilhem Fulcrand
*/

#include <unistd.h>
#include "mysh.h"
#include "my_env.h"
#include "parser.h"
#include "42shrc.h"

t_my_fd *init_main(int ac, t_mysh *sh, char **av, char **env)
{
  (void) ac;
  my_memset(sh, 0, sizeof(*sh));
  my_init_env(&sh->env, env);
  sh->alias = my_source(NULL);
  my_name(LIBMY_INIT, av[0]);
  return (my_fd_from_fd(0));
}

char *waitline(t_my_fd *in)
{
  char buff[255];
  char *cmd;

  if (isatty(0))
  {
    getcwd(buff, 255);
    my_printf("%s$> ", buff);
  }
  if (!(cmd = my_getline(in)))
    return (NULL);
  if (!(*cmd))
  {
    free(cmd);
    return (waitline(in));
  }
  return (cmd);
}

int		main(int ac, char **av, char **env)
{
  t_my_fd	*in;
  char		*cmd;
  t_tree	*tree;
  t_mysh	sh;
  t_exec_opts	opts;

  in = init_main(ac, &sh, av, env);
  while ((cmd = waitline(in)))
    {
      tree = parse_cmd(cmd);
      if (!tree)
	{
	  sh.last_exit = 1;
	  continue;
	}
      my_memset(&opts, 0, sizeof(opts));
      if (tree)
	execute_tree(&sh, tree, &opts);
      free_tree(tree);
      free(cmd);
      if (sh.exit)
	break;
    }
  free_env(sh.env);
  clist_free_data(sh.alias, free_alias);
  sh.alias = NULL;
  free(in);
  return (sh.last_exit);
}
