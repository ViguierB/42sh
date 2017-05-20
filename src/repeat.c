/*
** repeat.c for 42sh in /home/arthur/Modules/PSU/PSU_2016_42sh/src/
**
** Made by Arthur Devreker
** Login   <arthur.devreker@epitech.eu>
**
** Started on  Wed May 17 15:37:55 2017 Arthur Devreker
** Last update Sat May 20 10:39:32 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "my_env.h"
#include "parser.h"
#include <stdio.h>

char	*fill_str(int len_tot, int ac, char **av, int *len)
{
  int	i;
  int	j;
  int	k;
  char	*str;

  j = 0;
  k = 0;
  if (!(str = malloc(sizeof(char) * len_tot)))
    return (NULL);
  while (j < ac)
    {
      i = 0;
      while (i < len[j])
	{
	  str[k] = av[j + 2][i];
	  k++;
	  i++;
	}
      j++;
      if (j < ac)
	str[k] = ' ';
      k++;
    }
  str[k - 1] = '\0';
  return (str);
}

char	*my_wordtab_to_str(char **av)
{
  int	i;
  int	ac;
  int	*len;
  int	len_tot;
  char	*str;

  i = -1;
  ac = my_nbline(av) - 2;
  if ((len = malloc(sizeof(int) * ac)) == NULL)
    return (NULL);
  len_tot = 0;
  while (++i < ac)
    {
      len[i] = my_strlen(av[i + 2]);
      len_tot += len[i];
    }
  i--;
  str = fill_str(len_tot + i, ac, av, len);
  free(len);
  return (str);
}

int	error_repeat(char **av)
{
  int	ac;
  int	i;

  i = 0;
  if ((ac = my_nbline(av)) < 3)
    {
      my_printf("repeat: Too few arguments.\n");
      return (1);
    }
  while (av[1][i])
    {
      if (!NUM(av[1][i]) && av[1][i] != '-' && av[1][i] != '+')
	{
	  my_printf("repeat: Badly formed number.\n");
	  return (1);
	}
      i++;
    }
  return (ac);
}

int		my_repeat(char **av, t_mysh *sh)
{
  int		ac;
  int		nb;
  int		ret;
  char		*cmd;
  t_exec_opts	opts;
  t_tree	*tree;

  ret = 0;
  my_memset(&opts, 0, sizeof(t_exec_opts));
  if ((ac = error_repeat(av)) == 1)
    return (1);
  nb = my_atoi(av[1]);
  cmd = my_wordtab_to_str(av);
  while (nb > 0)
    {
      tree = parse_cmd(cmd);
      ret = execute_tree(sh, tree, &opts);
      free_tree(tree);
      nb--;
    }
  free(cmd);
  return (ret);
}
