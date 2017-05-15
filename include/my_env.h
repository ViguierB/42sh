/*
** my_env.h for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr  4 21:23:56 2017 Benjamin Viguier
** Last update Sun May 14 17:55:51 2017 Arthur Devreker
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
void	free_env(t_env *env);
t_mysh	my_unsetenv(char **tab, t_mysh sh);

#endif /* !MY_ENV_H_ */
