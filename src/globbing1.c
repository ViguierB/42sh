/*
** globing.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 15:21:25 2017 Alexandre Chamard-bois
** Last update Sat May  6 23:43:39 2017 Alexandre Chamard-bois
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "libmy.h"
#include "glob.h"

t_glob *_find_path(char **cutted_word, int i, char *path, t_glob *add)
{
  struct dirent *info;
  DIR *dirent;

  if (!cutted_word[i])
    return (_new_path(add, path));
  if (!(dirent = opendir((path ? path : "."))))
    return (add);
  while ((info = readdir(dirent)))
  {
    if ((*info->d_name != '.' || *cutted_word[i] == '.'))
    {
      if (match(info->d_name, cutted_word[i] + (*cutted_word[i] == '/')))
        add = _find_path(cutted_word, i + 1,
              str_conca(3, path, (path ? "/" : ""), info->d_name), add);
    }
  }
  closedir(dirent);
  return (add);
}

int globbing(char ***cmd)
{
  int   i;
  int   j;
  t_glob *add;
  char **cutted_word;

  add = NULL;
  if (!*cmd)
    return (1);
  i = -1;
  while ((*cmd)[++i])
  {
    j = -1;
    while ((*cmd)[i][++j])
    {
      if (GLOBING((*cmd)[i][j]))
      {
        if (!(cutted_word = _cut_word((*cmd)[i])))
          return (1);
        if (!(add = _find_path(cutted_word, 0, NULL, add)))
         return (1);
      }
    }
  }
  _print_add(add);
  return (0);
}

// int main(int ac, char **av)
// {
//   char **tab;
//
//   tab = malloc(sizeof(char*) * ac);
//   for (int i = 1; i < ac; i++)
//     tab[i - 1] = my_strdup(av[i]);
//   tab[ac - 1] = NULL;
//   globbing(&tab);
//   return (0);
// }
