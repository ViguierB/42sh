/*
** print_prompt.c for ko in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 20 19:46:08 2017 Alexandre Chamard-bois
** Last update Sat May 20 19:47:39 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include "my_env.h"
#include "mysh.h"

void print_prompt(t_mysh *sh)
{
  char bla[255];
  char *home;

  if (isatty(0))
  {
    home = NULL;
    getcwd(bla, 255);
    if (my_strncmp(my_getenv(sh->env, "HOME"),
                    bla, my_strlen(my_getenv(sh->env, "HOME"))) == 0)
        home = substr(bla, "~", 0, my_strlen(my_getenv(sh->env, "HOME")));
    my_printf("%s$> ", home);
    free(home);
  }
}
