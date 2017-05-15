/*
** get_path.c for minishell in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr 11 23:38:29 2017 Benjamin Viguier
** Last update Mon May 15 14:50:53 2017 Alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"
#include "parser.h"
#include "my_env.h"

const t_builtin	g_builtin_tab[] =
  {
    {"cd", NULL},
    {"setenv", NULL},
    {"unsetenv", NULL},
    {"exit", NULL},
    {NULL, NULL}
  };

char		**get_path_tab(t_env *env)
{
  t_clist_elm	*elm;
  t_env_elm	*cur;
  char		**simple;

  elm = env;
  while (elm)
    {
      cur = elm->ptr;
      if (my_strcmp(cur->key, "PATH") == 0)
	{
	  return (my_split(cur->value, ':', NULL));
	}
      elm = CLIST_NEXT(env, elm);
    }
  if (!(simple = malloc(sizeof(char *))))
    my_perror((void*) __func__);
  *simple = NULL;
  return (simple);
}

char	*search_in_path(t_mysh *sh, char *name)
{
  char		**path;
  char		*str;
  int		i;
  t_strbuilder	*sb;

  i = 0;
  path = get_path_tab(sh->env);
  sb = my_sb_init();
  while (path[i])
    {
      my_sb_write(sb, path[i], my_strlen(path[i]));
      if (path[i][my_strlen(path[i]) - 1] != '/')
	my_sb_write(sb, "/", 1);
      my_sb_write(sb, name, my_strlen(name));
      str = my_sb_flush(sb);
      if (str)
	{
	  if (fexists(str))
	    return (my_sb_destroy(sb), str);
	  free(str);
	}
      i++;
    }
  my_sb_destroy(sb);
  return (NULL);
}

char		*get_real_cmd(char *name, t_mysh *sh, t_process *proc)
{
  t_builtin	*cur;
  char		*str;

  cur = (void*) g_builtin_tab;
  while (cur->name)
    if (!my_strcmp((cur++)->name, name))
      {
	proc->builtin = TRUE;
	str = my_strdup(name);
	return (str);
      }
  proc->builtin = FALSE;
  if (is_local_cmd(name))
    {
      if (!fexists(name))
	return (NULL);
      str = my_strdup(name);
      free(name);
      return (str);
    }
  return (search_in_path(sh, name));
}
