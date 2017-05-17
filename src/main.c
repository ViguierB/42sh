/*
** main.c for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Apr  3 15:09:58 2017 Benjamin Viguier
** Last update Wed May 17 19:04:53 2017 Guilhem Fulcrand
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
  var_last_ret(sh);
  return (my_fd_from_fd(0));
}

char *waitline(t_mysh *sh, t_my_fd *in)
{
  char *home;
  char *cmd;

  if (!(home = malloc(sizeof(char) * 256)))
    return (NULL);
  if (isatty(0))
  {
    getcwd(home, 255);
    if (my_strncmp(my_getenv(sh->env, "HOME"),
                    home, my_strlen(my_getenv(sh->env, "HOME"))) == 0)
        home = substr(home, "~", 0, my_strlen(my_getenv(sh->env, "HOME")));
    my_printf("%s$> ", home);
    free(home);
  }
  if (!(cmd = my_getline(in)))
    return (NULL);
  cmd = my_ftrim(cmd);
  if (!(*cmd))
  {
    free(cmd);
    return (waitline(sh, in));
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
  while ((cmd = waitline(&sh, in)))
    {
        cmd = true_preparsing(&sh, cmd);
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
  free(in);
  return (sh.last_exit);
}
