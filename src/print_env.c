/*
** print_env.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Wed May 17 14:05:03 2017 Alexandre Chamard-bois
** Last update Wed May 17 14:07:30 2017 Alexandre Chamard-bois
*/

#include "my_env.h"
#include "mysh.h"

int my_print_env(char **tab, t_mysh *mysh)
{
  t_env *env;

  (void) tab;
  env = mysh->env;
  while (env)
  {
    my_printf("%s=%s\n", GET_KEY(env), GET_VALUE(env));
    env = CLIST_NEXT(mysh->env, env);
  }
  return (0);
}
