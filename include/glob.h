/*
** glob.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:22:41 2017 Alexandre Chamard-bois
** Last update Sun May 21 20:12:09 2017 alexandre Chamard-bois
*/

#include <mysh.h>
#ifndef GLOB_H_
# define GLOB_H_

# define FIRST(cut) (**cut == '/' ? "/" : ".")

typedef struct  s_glob
{
  char          *str;
  struct s_glob *next;
}               t_glob;

char	**_cut_word(char *cmd);
t_clist *_new_path(t_clist *, char *path);
char	**_remplace_cmd(char **cmd, int i, t_clist *add, char *cut);

#endif
