/*
** builtins.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May 14 15:10:27 2017 Alexandre Chamard-bois
** Last update Tue May 16 09:59:57 2017 Alexandre Chamard-bois
*/

#include "parser.h"
#include "mysh.h"

const t_builtin g_builtins[] =
{
  {"env", NULL},
  {"setenv", NULL},
  {"unsetenv", NULL},
  {"cd", NULL},
  {"exit", NULL},
  {"echo", my_echo},
  {"[", builtin_crochet},
  {"set", NULL},
  {"if", NULL},
  {NULL, NULL},
};

int is_builtin(char *name)
{
  int i;

  i = 0;
  while (g_builtins[i].name && my_strcmp(name, g_builtins[i].name))
    i++;
  if (!g_builtins[i].name)
    return (1);
  return (0);
}

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
  mysh->last_exit = g_builtins[i].func(proc->args, mysh);
  return (0);
}
