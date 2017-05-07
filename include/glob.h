/*
** glob.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:22:41 2017 Alexandre Chamard-bois
** Last update Sun May  7 10:08:48 2017 Alexandre Chamard-bois
*/

#ifndef GLOB_H_
#define GLOB_H_

typedef struct  s_glob
{
  char          *str;
  struct s_glob *next;
}               t_glob;

char **_cut_word(char *cmd);
t_glob *_new_path(t_glob *, char *path);
char **_remplace_cmd(char **cmd, int i, t_glob *add);
void _print_add(t_glob *add);

#endif
