/*
** my_cd.c for cd in /home/augustin/Bureau/augustin/projets_groupes/42sh/PSU_2016_42sh/src/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Sun May 14 14:41:18 2017 augustin leconte
** Last update Sun May 21 20:35:01 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libmy.h"
#include "mysh.h"
#include "my_env.h"
#include "parser.h"

char	*modify_pwd(char *to_modify, char *arg)
{
  char	*new_str;
  int	i;
  int	j;

  i = my_strlen(to_modify) + 3 + my_strlen(arg);
  if ((new_str = malloc(sizeof(char) * i)) == NULL)
    return (to_modify);
  j = -1;
  while (++j < my_strlen(to_modify))
    new_str[j] = to_modify[j];
  new_str[j] = '/';
  i = -1;
  while (++i < my_strlen(arg) + 1)
    new_str[++j] = arg[i];
  new_str[j] = '\0';
  return (new_str);
}

t_env	*old_pwd(char *memo, t_env *env)
{
  char	**ptrptr;
  char	*ptr;

  if ((memo = my_strconca("OLDPWD", memo)) == NULL)
    return (env);
  ptr = my_getenv(env, "OLDPWD");
  ptrptr = &ptr;
  *ptrptr = my_strdup(memo);
  return (env);
}

int		error_chdir(char *tab)
{
  struct stat	stats;

  if (stat(tab, &stats))
    dprintf(2, "%s: No such file or directory.\n", tab);
  else if (!S_ISDIR(stats.st_mode))
    dprintf(2, "%s: Not a directory.\n", tab);
  return (1);
}

int end_cd(char cwd[1024], t_mysh *sh)
{
  var_set_env(sh, "OLDPWD", cwd);
  getcwd(cwd, 1024);
  var_set_env(sh, "PWD", cwd);
  return (0);
}

int	my_cd(char **tab, t_mysh *sh)
{
  char	old_cwd[1024];
  char	*new_cwd;

  getcwd(old_cwd, 1024);
  if (!tab[1])
    {
      if (!(new_cwd = my_getenv(sh->env, "HOME")))
	return (1);
    }
  else if ((my_strcmp(tab[1], "-")) == 0)
    {
      if (!(new_cwd = my_getenv(sh->env, "OLDPWD")))
	return (1);
    }
  else if (*tab[1] == '/')
    new_cwd = tab[1];
  else if (my_strcmp(tab[1], "-") != 0)
    new_cwd = modify_pwd(old_cwd, tab[1]);
  if (chdir(new_cwd) == -1)
    return (error_chdir(tab[1]));
  return (end_cd(old_cwd, sh));
}
