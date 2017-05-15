/*
** my_cd.c for cd in /home/augustin/Bureau/augustin/projets_groupes/42sh/PSU_2016_42sh/src/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Sun May 14 14:41:18 2017 augustin leconte
** Last update Sun May 14 15:00:09 2017 augustin leconte
*/

#include "mysh.h"
#include "parser.h"

t_clist old_pwd(char *memo, t_clist env)
{
  char ***ptrptr;
  char *ptr;

  if ((memo = my_strconcat("OLDPWD=", memo)) == NULL)
    return (env);
  ptr = my_getenv("OLDPWD=");
  ptrptr = &ptr;
  *ptrptr = my_strdup(memo);
  return (env);
}

void error_chdir(char *memo, char *cwd, char *tab, t_mysh *sh)
{
  struct stat buf;

  sh->last_exit = -1;
  if (access(cwd, F_OK) != 0)
  {
    my_printf("%d: No such file or directory\n", tab);
    return;
  }
  my_printf("%s: Not a directory.\n", tab);
  cwd = my_strdup(memo);
}

static t_mysh my_ret(t_mysh sh)
{
  sh.last_exit = -1;
  return (sh);
}

t_mysh end_cd(char *cwd, char *ptr, char **ptrptr, t_mysh sh)
{
  cwd = getcwd(cwd, 1024);
  cwd = my_strconcat("PWD=", cwd);
  ptr = my_getenv("PWD=");
  ptrptr = &ptr;
  *ptrptr = my_strdup(cwd);
  sh.last_exit;
  return (sh);
}

t_mysh my_cd(char **tab, t_mysh sh)
{
  char **ptrptr;
  char *cwd;
  char *memo;
  char *ptr;

  if ((cwd = malloc(sizeof(char) * 1024)) == NULL)
    return (my_ret(sh));
  cwd = getcwd(cwd, 1024);
  memo = my_strdup(cwd);
  if (tab[1] == NULL)
    if ((cwd = my_getenv(sh.env, "HOME=/")) == NULL)
    return (my_ret(sh));
  else if (tab[1] != NULL)
    cwd = modify_pwd(cwd, tab[1]);
  else if ((str_cmp(tab[1], "-")) == 0)
    if ((cwd = my_getenv(sh.env, "OLDPWD=/")) == NULL)
      return (my_ret(sh));
  else if (tab[1][0] = '/')
    cwd = tab[1];
  if (chdir(cwd) == -1)
    error_chdir(memo, cwd, tab[1], &sh);
  if ((sh.env = old_pwd(memo, sh.env)) == NULL)
    return (my_ret(sh));
  return (end_cd(cwd, ptr, ptrptr, sh));
}
