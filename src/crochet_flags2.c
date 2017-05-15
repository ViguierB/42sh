/*
** crochet_flags1.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 13 10:37:05 2017 Alexandre Chamard-bois
** Last update Sat May 13 12:11:23 2017 Alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libmy.h"
#include "crochet.h"

int _flag_e(char *to_pars[4])
{
  struct stat buff;

  if (stat(to_pars[1], &buff))
    return (REV(1));
  return (REV(0));
}

int _flag_d(char *to_pars[4])
{
  struct stat buff;

  if (stat(to_pars[1], &buff))
    return (REV(1));
  if (S_ISDIR(buff.st_mode))
    return (REV(0));
  return (REV(1));
}

int _flag_f(char *to_pars[4])
{
  struct stat buff;

  if (stat(to_pars[1], &buff))
    return (REV(1));
  if (S_ISREG(buff.st_mode))
    return (REV(0));
  return (REV(1));
}
