/*
** parse_argv.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr 11 15:58:10 2017 Benjamin Viguier
** Last update Thu May 11 12:43:17 2017 Alexandre Chamard-bois
*/

#include "parser.h"

char	*get_block(char *cur, t_strbuilder *sb)
{
  char	base;

  base = *(cur++);
  while (*cur)
    {
      if (*cur == base && cur[1] == base)
	my_sb_write(sb, cur++, 1);
      else if (*cur == base)
	break;
      else
	my_sb_write(sb, cur, 1);
      cur++;
    }
  return (cur);
}

char	**realloc_argv(char **argv, int i)
{
  void	*to_free;

  if (i && i % 8)
    {
      to_free = argv;
      if (!(argv = malloc(sizeof(char*) * (i + 8 + 1))))
	my_perror((void*) __func__);
      my_memset(argv, 0, sizeof(char*) * (i + 8 + 1));
      my_memcpy(argv, to_free, sizeof(char*) * i);
      free(to_free);
    }
  return (argv);
}

char	**init_argv(t_strbuilder **sb)
{
  char	**argv;

  if (!(argv = malloc(sizeof(char*) * (8 + 1))))
    my_perror((void*) __func__);
  my_memset(argv, 0, sizeof(char*) * (8 + 1));
  *sb = my_sb_init();
  if (*sb == NULL)
    my_perror((void*) __func__);
  return (argv);
}

int	parse_cmd_args(t_process *proc, char *cmd)
{
  t_strbuilder	*sb;
  char		**argv;
  int		i;

  argv = init_argv(&sb);
  i = 0;
  while (*cmd)
    {
      if (*cmd == '\'' || *cmd == '"')
	cmd = get_block(cmd, sb);
      else if (*cmd == ' ')
	{
	  while (*cmd == ' ')
	    cmd++;
	  argv[i++] = my_sb_flush(sb);
	  cmd--;
	}
      else
	my_sb_write(sb, cmd, 1);
      argv = realloc_argv(argv, i);
      cmd++;
    }
  argv[i] = my_sb_get_str(sb);
  if (globbing(&argv))
    return (-1);
  proc->name = argv[0];
  proc->args = argv;
  return (0);
}
