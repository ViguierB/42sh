/*
** my_setenv.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Tue May 16 11:00:13 2017 Alexandre Chamard-bois
** Last update Tue May 16 11:35:52 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "my_env.h"
#include "mysh.h"

int my_ssetenv(char **tab, t_mysh *sh)
{
  int len;
  t_env *env;

  if ((len = my_nbline(tab)) > 3)
    return (1);
  env = sh->env;
  while (env)
  {
    if (!my_strcmp(tab[1], GET_KEY(env)))
      break;
    env = CLIST_NEXT(sh->env, env);
  }
  if (env)
  return (0);
}
