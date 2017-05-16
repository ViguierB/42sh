/*
** my_exit.c for 42sh in /home/arthur/Modules/PSU/TESTS/
**
** Made by Arthur Devreker
** Login   <arthur.devreker@epitech.eu>
**
** Started on  Tue May 16 11:35:13 2017 Arthur Devreker
** Last update Tue May 16 14:07:07 2017 Alexandre Chamard-bois
*/

#include "mysh.h"
#include "libmy.h"

int	my_exit(char **av, t_mysh *sh)
{
  int	ac;

  (void)sh;
  ac = my_nbline(av);
  if (ac == 1)
    exit(0);
  if (NUM(av[1][0]) && !my_isnum(av[1]))
  {
    my_printf("exit: Badly formed number.\n");
    return (1);
  }
  if (!my_isnum(av[1]) || ac > 2)
  {
    my_printf("exit: Expression Syntax.\n");
    return (1);
  }
  exit(my_atoi(av[1]));
  return (0);
}
