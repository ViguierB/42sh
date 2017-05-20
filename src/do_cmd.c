/*
** do_cmd.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 20:24:08 2017 Alexandre Chamard-bois
** Last update Sat May 20 15:45:26 2017 Alexandre Chamard-bois
*/

#include "mysh.h"
#include "parser.h"

int do_cmd(t_mysh *sh, char *cmd)
{
  t_tree *tree;
  t_exec_opts opts;

  if (!cmd || !*cmd)
  {
  sh->last_exit = 1;
  return (0);
  }
  tree = parse_cmd(cmd);
  if (!tree)
{
sh->last_exit = 1;
return (0);
}
  my_memset(&opts, 0, sizeof(opts));
  if (tree)
execute_tree(sh, tree, &opts);
  free_tree(tree);
  return (0);
}
