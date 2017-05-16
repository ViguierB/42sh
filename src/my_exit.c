/*
** my_exit.c for 42sh in /home/arthur/Modules/PSU/TESTS/
**
** Made by Arthur Devreker
** Login   <arthur.devreker@epitech.eu>
**
** Started on  Tue May 16 11:35:13 2017 Arthur Devreker
** Last update Tue May 16 14:42:08 2017 Benjamin Viguier
*/

#include "mysh.h"
#include "libmy.h"

int	my_exit(char **av, t_mysh *sh)
{
  int	ac;
  char	*err_ptr;

  (void)sh;
  ac = my_nbline(av);
  if (ac == 1)
    {
      sh->exit = 1;
      return (0);
    }
  sh->last_exit = strtol(av[1], &err_ptr, 10);
  if (err_ptr == av[1] || (!(NUM(av[1][0])) && av[1][0] != '-'))
    {
      my_printf("exit: Expression Syntax.\n");
      return (1);
    }
  if (*err_ptr)
    {
      my_printf("exit: Badly formed number.\n");
      return (1);
    }
  sh->exit = 1;
  return (sh->last_exit);
}
