/*
** my_setenv.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Tue May 16 11:00:13 2017 Alexandre Chamard-bois
** Last update Wed May 17 15:30:52 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "my_env.h"
#include "mysh.h"

int	error_setenv(char **tab)
{
  int	i;

  i = 1;
  if (!ALPHA(tab[1][0]))
    {
      my_printf("setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  while (tab[1][i])
    {
      if (!ALPHNUM(tab[1][i]))
	{
	  my_printf("setenv: Variable name must contain alphanumeric "
              "characters.\n");
	  return (1);
	}
      i++;
    }
  return (0);
}

int my_ssetenv(char **tab, t_mysh *sh)
{
  t_env_elm *node;
  int len;

  if ((len = my_nbline(tab)) > 3)
  {
    my_printf("setenv: Too many arguments.\n");
    return (1);
  }
  if (error_setenv(tab))
    return (1);
  if (len == 1)
    return (my_print_env(tab, sh));
  if (my_setenv(sh->env, tab[1], tab[2]))
  {
    if (!(node = malloc(sizeof(t_env_elm))))
      return (1);
    node->key = my_strdup(tab[1]);
    node->value = my_strdup(tab[2]);
    clist_push(sh->env, node);
  }
  return (0);
}
