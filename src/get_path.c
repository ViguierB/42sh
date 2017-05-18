/*
** get_path.c for minishell in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr 11 23:38:29 2017 Benjamin Viguier
** Last update Thu May 18 16:48:31 2017 Guilhem Fulcrand
*/

#include <unistd.h>
#include "mysh.h"
#include "parser.h"
#include "my_env.h"

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

char	        *search_in_all_paths(t_mysh *sh, char *name)
{
  char		    **path;
  char		    *str;
  char          *tmp;
  int		     i;

    if (!(str = malloc(sizeof(char) * 256)))
        return (NULL);
    if (!(tmp = malloc(sizeof(char) * 256)))
        return (NULL);
    my_memset(str, 0, 256);
  i = -1;
  path = get_path_tab(sh->env);
  while (path[++i])
    {
        tmp = my_strconca(path[i], "/");
        tmp = my_strconca(tmp, name);
        if (fexists(tmp))
        {
            str = substr(str, tmp, my_strlen(str), 0);
            str = my_strconca(str, "\n");
        }
        free(tmp);
    }
    free(path[0]);
    free(path);
    return (str);
}

char		*get_real_cmd(t_mysh *sh, t_process *proc)
{
  char		*str;

  if (preparsing(sh, &proc->args) || globbing(&proc->args))
    return (NULL);
  if (!is_builtin(*proc->args))
      {
	proc->builtin = TRUE;
	str = my_strdup(*proc->args);
	return (str);
      }
  proc->builtin = FALSE;
  if (is_local_cmd(*proc->args))
    {
      if (!fexists(*proc->args))
	return (NULL);
      str = my_strdup(*proc->args);
      return (str);
    }
  return (search_in_path(sh, *proc->args));
}
