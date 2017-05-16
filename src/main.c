/*
** main.c for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Apr  3 15:09:58 2017 Benjamin Viguier
** Last update Tue May 16 10:16:31 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include "mysh.h"
#include "my_env.h"
#include "parser.h"

t_my_fd *init_main(int ac, t_mysh *sh, char **av, char **env)
{
  (void) ac;
  my_memset(sh, 0, sizeof(sh));
  my_init_env(&sh->env, env);
  my_name(LIBMY_INIT, av[0]);
  return (my_fd_from_fd(0));
}

char *waitline(t_my_fd *in)
{
  char *cmd;

  if (isatty(0))
    my_printf("$> ");
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
  char buff[255];
  t_my_fd	*in;
  char		*cmd;
  t_tree	*tree;
  t_mysh	sh;
  t_exec_opts	opts;

  in = init_main(ac, &sh, av, env);
  while ((cmd = waitline(in)))
    {
      getcwd(buff, 255);
      my_printf("%s\n", buff);
      tree = parse_cmd(cmd);
      my_memset(&opts, 0, sizeof(opts));
      if (tree)
	execute_tree(&sh, tree, &opts);
      free_tree(tree);
      free(cmd);
    }
    free_env(sh.env);
    free(in);
    return (sh.last_exit);
}
