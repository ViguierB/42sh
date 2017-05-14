/*
** pars_egality.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 09:31:19 2017 Alexandre Chamard-bois
** Last update Thu May 11 10:31:27 2017 Alexandre Chamard-bois
*/

#include "script.h"

int pars_level(t_pars_level *level, char c)
{
  if (c == '\"')
    level->d_quote = (level->d_quote == 1 ? 0 : 1);
  else if (c == '\'')
    level->s_quote = (level->s_quote == 1 ? 0 : 1);
  else if (c == '(')
    level->parent++;
  else if (c == ')')
    level->parent--;
  return (0);
}

int find_type_appel(char *str)
{
  t_pars_level level;
  int i;

  my_memset(&level, 0, sizeof(t_pars_level));
  i = 0;
  while (str[i])
  {
    if (LEVEL(str[i]))
     pars_level(&level, str[i]);
    if (str[i] == '?' && !level.parent && !level.d_quote && !level.s_quote)
     return (A_TER);
    if (str[i] == '=' && !level.parent && !level.d_quote && !level.s_quote)
      return (A_ASS);
    if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ||
        str[i] == '%') && !level.parent && !level.d_quote && !level.s_quote)
      return (A_CALC);
    i++;
  }
  if (nb_word(str) == 1 && *str == '$')
    return (A_VAR);
  return (A_ERR);
}

t_value pars_appel(t_mysh *sh, char *str)
{
  t_value value;

  my_memset(&value, 0, sizeof(value));
  return (value);
}
