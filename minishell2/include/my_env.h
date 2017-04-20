/*
** my_env.h for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Apr  4 21:23:56 2017 Benjamin Viguier
** Last update Tue Apr 11 18:57:16 2017 Benjamin Viguier
*/

#ifndef MY_ENV_H_
# define MY_ENV_H_

# include "libmy.h"

typedef struct	s_env_elm
{
  char		*key;
  char		*value;
}		t_env_elm;

typedef t_clist	t_env;

char	*my_getenv(t_env *env, char *key);
int	my_setenv(t_env *env, char *key, char *value);
char	**my_env(t_env *env);
int	my_init_env(t_env **env, char **init_env);
void	free_tmp_env(char **env);

#endif /* !MY_ENV_H_ */
