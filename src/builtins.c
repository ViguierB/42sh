/*
** builtins.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May 14 15:10:27 2017 Alexandre Chamard-bois
** Last update Mon May 15 13:00:57 2017 Alexandre Chamard-bois
*/

#include "parser.h"
#include "mysh.h"

const t_builtin g_builtins[] =
{
  {"env", NULL},
  {"setenv", NULL},
  {"unsetenv", NULL},
  {"cd", NULL},
  {"echo", NULL},
  {"[", NULL},
  {"set", NULL},
  {"if", NULL},
  {NULL, NULL},
};

int exec_builtin(t_mysh *mysh, t_process *proc, t_exec_opts *opts)
{
  int i;

  i = 0;
  (void) mysh;
  (void) opts;
  while (g_builtins[i].name && my_strcmp(proc->name, g_builtins[i].name))
    i++;
  if (!g_builtins[i].name)
    return (1);
  return (0);
}
