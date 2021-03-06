/*
** env.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr  4 21:45:00 2017 Benjamin Viguier
** Last update Sun May 21 20:21:29 2017 alexandre Chamard-bois
*/

#include "mysh.h"
#include "my_env.h"

int		my_init_env(t_env **env, char **init_env)
{
  int		sep_pos;
  t_env_elm	*node;

  *env = NULL;
  while (*init_env)
    {
      if (!(node = malloc(sizeof(t_env_elm))))
	my_perror((void*) __func__);
      sep_pos = 0;
      while ((*init_env)[sep_pos] && (*init_env)[sep_pos] != '=')
	sep_pos++;
      node->key = my_strndup(*init_env, sep_pos);
      node->value = my_strdup(*init_env + sep_pos + 1);
      *env = clist_push(*env, node);
      init_env++;
    }
  return (0);
}

char		*my_getenv(t_env *env, char *key)
{
  t_clist_elm	*elm;

  elm = env;
  while (elm)
    {
      if (!(my_strcmp(GET_KEY(elm), key)))
	return (GET_VALUE(elm));
      elm = CLIST_NEXT(env, elm);
    }
  return (NULL);
}

int		my_setenv(t_env *env, char *key, char *value)
{
  t_clist_elm	*elm;
  t_env_elm	*cur;

  elm = env;
  while (elm)
    {
      cur = elm->ptr;
      if (!(my_strcmp(cur->key, key)))
	{
	  if (cur->value)
	    free(cur->value);
	  if (value)
	    cur->value = my_strdup(value);
	  else
	    cur->value = NULL;
	  return (0);
	}
      elm = CLIST_NEXT(env, elm);
    }
  return (1);
}

void free_env(t_env *env)
{
  t_env *next;

  if (env)
    env->prev->next = NULL;
  while (env)
    {
      next = env->next;
      free(GET_KEY(env));
      free(GET_VALUE(env));
      free(env->ptr);
      free(env);
      env = next;
    }
}

void	free_tmp_env(char **env)
{
  char	**cur;

  if (env)
    {
      cur = env;
      while (*cur)
	{
	  free(*cur);
	  cur++;
	}
      free(env);
    }
}
