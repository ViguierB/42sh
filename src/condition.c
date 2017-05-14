/*
** condition.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May  7 20:26:36 2017 Alexandre Chamard-bois
** Last update Sun May  7 20:43:17 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "script.h"

char *recup_token(char *str, int *err)
{
  static int i = 0;
  char *token;
  int j;

  while (str[i] && str[i] != '[')
    i++;
  j = i;
  while (str[j] && str[j] != ']')
    j++;
  if (str[i] != '[')
  {
    *err = 0;
    i = 0;
    return (NULL);
  }
  if (str[j] != ']' || !(token = my_strndup(str + i, j - i + 1)))
  {
    *err = 1;
    i = 0;
    return (NULL);
  }
  *err = 0;
  i++;
  return (token);
}

t_cond *build_cond(char *str)
{
  t_cond *next;
  t_cond *cond;
  char *token;
  int err;

  next = NULL;
  while ((token = recup_token(str, &err)))
  {
    if (!(cond = malloc(sizeof(t_cond))))
      return (NULL);
    my_memset(cond, 0, sizeof(t_cond));
    my_printf("%s\n", token);
    free(token);
  }
  if (err)
    return (NULL);
  return (cond);
}
