/*
** glob.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 22:22:41 2017 Alexandre Chamard-bois
** Last update Thu May 11 12:39:55 2017 Alexandre Chamard-bois
*/

#ifndef GLOB_H_
#define GLOB_H_

#define FIRST(cut) (**cut == '/' ? "/" : ".")

typedef struct  s_glob
{
  char          *str;
  struct s_glob *next;
}               t_glob;

char **_cut_word(char *cmd);
t_glob *_new_path(t_glob *, char *path);
char **_remplace_cmd(char **cmd, int i, t_glob *add, char *cut);

#endif
