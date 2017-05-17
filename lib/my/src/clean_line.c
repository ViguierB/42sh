/*
** clean_line.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:42:56 2017 Alexandre Chamard-bois
** Last update Wed May 17 14:49:35 2017 Alexandre Chamard-bois
*/

#include "libmy.h"

char *clean_line(char *str)
{
  int i;

  i = 0;
  if (!str)
    return (NULL);
  while (SPACE(str[i]))
    i++;
  if (i)
    my_strcpy(str, str + i);
  i = my_strlen(str) - 1;
  while (i >= 0 && SPACE(str[i]))
  {
    str[i] = 0;
    i--;
  }
  return (str);
}
