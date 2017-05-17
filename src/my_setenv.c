/*
** my_setenv.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Tue May 16 11:00:13 2017 Alexandre Chamard-bois
** Last update Wed May 17 14:24:01 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "my_env.h"
#include "mysh.h"

int my_ssetenv(char **tab, t_mysh *sh)
{
  int len;

  if ((len = my_nbline(tab)) > 3)
  {
    my_printf("setenv: Too many arguments.\n");
    return (1);
  }
  if (len == 1)
    return (my_print_env(tab, sh));
  my_setenv(sh->env, tab[1], tab[2]);
  return (0);
}
