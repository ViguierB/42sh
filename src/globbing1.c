/*
** globing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 15:21:25 2017 Alexandre Chamard-bois
** Last update Sun May 21 20:25:31 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "libmy.h"
#include "glob.h"

static int	_count_folder(char *cmd)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (cmd[i])
    {
      if (cmd[i] == '/')
	nb++;
      i++;
    }
  return (nb + 1);
}

char	**_cut_word(char *cmd)
{
  char	**tab;
  int	nb_folder;
  int	i;
  int	start;
  int	end;

  nb_folder = _count_folder(cmd);
  if (!(tab = malloc(sizeof(char *) * (nb_folder + 1))))
    return (NULL);
  i = 0;
  start = 0;
  while (cmd[start] && i < nb_folder)
    {
      end = start + 1;
      while (cmd[end] && cmd[end] != '/')
	end++;
      if (!(tab[i] = my_strndup(cmd + start, end - start)))
	return (NULL);
      start = end;
      while (cmd[start] == '/')
	start++;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

static char	*path_conca(char *path, char *name)
{
  char		*tmp;

  if (*name == '.' && path[my_strlen(path) - 1] == '.')
    return (my_strdup(name));
  if (path[my_strlen(path) - 1] != '/')
    {
      tmp = my_strconca(path, "/");
      path = my_strconca(tmp, name);
      free(tmp);
    }
  else
    path = my_strconca(path, name);
  return (path);
}

t_clist		*_find_path(char **cutted_word, int i, char *path, t_clist *add)
{
  struct dirent *info;
  DIR		*dirent;

  while (!my_strcmp(cutted_word[i], "/"))
    i++;
  if (!cutted_word[i])
    return (clist_push(add, path));
  if (!(dirent = opendir(path)))
    return (add);
  while ((info = readdir(dirent)))
    {
      if ((*info->d_name != '.' ||
	   *(cutted_word[i] + (*cutted_word[i] == '/')) == '.'))
	{
	  if (match(info->d_name, cutted_word[i] + (*cutted_word[i] == '/')))
	    add = _find_path(cutted_word, i + 1, path_conca(path, info->d_name)
			     , add);
	}
    }
  free(path);
  closedir(dirent);
  return (add);
}

int		globbing(char ***cmd)
{
  int		i;
  int		j;
  t_clist	*add;
  char		**cutted_word;

  add = NULL;
  if (!*cmd)
    return (1);
  i = 0;
  j = -1;
  while ((*cmd)[i] && ((*cmd)[i][++j] || (j = 0) || (*cmd)[++i]))
    {
      if (GLOBING((*cmd)[i][j]))
	{
	  if (!(cutted_word = _cut_word((*cmd)[i])))
	    return (1);
	  add = _find_path(cutted_word, 0, my_strdup(FIRST(cutted_word)), add);
	  if (add)
	    *cmd = _remplace_cmd(*cmd, i, add, *cutted_word);
	  add = NULL;
	  free_tab(cutted_word);
	  j = 0;
	}
    }
  return (0);
}
