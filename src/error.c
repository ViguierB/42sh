/*
** error.c for minishell.c in /home/benji_epitech/System_Unix/PSU_2016_minishell2
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Apr  4 11:37:45 2017 Benjamin Viguier
** Last update Thu Apr  6 14:29:11 2017 Benjamin Viguier
*/

#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include "libmy.h"

int	my_vfprintf(int fd, char *format, va_list ap);

char		*my_name(int to_do, ...)
{
  static char	*name;
  va_list	va;

  if (to_do == LIBMY_INIT)
    {
      va_start(va, to_do);
      name = va_arg(va, char*);
      va_end(va);
      return (name);
    }
  else if (to_do == LIBMY_GET)
    return (name);
  return (NULL);
}

int	my_perror(char *str)
{
  my_fprintf(S_ERR, "%9s %s: %s: %s\n", "[ERROR]", my_name(LIBMY_GET),
	     str, strerror(errno));
  exit(84);
  return (0);
}

int	my_warning(char *str, char *to_print)
{
  my_fprintf(S_ERR, "%9s %s: %s: %s\n", "[WARNING]", my_name(LIBMY_GET),
	     str, to_print);
  return (-1);
}

int	my_pwarning(char *str)
{
  my_fprintf(S_ERR, "%9s %s: %s: %s\n", "[WARNING]", my_name(LIBMY_GET),
	     str, strerror(errno));
  return (-1);
}

int	my_pcustomwarning(char *str, ...)
{
  va_list	va;

  my_fprintf(S_ERR, "%9s %s: ", "[WARNING]", my_name(LIBMY_GET));
  va_start(va, str);
  my_vfprintf(S_ERR, str, va);
  va_end(va);
  return (-1);
}
