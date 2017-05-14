/*
** nb_word.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 10:10:14 2017 Alexandre Chamard-bois
** Last update Thu May 11 10:10:23 2017 Alexandre Chamard-bois
*/

#include "macro.h"

int	nb_word(const char *str)
{
	int in_word;
  int nb_word;

  nb_word = 0;
  if (BLANK(*str))
    in_word = 0;
  else
  {
    in_word = 1;
    nb_word = 1;
  }
  while (*str)
  {
    if (!BLANK(*str) && in_word == 0)
      nb_word++;
    if (BLANK(*str))
      in_word = 0;
    else
      in_word = 1;
    str++;
  }
  return (nb_word);
}
