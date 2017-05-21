/*
** main.c for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Apr  3 15:09:58 2017 Benjamin Viguier
** Last update Sun May 21 20:33:40 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include "mysh.h"
#include "my_env.h"
#include "parser.h"
#include "42shrc.h"

void init_main(int ac, t_mysh *sh, char **av, char **env)
{
  my_memset(sh, 0, sizeof(*sh));
  my_init_env(&sh->env, env);
  sh->hist = NULL;
  sh->alias = my_source(NULL);
  my_name(LIBMY_INIT, av[0]);
  var_last_ret(sh);
  if (ac == 1)
    sh->in = my_fd_from_fd(0);
  else
    main_script(ac, av, sh);
}

char	*waitline(t_mysh *sh, t_my_fd *in)
{
  char	*cmd;

  print_prompt(sh);
  cmd = my_getline(in);
  if (!cmd)
    return (NULL);
  cmd = my_ftrim(cmd);
  if (!(cmd = true_preparsing(sh, cmd)) || !*cmd)
    {
      free(cmd);
      return (waitline(sh, in));
    }
  return (cmd);
}

int end_main(t_mysh *sh, t_my_fd *in)
{
  free_env(sh->env);
  clist_free_data(sh->hist, free);
  clist_free_data(sh->alias, free_alias);
  free(in);
  return (sh->last_exit);
}

int		main(int ac, char **av, char **env)
{
  char		*cmd;
  t_tree	*tree;
  t_mysh	sh;
  t_exec_opts	opts;

  init_main(ac, &sh, av, env);
  while ((cmd = waitline(&sh, sh.in)))
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
      sh.hist = clist_push(sh.hist, cmd);
      if (sh.exit)
	break;
    }
  return (end_main(&sh, sh.in));
}
