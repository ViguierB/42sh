/*
** env_ext.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr 11 21:34:15 2017 Benjamin Viguier
** Last update Mon May 15 16:40:57 2017 Alexandre Chamard-bois
*/

#include "mysh.h"
#include "my_env.h"

int		count_env(t_env *env)
{
  t_clist_elm	*elm;
  int		counter;

  elm = env;
  counter = 0;
  while (elm)
    {
      counter++;
      elm = CLIST_NEXT(env, elm);
    }
  return (counter);
}

char		**my_env(t_env *env)
{
  t_strbuilder	*sb;
  t_clist_elm	*elm;
  t_env_elm	*node;
  char		**result;
  char		**cur;

  if (!(cur = malloc(sizeof(char*) * (count_env(env) + 1))))
    my_perror((void*) __func__);
  result = cur;
  sb = my_sb_init();
  elm = env;
  while (elm)
    {
      node = ((t_env_elm*) elm->ptr);
      my_sb_write(sb, node->key, my_strlen(node->key));
      my_sb_write(sb, "=", 1);
      my_sb_write(sb, node->value, my_strlen(node->value));
      *(cur++) = my_sb_flush(sb);
      elm = CLIST_NEXT(env, elm);
    }
  *cur = NULL;
  return (result);
}

int		my_unsetenv(char **tab, t_mysh *sh)
{
  t_env	*elm;
  int i;

  elm = sh->env;
  i = 0;
  if (!tab[1])
    {
      sh->last_exit = 1;
      return (1);
    }
  while (tab[++i] && (elm = sh->env))
    while (elm)
    {
      if (!my_strcmp(((t_env_elm*)elm->ptr)->key, tab[i]))
      {
        elm->next->prev = elm->prev;
        elm->prev->next = elm->next;
        elm = sh->env;
        break;
      }
      elm = CLIST_NEXT(sh->env, elm);
    }
  sh->last_exit = 0;
  return (0);
}
