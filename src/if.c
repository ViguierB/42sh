/*
** if.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May  7 20:17:55 2017 Alexandre Chamard-bois
** Last update Sun May  7 20:34:47 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "script.h"

t_mysh built_if(char **tab, t_mysh sh)
{
  t_cond *cond;

  if (!(cond = build_cond(tab[0])))
    return (my_putstr("error condition\n"), (t_mysh){sh.env, 0});
  return ((t_mysh){sh.env, 0});
}

int main(int ac, char **av)
{
  (void) ac;
  built_if(av + 1, (t_mysh){NULL, 0});
  return (0);
}
