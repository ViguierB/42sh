/*
** main.c for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Apr  3 15:09:58 2017 Benjamin Viguier
** Last update Sat May  6 14:41:53 2017 Alexandre Chamard-bois
*/

#include "mysh.h"
#include "my_env.h"
#include "parser.h"

int		main(int ac, char **av, char **env)
{
  t_my_fd	*in;
  char		*cmd;
  t_tree	*tree;
  t_mysh	sh;
  t_exec_opts	opts;

  (void) ac;
  my_memset(&sh, 0, sizeof(sh));
  my_init_env(&(sh.env), env);
  my_name(LIBMY_INIT, av[0]);
  in = my_fd_from_fd(0);
  while (1)
    {
      my_printf("$> ");
      cmd = my_getline(in);
      if (!cmd)
	return (sh.last_exit);
      if (!(*cmd))
	continue;
      tree = parse_cmd(cmd);
      my_memset(&opts, 0, sizeof(opts));
      if (tree)
	execute_tree(&sh, tree, &opts);
      free_tree(tree);
    }
}
