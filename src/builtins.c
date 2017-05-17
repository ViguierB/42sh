/*
** builtins.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May 14 15:10:27 2017 Alexandre Chamard-bois
** Last update Wed May 17 20:07:01 2017 Guilhem Fulcrand
*/

#include <unistd.h>
#include "parser.h"
#include "mysh.h"

const t_builtin g_builtins[] =
{
  {"env", my_print_env},
  {"setenv", my_ssetenv},
  {"unsetenv", my_unsetenv},
  {"cd", my_cd},
  {"exit", my_exit},
  {"echo", my_echo},
  {"[", builtin_crochet},
  {"set", my_set},
  {"which", my_which},
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
  if (g_builtins[i].func)
    mysh->last_exit = g_builtins[i].func(proc->args, mysh);
  else
    mysh->last_exit = 1;
  if (!isatty(0) && mysh->last_exit)
    mysh->exit = 1;
  return (0);
}
