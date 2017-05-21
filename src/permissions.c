/*
** permissions.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Wed May 17 18:36:50 2017 Guilhem Fulcrand
** Last update Sun May 21 21:06:42 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include "libmy.h"

int     is_permited(char *path)
{
  if (access(path, F_OK) == 0)
    {
      if (access(path, X_OK) == 0)
	return (0);
      return (1);
    }
  return (-1);
}
